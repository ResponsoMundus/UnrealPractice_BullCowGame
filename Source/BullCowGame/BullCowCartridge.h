// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	
	void InitGame();
	void EndGame();
	void ProcessGuess(const FString& Input);
	bool IsIsogram(const FString& Input) const;

	TArray<FString> GetValidWords(const TArray<FString>& WordList);

	// Your declarations go below!
	private:
	int32 NumLives;
	bool bGameOver;

	FString HiddenWord;
	TArray<FString> IsogramList;
};
