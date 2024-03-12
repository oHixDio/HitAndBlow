// Fill out your copyright notice in the Description page of Project Settings.


#include "InputAction.h" // ’Ç‰Á
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h" // ’Ç‰Á
#include "EnhancedInputSubsystems.h" // ’Ç‰Á
#include "../Pawn/SlidePuzzle_P.h"
#include "SlidePuzzle_PC.h"

	// -------------------------------------------------- //
	// -------------------- Defaults -------------------- //
	// -------------------------------------------------- //

ASlidePuzzle_PC::ASlidePuzzle_PC()
	:Super()
{
}

void ASlidePuzzle_PC::BeginPlay()
{
	Super::BeginPlay();

	
}

void ASlidePuzzle_PC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlidePuzzle_PC::Setup()
{

	SetInputMode(FInputModeGameOnly());

	bShowMouseCursor = false;
}