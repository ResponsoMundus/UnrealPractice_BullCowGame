// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

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

	TArray<FString> GetValidWords(const TArray<FString>& WordList) const;
	// void GetBullCows(const FString Input, int32& Bulls, int32& Cows) const;
	FBullCowCount GetBullCows(const FString Input) const;

	// Your declarations go below!
	private:

	int32 NumLives;
	bool bGameOver;

	FString HiddenWord;
	TArray<FString> IsogramList;
};
