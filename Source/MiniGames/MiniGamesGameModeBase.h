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
	* Engine�Œ񋟂���Ă��郁�\�b�h��override�Q
	*/
public:
	AMiniGamesGameModeBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/*
	* �p�x�������������܂Ƃ߂����\�b�h�Q
	*/
public:
	// InputMappingContect�����t����
	void AddInputMap(APlayerController* PlayerController, class UInputMappingContext* InputMap, int32 Priority = 0);

	// InputMappingContect�����O��
	void RemoveInputMap(APlayerController* PlayerController, class UInputMappingContext* InputMap);

	// Actor��InterpToMove�����郁�\�b�h
	UFUNCTION(BlueprintCallable)
	void MoveActor(class AMyActor* Actor, FVector MoveOffset, float MoveTime);

	/*
	* ���Menu��Q�[���J�n�A�I�����ɌĂ΂�郁�\�b�h�Q
	*/
public:
	void OpenLevel(FName LevelName);

	void QuitGame();


};
