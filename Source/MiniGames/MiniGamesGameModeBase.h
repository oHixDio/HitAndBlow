// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MiniGamesGameModeBase.generated.h"


/**
 * 
 */
UCLASS(Abstract)
class MINIGAMES_API AMiniGamesGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	/*
	* Engineで提供されているメソッドのoverride群
	*/
public:
	AMiniGamesGameModeBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/*
	* 頻度が高い処理をまとめたメソッド群
	*/
public:
	// InputMappingContectを取り付ける
	void AddInputMap(APlayerController* PlayerController, class UInputMappingContext* InputMap, int32 Priority = 0);

	// InputMappingContectを取り外す
	void RemoveInputMap(APlayerController* PlayerController, class UInputMappingContext* InputMap);

	// ActorをInterpToMoveさせるメソッド
	UFUNCTION(BlueprintCallable)
	void MoveActor(class AMyActor* Actor, FVector MoveOffset, float MoveTime);

	/*
	* 主にMenuやゲーム開始、終了時に呼ばれるメソッド群
	*/
public:
	void OpenLevel(FName LevelName);

	void QuitGame();


};
