// Fill out your copyright notice in the Description page of Project Settings.


#include "HitAndBlow_PC.h"
#include "../GameModeBase/HitAndBlow_GMB.h"
#include "../GameStateBase/HitAndBlow_GSB.h"
#include "../HUD/HitAndBlow_HUD.h"
#include "../Actor/Board_HnB.h"
#include "../UserWidget/PauseMenu_UW.h"
#include <MiniGames/UserWidget/Result_UW.h>
#include "InputAction.h" // �ǉ�
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h" // �ǉ�
#include "EnhancedInputSubsystems.h" // �ǉ�
#include <Kismet/GameplayStatics.h>

AHitAndBlow_PC::AHitAndBlow_PC()
	:Super()
{
	
}

void AHitAndBlow_PC::BeginPlay()
{
	Super::BeginPlay();

	// InputMappingContext��ݒ�
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultIMC, 0);
	}
UE_LOG(LogTemp, Warning, TEXT("HitAndBlow_PC"));
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void AHitAndBlow_PC::BindPauseAction()
{
	// Pause�݂̂ł���
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		BindingActionList.Add(EnhancedInputComponent->BindAction(InputToPause, ETriggerEvent::Triggered, this, &AHitAndBlow_PC::EnablePause));
	}
}

void AHitAndBlow_PC::BindPauseModeAction()
{
	// Pause��Ԃ̑���
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		BindingActionList.Add(EnhancedInputComponent->BindAction(InputToPause, ETriggerEvent::Triggered, this, &AHitAndBlow_PC::DisablePause));

		// PauseMenu�̋@�\���o�C���h
		if (UPauseMenu_UW* PauseUI = Cast<UPauseMenu_UW>(GetHUD<AHitAndBlow_HUD>()->GetPauseUI()))
		{
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToDone, ETriggerEvent::Triggered, PauseUI, &UPauseMenu_UW::OnButton));
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToCancel, ETriggerEvent::Triggered, PauseUI, &UPauseMenu_UW::OnCancel));
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToSelectY, ETriggerEvent::Triggered, PauseUI, &UPauseMenu_UW::OnSelect));
		}
	}
}

void AHitAndBlow_PC::BindResultModeAction()
{
	// Result_UW����@�\��I��
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{

		// PauseMenu�̋@�\���o�C���h
		if (UResult_UW* ResultUI = Cast<UResult_UW>(GetHUD<AHitAndBlow_HUD>()->GetResultUI()))
		{
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToDone, ETriggerEvent::Triggered, ResultUI, &UResult_UW::OnButton));
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToSelectY, ETriggerEvent::Triggered, ResultUI, &UResult_UW::OnSelect));
		}
	}
	
}

void AHitAndBlow_PC::BindPlayModeAction()
{
	// Play��Ԃ̑���
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		BindingActionList.Add(EnhancedInputComponent->BindAction(InputToPause, ETriggerEvent::Triggered, this, &AHitAndBlow_PC::EnablePause));

		// Board�̋@�\���o�C���h
		AHitAndBlow_GMB* GameMode = GetWorld()->GetAuthGameMode<AHitAndBlow_GMB>();
		if (ABoard_HnB* Board = Cast<ABoard_HnB>(GameMode->GetBoard()))
		{
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToDone, ETriggerEvent::Triggered, GameMode, &AHitAndBlow_GMB::Interact));
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToSelectX, ETriggerEvent::Triggered, Board, &ABoard_HnB::TargetSelectPointUpdate));
			BindingActionList.Add(EnhancedInputComponent->BindAction(InputToSelectY, ETriggerEvent::Triggered, Board, &ABoard_HnB::TargetChoisePointUpdate));
		}
	}
}

void AHitAndBlow_PC::RemoveBindAction()
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bind�ς�Action�����O��
		for (FInputBindingHandle BindingAction : BindingActionList)
		{
			EnhancedInputComponent->RemoveBinding(BindingAction);
		}
	}
}

void AHitAndBlow_PC::AddBindAction(EHitAndBlowState State)
{
	switch (State)
	{
	case EHitAndBlowState::NONE:
		break;
	case EHitAndBlowState::BEFORE_PLAY:
		break;
	case EHitAndBlowState::PLAY:
		BindPlayModeAction();
		break;
	case EHitAndBlowState::AFTER_PLAY:
		break;
	case EHitAndBlowState::RESULT:
		BindResultModeAction();
		break;
	default:
		break;
	}
}

void AHitAndBlow_PC::SetPlayerEnableState(bool bIsEnable)
{
	if (bIsEnable)
	{
		EnableInput(this);
	}
	else
	{
		DisableInput(this);
	}
}

void AHitAndBlow_PC::EnablePause()
{
	Super::EnablePause();

	// PauseModeBind�ɕύX
	RemoveBindAction();
	BindPauseModeAction();

	UE_LOG(LogTemp, Warning, TEXT("IsPause"));
}

void AHitAndBlow_PC::DisablePause()
{
	Super::DisablePause();
	EHitAndBlowState CurState = GetWorld()->GetGameState<AHitAndBlow_GSB>()->GetCurrentState();

	RemoveBindAction();
	if (CurState == EHitAndBlowState::PLAY)
	{
		// PlayModeBind�ɕύX
		BindPlayModeAction();
	}
	else
	{
		BindPauseAction();
	}
	UE_LOG(LogTemp, Warning, TEXT("IsNotPause"));
}

void AHitAndBlow_PC::NoneAction()
{
}

