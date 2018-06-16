// Fill out your copyright notice in the Description page of Project Settings.

#include "Parser.h"
#include <vector>
#include <string>         // std::string

Parser::Parser()
{
}

Parser::~Parser()
{
}

/*
PRETTY CERTAIN THIS IS DEPRECATED
TArray<FPlayerOptionType> Parser::OptionsParser(TArray<FPlayerOptionType> Array, std::string strhaystack)
{
	//std::cout << "Haystack sentence is: " << strhaystack << "\n";
	//std::cout << "Needle phrase is: " << strneedlestart << " and end is " << strneedleend << "and Div is " << strneedlediv << " \n";
	TArray<FPlayerOptionType> OptionMap;

	std::size_t found = 0;
	int i = 0;

	while (found != std::string::npos) {
		found = strhaystack.find(strneedlestart, found + 1);
		if (found != std::string::npos) {
			//std::cout << "Entry " << i << " start   '" << strneedlestart << "' at: " << found << '\n';
			std::size_t start = found;
			found = strhaystack.find(strneedlediv, found + 1);
			//std::cout << "Entry " << i << " divider '" << strneedlediv << "' at: " << found << '\n';
			std::size_t div = found;
			found = strhaystack.find(strneedleend, found + 1);
			//std::cout << "Entry " << i << " end     '" << strneedleend << "' at: " << found << '\n';
			std::size_t end = found;
			std::string option = strhaystack.substr(start + 2, div - start - 2);
			std::string node = strhaystack.substr(div + 1, end - div - 1);
			//std::cout << "Node " << i << " is       " << node << '\n';
			std::pair <std::string, std::string> pairstrings(option, node);
			
			OptionMap.Add(std::pair<int, std::pair<std::string, std::string>>(i, pairstrings));
			//std::cout << "Option Segment: '" << option << "'\n";
		}

		i++;
	}

	return OptionMap;
}
*/

FString Parser::DialogueParser(std::string strhaystack)
{

	std::size_t DialogueEnd = strhaystack.find(strneedlestart, 0);
	std::string DialogueString = strhaystack.substr(0, DialogueEnd);
	FString DialogueFString =  DialogueString.c_str();
	return DialogueFString;
}


// TODO Try and do the below with all char (as given by c_str()) instead of std::string
// The below basically just uses std::string for the find() and substr() functions. 
// Can this be done with char instead? XML returns char anyway and FStrings are chars. Just converting in and out of std::strings for this bit.

TArray<FPlayerOptionType> Parser::ParseOptions(std::string strhaystack)
{
	TArray<FPlayerOptionType> OptionsArray;
	FPlayerOptionType WorkingOption;

	std::string OptionString;
	std::string OptionCodeString;
	std::string NodeString;
	
	std::size_t found = 0;
	std::size_t codefound = 0;
	int i = 0;

	while (found != std::string::npos) {
		found = strhaystack.find(strneedlestart, found + 1);
		if (found != std::string::npos) {
			std::size_t start = found;
			found = strhaystack.find(strneedlediv, found + 1);
			std::size_t div = found;
			found = strhaystack.find(strneedleend, found + 1);
			std::size_t end = found;

			std::string OptionPlain = strhaystack.substr(start + 2, div - start - 2);
			codefound = OptionPlain.find(codeneedlestart, codefound);
			if (codefound != std::string::npos) {
				std::size_t codestart = codefound;
				codefound = OptionPlain.find(codeneedleend, codefound + 1);
				std::size_t codeend = codefound;
				OptionCodeString = OptionPlain.substr(codestart + 1, codeend - 1);
				WorkingOption.optioncode = OptionCodeString.c_str();
				OptionString = OptionPlain.substr(codeend + 1, std::string::npos);
				WorkingOption.option = OptionString.c_str();
			}
			else {
				WorkingOption.option = OptionPlain.c_str();
			}
			codefound = 0;
			WorkingOption.index = i;
			NodeString = strhaystack.substr(div + 1, end - div - 1);
			WorkingOption.node = NodeString.c_str();
			OptionsArray.Add(WorkingOption);


			//FOR REFERENCE:
			/*
		FPlayerOptionType PlaceholderPlayerOptionType2;
		PlaceholderPlayerOptionType2.index = PlaceholderIndex;
		PlaceholderPlayerOptionType2.option = PlaceholderOption;
		PlaceholderPlayerOptionType2.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType2.node = PlaceholderNode;

		WorkingArray.Add(PlaceholderPlayerOptionType2);
			*/

		}

		i++;
	}

	return OptionsArray;
}

ECodeType Parser::CodeTypeParser(std::string CodeString)
{
	std::size_t found = 0;
	found = CodeString.find(" ", found);
	std::string Type = CodeString.substr(0, found);
	if (Type == setindicator) {
		return ECodeType::Set_Value;
	}
	else if (Type == condindicator) {
		std::size_t greaterthanpos = CodeString.find(greaterthan, 0);
		std::size_t lessthanpos = CodeString.find(lessthan, 0);
		std::size_t equaltopos = CodeString.find(equalto, 0);
		if (greaterthanpos != std::string::npos) {
			return ECodeType::Greater_Than;
		}
		else if (lessthanpos != std::string::npos) {
			return ECodeType::Less_Than;
		}
		else if (equaltopos != std::string::npos) {
			return ECodeType::Equal_To;
		}
		else {
			return ECodeType::Bool_Check;
		}
	}
	else {
		return ECodeType::No_Code;
	}
}
