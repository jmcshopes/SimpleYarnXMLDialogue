// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <vector>
#include "Components/ActorComponent.h"
#include "DialogueGetter.generated.h"

USTRUCT(BlueprintType)
struct FPlayerOptionType 
{
	GENERATED_BODY()

		FPlayerOptionType()        // this is your default constructor which is required for a USTRUCT definition
	{
		// initialize things here if desired or required
	}


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Option Type")
	int32 index;
	// TODO Replace these type with types that can be a UPROPERTY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Option Type")
	FString option;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Option Type")
	FString optioncode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Option Type")
	FString node;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIMPLEDIALOGUE_API UDialogueGetter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDialogueGetter();
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Dialogue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FPlayerOptionType> OptionsArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	FString CurrentNode;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	TArray<FPlayerOptionType> GetNextNode(const FString InputNode, const FString NPCName);

	
};
