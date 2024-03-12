// Fill out your copyright notice in the Description page of Project Settings.


#include "InputAction.h" // �ǉ�
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h" // �ǉ�
#include "EnhancedInputSubsystems.h" // �ǉ�
#include "SlidePuzzle_P.h"

ASlidePuzzle_P::ASlidePuzzle_P()
	:Super()
{
}

void ASlidePuzzle_P::BeginPlay()
{
	Super::BeginPlay();
	

	// �����̎��s���x
	// 1 Pawn��BeginPlay
	// 2 PlayerController��Pawn�����L����
	// 2->1�̏��ōs�Ȃ��Ăق�������NextTick���L�q
	GetWorldTimerManager().SetTimerForNextTick
	(
		[&]()
		{
			if (APlayerController* PlayerController = Cast<APlayerController>(GetOwner()))
			{
				// InputMappingContext��ݒ�
				if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
				{
					Subsystem->AddMappingContext(DefaultIMC, 0);
				}
			}
		}
	);



}

void ASlidePuzzle_P::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlidePuzzle_P::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// InputAction���@�\��Bind����
		BindingActionList.Add(EnhancedInputComponent->BindAction(InputToDone, ETriggerEvent::Triggered, this, &ASlidePuzzle_P::OnTest));
	}
	// UE_LOG(LogTemp, Warning, TEXT("Setup:%s"), *GetName());
	
}

void ASlidePuzzle_P::RemoveBindAction()
{
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerController->InputComponent))
	{
		// Bind�ς�Action�����O��
		for (FInputBindingHandle BindingAction : BindingActionList)
		{
			EnhancedInputComponent->RemoveBinding(BindingAction);
		}
	}
}

void ASlidePuzzle_P::OnTest(const FInputActionValue& Value)
{
	float Val = Value.Get<float>();
	UE_LOG(LogTemp, Warning, TEXT("MyName:%s"), *GetName());
}
