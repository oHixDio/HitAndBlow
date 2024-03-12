// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "PieceBoard.generated.h"

/**
 * 
 */
UCLASS()
class MINIGAMES_API APieceBoard : public AMyActor
{
	GENERATED_BODY()


	// -------------------------------------------------- //
	// ------------------- Components ------------------- //
	// -------------------------------------------------- //
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components|PointList")
	TArray<USceneComponent*> LeftPieceDeployPointList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components|PointList")
	TArray<USceneComponent*> RightPieceDeployPointList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components|PointList")
	TArray<USceneComponent*> FixedPieceDeployPointList;


	// -------------------------------------------------- //
	// --------------------- Index  --------------------- //
	// -------------------------------------------------- //
protected:

	// Left, Right
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components|Index")
	TArray<uint8> SelectPoint{ 0,0 };


	// -------------------------------------------------- //
	// --------------------- Others --------------------- //
	// -------------------------------------------------- //
protected:
	UPROPERTY(VisibleAnywhere, Category = "Other")
	FVector PieceDeployOffset{ FVector(0,0,0.2) };
	


	// -------------------------------------------------- //
	// -------------------- Defaults -------------------- //
	// -------------------------------------------------- //
public:
	APieceBoard();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


	// -------------------------------------------------- //
	// --------------- BlueprintCallables --------------- //
	// -------------------------------------------------- //
protected:
	UFUNCTION(BlueprintCallable)
	void SetPointList(
		TArray<USceneComponent*> NewLeftPieceDeployPointList,
		TArray<USceneComponent*> NewRightPieceDeployPointList,
		TArray<USceneComponent*> NewFixedPieceDeployPointList
	);


	// -------------------------------------------------- //
	// ---------------------- Main ---------------------- //
	// -------------------------------------------------- //
public:

	void ChangeRowSelect(int PlayerNum, float InputValue);

	void ChangeColSelect(int PlayerNum, float InputValue);
};
