// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayerController.h"
#include "SlidePuzzle_PC.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API ASlidePuzzle_PC : public AMyPlayerController
{
	GENERATED_BODY()



	// -------------------------------------------------- //
	// -------------------- Defaults -------------------- //
	// -------------------------------------------------- //
public:

	ASlidePuzzle_PC();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;


	// -------------------------------------------------- //
	// ---------------------- Main ---------------------- //
	// -------------------------------------------------- //
public:

	void Setup();

};
