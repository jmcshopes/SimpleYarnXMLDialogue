// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueGetter.h"
#include "Parser.h"
#include "XMLExtractor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UDialogueGetter::UDialogueGetter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDialogueGetter::BeginPlay()
{
	Super::BeginPlay();

	// TODO Replace the placeholders below with implementation as in UE4YarnToXML

	CurrentNode = "Start";

	std::string placeholdertext = "Placeholder text.";
	Dialogue = placeholdertext.c_str();

	// Creating a first option and adding

	int32 PlaceholderIndex = 0;
	FString PlaceholderOption = "Placeholder Option.";
	FString PlaceholderOptionCode = "Placeholder Option Code.";
	FString PlaceholderNode = "PlaceholderNodeNameText";

	FPlayerOptionType PlaceholderPlayerOptionType;
	PlaceholderPlayerOptionType.index = PlaceholderIndex;
	PlaceholderPlayerOptionType.option = PlaceholderOption;
	PlaceholderPlayerOptionType.optioncode = PlaceholderOptionCode;
	PlaceholderPlayerOptionType.node = PlaceholderNode;

	OptionsArray.Add(PlaceholderPlayerOptionType);

	// Creating a second option and adding

	PlaceholderOption = "Placeholder Option.2";
	PlaceholderOptionCode = "Placeholder Option Code.2";
	PlaceholderNode = "PlaceholderNodeNameText2";

	FPlayerOptionType PlaceholderPlayerOptionType2;
	PlaceholderPlayerOptionType2.index = PlaceholderIndex;
	PlaceholderPlayerOptionType2.option = PlaceholderOption;
	PlaceholderPlayerOptionType2.optioncode = PlaceholderOptionCode;
	PlaceholderPlayerOptionType2.node = PlaceholderNode;

	OptionsArray.Add(PlaceholderPlayerOptionType2);

	// Creating a third option and adding

	PlaceholderOption = "Placeholder Option.3";
	PlaceholderOptionCode = "Placeholder Option Code.3";
	PlaceholderNode = "PlaceholderNodeNameText3";

	FPlayerOptionType PlaceholderPlayerOptionType3;
	PlaceholderPlayerOptionType3.index = PlaceholderIndex;
	PlaceholderPlayerOptionType3.option = PlaceholderOption;
	PlaceholderPlayerOptionType3.optioncode = PlaceholderOptionCode;
	PlaceholderPlayerOptionType3.node = PlaceholderNode;

	OptionsArray.Add(PlaceholderPlayerOptionType3);

	// ...
	
}


// Called every frame
void UDialogueGetter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


