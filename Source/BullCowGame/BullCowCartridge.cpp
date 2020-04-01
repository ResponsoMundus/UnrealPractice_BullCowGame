// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver) {
        ClearScreen();
        InitGame();
    } else {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::InitGame()
{
    PrintLine(TEXT("Hello Player! Welcome to Bull Cow Game!"));

    HiddenWord = TEXT("xisuma");
    NumLives = HiddenWord.Len();
    bGameOver = false;

    // PrintLine(TEXT("The Hidden Word is %i letter long!"), HiddenWord.Len());
    // PrintLine(TEXT("Debug Info: The Hidden Word is %s!"), *HiddenWord);

    PrintLine(TEXT("Guess the %i characters word in %i lives."), HiddenWord.Len(), NumLives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("The Hidden Word is %s."), *HiddenWord);
    PrintLine(TEXT("Enter to play again!"));
}

void UBullCowCartridge::ProcessGuess(const FString& Input) {
    if (Input == HiddenWord) {
        PrintLine(TEXT("You've Won"));
        EndGame();
        return;
    }

    if (Input.Len() != HiddenWord.Len()) {
        PrintLine(TEXT("The Hidden Word is a %i characters long!"), HiddenWord.Len());
        PrintLine(TEXT("%i lives left! Try Again!"), NumLives);
        return;
    }

    if (!IsIsogram(Input)) {
        PrintLine(TEXT("%s is not an isogram!"), *Input);
    }

    if (--NumLives == 0) {
        PrintLine(TEXT("You've lost!"));
        EndGame();
    } else {
        PrintLine(TEXT("%i lives left! Try Again!"), NumLives);
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Input) {
    return false;
}