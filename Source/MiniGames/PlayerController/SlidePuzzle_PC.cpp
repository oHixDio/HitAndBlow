// Fill out your copyright notice in the Description page of Project Settings.


#include "InputAction.h" // 追加
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h" // 追加
#include "EnhancedInputSubsystems.h" // 追加
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