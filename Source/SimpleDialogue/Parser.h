// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>         // std::string
#include <map>  
#include <vector>
#include "DialogueGetter.h"
#include "CoreMinimal.h"

enum class ECodeType
{
	No_Code,
	Set_Value,
	Bool_Check,
	Greater_Than,
	Less_Than,
	Equal_To
};

struct playeroptiontype {
	int index;
	std::string option;
	std::string optioncode;
	std::string node;
};

/**
 * 
 */
class SIMPLEDIALOGUE_API Parser
{
public:
	Parser();
	~Parser();
	// PRETTY CERTAIN THE BELOW IS DEPRECATED
	//TArray<FPlayerOptionType> OptionsParser(TArray<FPlayerOptionType>,std::string);
	TArray<FPlayerOptionType> ParseOptions(std::string);
	FString DialogueParser(std::string);
	ECodeType CodeTypeParser(std::string); // TODO To reference specific UE4 objects from written code, will have to implement LoadObject/LoadClass-friendly strings

private:
	std::string strneedlestart = "[[";
	std::string strneedlediv = "|";
	std::string strneedleend = "]]";
	std::string codeneedlestart = "(";
	std::string codeneedleend = ")";
	std::string setindicator = "set";
	std::string condindicator = "if";
	std::string greaterthan = "greaterthan";
	std::string lessthan = "lessthan";
	std::string equalto = "equalto";
};
