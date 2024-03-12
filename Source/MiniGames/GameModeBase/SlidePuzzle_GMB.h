// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../MiniGamesGameModeBase.h"
#include "SlidePuzzle_GMB.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API ASlidePuzzle_GMB : public AMiniGamesGameModeBase
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere, Category = "MyDetail|bool")
	TArray<TObjectPtr<class ASlidePuzzle_PC>> PlayerList;

	UPROPERTY(EditAnywhere, Category = "MyDetail|bool")
	bool bIsMultiMode{ false };

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actors|Pointer")
	TObjectPtr<class AFixedCamera> FixedCamera{ nullptr };
	
	// -------------------------------------------------- //
	// -------------------- Defaults -------------------- //
	// -------------------------------------------------- //
public:

	ASlidePuzzle_GMB();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	// -------------------------------------------------- //
	// ---------------------- Main ---------------------- //
	// -------------------------------------------------- //
public:

	void Setup();
};
