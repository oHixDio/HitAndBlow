// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceBoard.h"

APieceBoard::APieceBoard()
	:Super()
{
	// Root生成
	if (RootComponent == nullptr)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	}
	
}

void APieceBoard::BeginPlay()
{
	Super::BeginPlay();
}

void APieceBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APieceBoard::SetPointList
(
	TArray<USceneComponent*> NewLeftPieceDeployPointList,
	TArray<USceneComponent*> NewRightPieceDeployPointList,
	TArray<USceneComponent*> NewFixedPieceDeployPointList
)
{
	LeftPieceDeployPointList = NewLeftPieceDeployPointList;
	RightPieceDeployPointList = NewRightPieceDeployPointList;
	FixedPieceDeployPointList = NewFixedPieceDeployPointList;
}


void APieceBoard::ChangeRowSelect(int PlayerNum, float InputValue)
{
	// PlayerNumberで処理対象が異なる
	// Player0ならLeft : Player0以外ならRight
	int Index = PlayerNum == 0 ? 0 : 1;
	// 入力値がプラスなら
	if (InputValue > 0)
	{
		++SelectPoint[Index] %= 2;
	}
	// 入力値がマイナスなら
	else
	{
		SelectPoint[Index]--;
		if (SelectPoint[Index] < 0) { SelectPoint[Index] = 1; }
	}
}


void APieceBoard::ChangeColSelect(int PlayerNum, float InputValue)
{
	// PlayerNumberで処理対象が異なる
	// Player0ならLeft : Player0以外ならRight
	int Index = PlayerNum == 0 ? 1 : 3;
	// 入力値がプラスなら
	if (InputValue > 0)
	{
		++SelectPoint[Index] %= 3;
	}
	// 入力値がマイナスなら
	else
	{
		SelectPoint[Index]--;
		if (SelectPoint[Index] < 0) { SelectPoint[Index] = 2; }
	}
}