TArray<FPlayerOptionType> UDialogueGetter::GetNextNode(const FString InputNode, const FString NPCName){
	
	// Using the Parser
	Parser ParserInstance;
	std::string ExampleXMLText = "Oh sorry dear, I didn't see you there. Did Orson send you about the clematis vines?  [[I'm afraid not. I wanted to ask you some questions.|VineQuestions]]  [[Um, yes, Orson sent me.Though he wasn't clear what needed doing with them.|YesForVines]]  [[No he didn't. Sorry.|NoVines]]";
	std::string node = std::string(TCHAR_TO_UTF8(*InputNode));
	XMLExtractor XMLExtractorInstance;

	FString ProjectDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
	UE_LOG(LogTemp, Warning, TEXT("Directory path is: %s"), *ProjectDir);

	UWorld* MyWorld = GetWorld();
	FString MapName = MyWorld->GetMapName();
	UE_LOG(LogTemp, Warning, TEXT("Map Name is: %s"), *MapName);
	UE_LOG(LogTemp, Warning, TEXT("NPC Name is: %s"), *NPCName);

	FString FFolderPath = ProjectDir + "Dialogues/" + MapName + "/" + NPCName + ".xml";
	// TODO Remove if not needed:
	//FString WinFriendlyPath = FFolderPath.Replace(TEXT("/"), TEXT("\\"));
	//UE_LOG(LogTemp, Warning, TEXT("FilePath is: %s"), *WinFriendlyPath);
	//std::string NPCName2 = "Oleya";
	//std::string Folderbit = XMLExtractorInstance.FolderPath;
	//std::string FilePath = Folderbit + NPCName2 + ".xml";

	std::string FilePath = std::string(TCHAR_TO_UTF8(*FFolderPath));
	tinyxml2::XMLDocument xmlDocToPass;
	tinyxml2::XMLError eResult = xmlDocToPass.LoadFile(FilePath.c_str());
	tinyxml2::XMLDocument *xmlDocToPassPointer;
	xmlDocToPassPointer = &xmlDocToPass;

	std::string XMLText = XMLExtractorInstance.ReadBody(xmlDocToPassPointer, node);

	OptionsArray = ParserInstance.ParseOptions(XMLText);
	Dialogue = ParserInstance.DialogueParser(XMLText);


	return OptionsArray;
	//OLD TEST
	/*
	if (InputNode == "Start") {
		std::string placeholdertext = "Placeholder 2 text.";
		Dialogue = placeholdertext.c_str();

		// Creating a first option and adding

		int32 PlaceholderIndex = 0;
		FString PlaceholderOption = "Placeholder 2 Option.";
		FString PlaceholderOptionCode = "Placeholder Option Code.";
		FString PlaceholderNode = "PlaceholderNodeNameText";

		FPlayerOptionType PlaceholderPlayerOptionType;
		PlaceholderPlayerOptionType.index = PlaceholderIndex;
		PlaceholderPlayerOptionType.option = PlaceholderOption;
		PlaceholderPlayerOptionType.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType.node = PlaceholderNode;

		OptionsArray.Add(PlaceholderPlayerOptionType);

		// Creating a second option and adding

		PlaceholderOption = "Placeholder 2 Option.2";
		PlaceholderOptionCode = "Placeholder Option Code.2";
		PlaceholderNode = "PlaceholderNodeNameText";

		FPlayerOptionType PlaceholderPlayerOptionType2;
		PlaceholderPlayerOptionType2.index = PlaceholderIndex;
		PlaceholderPlayerOptionType2.option = PlaceholderOption;
		PlaceholderPlayerOptionType2.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType2.node = PlaceholderNode;

		OptionsArray.Add(PlaceholderPlayerOptionType2);

		// Creating a third option and adding

		PlaceholderOption = "Placeholder 2 Option.3";
		PlaceholderOptionCode = "Placeholder Option Code.3";
		PlaceholderNode = "PlaceholderNodeNameText";

		FPlayerOptionType PlaceholderPlayerOptionType3;
		PlaceholderPlayerOptionType3.index = PlaceholderIndex;
		PlaceholderPlayerOptionType3.option = PlaceholderOption;
		PlaceholderPlayerOptionType3.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType3.node = PlaceholderNode;

		OptionsArray.Add(PlaceholderPlayerOptionType3);

		return OptionsArray;
	}
	else if (InputNode == "PlaceholderNodeNameText"){
		TArray<FPlayerOptionType> WorkingArray;
		
		OptionsArray.Empty();

		std::string placeholdertext = "BPlaceholder 2 text.";
		Dialogue = placeholdertext.c_str();

		// Creating a first option and adding

		int32 PlaceholderIndex = 0;
		FString PlaceholderOption = "BPlaceholder 2 Option.";
		FString PlaceholderOptionCode = "Placeholder Option Code.";
		FString PlaceholderNode = "PlaceholderNodeNameText";

		FPlayerOptionType PlaceholderPlayerOptionType;
		PlaceholderPlayerOptionType.index = PlaceholderIndex;
		PlaceholderPlayerOptionType.option = PlaceholderOption;
		PlaceholderPlayerOptionType.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType.node = PlaceholderNode;

		WorkingArray.Add(PlaceholderPlayerOptionType);

		// Creating a second option and adding

		PlaceholderOption = "BPlaceholder 2 Option.2";
		PlaceholderOptionCode = "Placeholder Option Code.2";
		PlaceholderNode = "PlaceholderNodeNameText";

		FPlayerOptionType PlaceholderPlayerOptionType2;
		PlaceholderPlayerOptionType2.index = PlaceholderIndex;
		PlaceholderPlayerOptionType2.option = PlaceholderOption;
		PlaceholderPlayerOptionType2.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType2.node = PlaceholderNode;

		WorkingArray.Add(PlaceholderPlayerOptionType2);

		// Creating a third option and adding

		PlaceholderOption = "BPlaceholder 2 Option.3";
		PlaceholderOptionCode = "Placeholder Option Code.3";
		PlaceholderNode = "Start";

		FPlayerOptionType PlaceholderPlayerOptionType3;
		PlaceholderPlayerOptionType3.index = PlaceholderIndex;
		PlaceholderPlayerOptionType3.option = PlaceholderOption;
		PlaceholderPlayerOptionType3.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType3.node = PlaceholderNode;

		WorkingArray.Add(PlaceholderPlayerOptionType3);

		return WorkingArray;
	}
	else
	{
		OptionsArray.Empty();
		int32 PlaceholderIndex = 0;
		FString PlaceholderOption = "ERROR Option.";
		FString PlaceholderOptionCode = "ERROR Option Code.";
		FString PlaceholderNode = "ERRORNodeNameText";

		FPlayerOptionType PlaceholderPlayerOptionType;
		PlaceholderPlayerOptionType.index = PlaceholderIndex;
		PlaceholderPlayerOptionType.option = PlaceholderOption;
		PlaceholderPlayerOptionType.optioncode = PlaceholderOptionCode;
		PlaceholderPlayerOptionType.node = PlaceholderNode;

		OptionsArray.Add(PlaceholderPlayerOptionType);
		return OptionsArray;
	}
	*/
}
