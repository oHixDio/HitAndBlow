// Fill out your copyright notice in the Description page of Project Settings.


#include <Kismet/GameplayStatics.h>
#include "../PlayerController/SlidePuzzle_PC.h"
#include "../Actor/FixedCamera.h"
#include "SlidePuzzle_GMB.h"

	// -------------------------------------------------- //
	// -------------------- Defaults -------------------- //
	// -------------------------------------------------- //

ASlidePuzzle_GMB::ASlidePuzzle_GMB()
	:Super()
{
}

void ASlidePuzzle_GMB::BeginPlay()
{
	Super::BeginPlay();

	Setup();
}

void ASlidePuzzle_GMB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlidePuzzle_GMB::Setup()
{
	// Cameraの取得
	{
		// 取得
		TObjectPtr<AActor> GetActor = UGameplayStatics::GetActorOfClass(this, AFixedCamera::StaticClass());
		if (GetActor != nullptr)
		{
			FixedCamera = Cast<AFixedCamera>(GetActor);
		}
	}
	// Player生成、取得、初期化
	{
		// マルチプレイの時プレイヤー生成
		if (bIsMultiMode)
		{
			// 最大2プレイヤーの想定しかしていないため、PlayerIDは固定で１(デフォルトで1名生成されるPlayerのIDは0である)	
			UGameplayStatics::CreatePlayer(this, 1);
		}

		// 取得
		TArray<TObjectPtr<AActor>> GetActors;
		UGameplayStatics::GetAllActorsOfClass(this, ASlidePuzzle_PC::StaticClass(), GetActors);
		for (TObjectPtr<AActor> act : GetActors)
		{
			if (Cast<ASlidePuzzle_PC>(act))
			{
				PlayerList.Add(Cast<ASlidePuzzle_PC>(Cast<ASlidePuzzle_PC>(act)));
			}
		}

		// ここで初期化しないと2台目のコントローラが上手く作動しない(thisが原因)
		for (TObjectPtr<ASlidePuzzle_PC> Controller : PlayerList)
		{
			Controller->Setup();
			// Test用
			EnableInput(Controller);
			// レベルのCamera視点にする
			Controller->SetViewTarget(FixedCamera);
		}
	}
	

}
