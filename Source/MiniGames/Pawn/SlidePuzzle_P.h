// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h" // 追加
#include "MyPawn.h"
#include "SlidePuzzle_P.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API ASlidePuzzle_P : public AMyPawn
{
	GENERATED_BODY()


	// -------------------------------------------------- //
	// -------------- InputMappingContexts  ------------- //
	// -------------------------------------------------- //
private:
	UPROPERTY(EditAnywhere, Category = "EnhancedInput|InputMappingContext")
	TObjectPtr<class UInputMappingContext> DefaultIMC{ nullptr };


	// -------------------------------------------------- //
	// ------------------ InputActions  ----------------- //
	// -------------------------------------------------- //
	// InputActionはPlayerContrpllerに配置
	// InputToOOOOOをテンプレとする
private:
	UPROPERTY(EditAnywhere, Category = "EnhancedInput|InputActions")
	TObjectPtr<class UInputAction> InputToPause{ nullptr };

	UPROPERTY(EditAnywhere, Category = "EnhancedInput|InputActions")
	TObjectPtr<class UInputAction> InputToDone{ nullptr };

	UPROPERTY(EditAnywhere, Category = "EnhancedInput|InputActions")
	TObjectPtr<class UInputAction> InputToCancel{ nullptr };

	UPROPERTY(EditAnywhere, Category = "EnhancedInput|InputActions")
	TObjectPtr<class UInputAction> InputToSelectX{ nullptr };

	UPROPERTY(EditAnywhere, Category = "EnhancedInput|InputActions")
	TObjectPtr<class UInputAction> InputToSelectY{ nullptr };


protected:
	
	// 現在PlayerがBind中のActionList
	// UPROPERTYはつけられない
	TArray<FInputBindingHandle> BindingActionList;




	// -------------------------------------------------- //
	// -------------------- Defaults -------------------- //
	// -------------------------------------------------- //
public:
	// Sets default values for this pawn's properties
	ASlidePuzzle_P();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	// -------------------------------------------------- //
	// --------------------- Binds  --------------------- //
	// -------------------------------------------------- //
public:

	void RemoveBindAction();


	// -------------------------------------------------- //
	// -------------------- Actions  -------------------- //
	// -------------------------------------------------- //
public:

	void OnTest(const FInputActionValue& Value);
};
