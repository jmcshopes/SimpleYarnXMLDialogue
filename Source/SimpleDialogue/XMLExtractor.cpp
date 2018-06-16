// Fill out your copyright notice in the Description page of Project Settings.

#include "XMLExtractor.h"
#include <iostream>

XMLExtractor::XMLExtractor()
{
}

XMLExtractor::~XMLExtractor()
{
}

std::string XMLExtractor::ReadBody(tinyxml2::XMLDocument* xmlDocRecvd, std::string node)
{
	// TODO make this an argument:

	tinyxml2::XMLNode * pRoot = xmlDocRecvd->FirstChild();
	if (pRoot == nullptr) return "file read error";

	tinyxml2::XMLNode * NodeRoot = pRoot->FirstChildElement();

	tinyxml2::XMLElement * TitleNode = NodeRoot->FirstChildElement("title");

	const char* TitleChars = TitleNode->GetText();
	std::string TitleString(TitleChars);
	//std::cout << "The first node's title element is: " << TitleString << "\n";

	tinyxml2::XMLElement * BodyNode = NodeRoot->FirstChildElement("body");

	const char* BodyChars = BodyNode->GetText();
	std::string BodyString(BodyChars);
	//std::cout << "The first node's body element is: \n" << BodyString << "\n\n The characters are: \n";
	// printf(BodyChars);




	while (TitleString != node) {

		NodeRoot = NodeRoot->NextSibling();

		TitleNode = NodeRoot->FirstChildElement("title");

		TitleChars = TitleNode->GetText();
		TitleString = (TitleChars);
		//std::cout << "The next node's title element is: " << TitleString << "\n\n";

		BodyNode = NodeRoot->FirstChildElement("body");

		BodyChars = BodyNode->GetText();
		BodyString = (BodyChars);
		//std::cout << "The next node's body element is: \n" << BodyString << "\n";
	}




	return BodyString;


}
