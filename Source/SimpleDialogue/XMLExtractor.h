// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <string>
#include "Tinyxml.h"
#include <map>
#include "CoreMinimal.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

/**
 * 
 */
class SIMPLEDIALOGUE_API XMLExtractor
{
public:
	XMLExtractor();
	~XMLExtractor();
	std::string ReadBody(tinyxml2::XMLDocument*, std::string);
	std::string FolderPath = "C:\\Users\\Jack\\Documents\\Yarn\\"; // TODO abstract this

};
