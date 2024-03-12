// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../MiniGamesGameModeBase.h"
#include "Test_GMB.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API ATest_GMB : public AMiniGamesGameModeBase
{
	GENERATED_BODY()
	
public:

	ATest_GMB();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;
};
