// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyHUD.h"
#include "HitAndBlow_HUD.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API AHitAndBlow_HUD : public AMyHUD
{
	GENERATED_BODY()
	

protected:

	UPROPERTY(EditAnywhere, Category = "UI|HitAndBlow")
	TSubclassOf<class UUserWidget> StartUIClass;

	UPROPERTY(VisibleAnywhere, Category = "UI|HitAndBlow")
	class UUserWidget* StartUI;

	UPROPERTY(EditAnywhere, Category = "UI|HitAndBlow")
	TSubclassOf<class UUserWidget> DetailUIClass;

	UPROPERTY(VisibleAnywhere, Category = "UI|HitAndBlow")
	class UUserWidget* DetailUI;

	UPROPERTY(EditAnywhere, Category = "UI|HitAndBlow")
	TSubclassOf<class UUserWidget> ResultUIClass;

	UPROPERTY(VisibleAnywhere, Category = "UI|HitAndBlow")
	TObjectPtr<class UUserWidget> ResultUI;

public:

	AHitAndBlow_HUD();

	virtual void BeginPlay() override;

public:
	const class UUserWidget* GetStartUI() const;

	const class UUserWidget* GetDetailUI() const;

	const TObjectPtr<class UUserWidget> GetResultUI() const;

public:
	virtual void Setup() override;

};
