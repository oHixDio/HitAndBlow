// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayerController.h"
#include "Test_PC.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API ATest_PC : public AMyPlayerController
{
	GENERATED_BODY()
	
public:

	ATest_PC();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;
};
