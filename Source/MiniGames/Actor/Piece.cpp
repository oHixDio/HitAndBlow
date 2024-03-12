// Fill out your copyright notice in the Description page of Project Settings.


#include "Piece.h"

APiece::APiece()
	:Super()
{
	// Root����
	if (RootComponent == nullptr)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	}
}

void APiece::BeginPlay()
{
	Super::BeginPlay();
}

void APiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
