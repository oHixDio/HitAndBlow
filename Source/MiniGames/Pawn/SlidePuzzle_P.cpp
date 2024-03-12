// Fill out your copyright notice in the Description page of Project Settings.


#include "InputAction.h" // 追加
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h" // 追加
#include "EnhancedInputSubsystems.h" // 追加
#include "SlidePuzzle_P.h"

ASlidePuzzle_P::ASlidePuzzle_P()
	:Super()
{
}

void ASlidePuzzle_P::BeginPlay()
{
	Super::BeginPlay();
	

	// 処理の実行速度
	// 1 PawnのBeginPlay
	// 2 PlayerControllerがPawnを所有する
	// 2->1の順で行なってほしいためNextTickを記述
	GetWorldTimerManager().SetTimerForNextTick
	(
		[&]()
		{
			if (APlayerController* PlayerController = Cast<APlayerController>(GetOwner()))
			{
				// InputMappingContextを設定
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
		// InputActionを機能にBindする
		BindingActionList.Add(EnhancedInputComponent->BindAction(InputToDone, ETriggerEvent::Triggered, this, &ASlidePuzzle_P::OnTest));
	}
	// UE_LOG(LogTemp, Warning, TEXT("Setup:%s"), *GetName());
	
}

void ASlidePuzzle_P::RemoveBindAction()
{
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerController->InputComponent))
	{
		// Bind済みActionを取り外す
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
