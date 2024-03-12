// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "Piece.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API APiece : public AMyActor
{
	GENERATED_BODY()
	

	// -------------------------------------------------- //
	// -------------------- Defaults -------------------- //
	// -------------------------------------------------- //
public:
	// Sets default values for this actor's properties
	APiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
