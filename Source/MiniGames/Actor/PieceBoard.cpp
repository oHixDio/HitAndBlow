// Fill out your copyright notice in the Description page of Project Settings.


#include "PieceBoard.h"

APieceBoard::APieceBoard()
	:Super()
{
	// Root����
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
	// PlayerNumber�ŏ����Ώۂ��قȂ�
	// Player0�Ȃ�Left : Player0�ȊO�Ȃ�Right
	int Index = PlayerNum == 0 ? 0 : 1;
	// ���͒l���v���X�Ȃ�
	if (InputValue > 0)
	{
		++SelectPoint[Index] %= 2;
	}
	// ���͒l���}�C�i�X�Ȃ�
	else
	{
		SelectPoint[Index]--;
		if (SelectPoint[Index] < 0) { SelectPoint[Index] = 1; }
	}
}


void APieceBoard::ChangeColSelect(int PlayerNum, float InputValue)
{
	// PlayerNumber�ŏ����Ώۂ��قȂ�
	// Player0�Ȃ�Left : Player0�ȊO�Ȃ�Right
	int Index = PlayerNum == 0 ? 1 : 3;
	// ���͒l���v���X�Ȃ�
	if (InputValue > 0)
	{
		++SelectPoint[Index] %= 3;
	}
	// ���͒l���}�C�i�X�Ȃ�
	else
	{
		SelectPoint[Index]--;
		if (SelectPoint[Index] < 0) { SelectPoint[Index] = 2; }
	}
}