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
	// Camera�̎擾
	{
		// �擾
		TObjectPtr<AActor> GetActor = UGameplayStatics::GetActorOfClass(this, AFixedCamera::StaticClass());
		if (GetActor != nullptr)
		{
			FixedCamera = Cast<AFixedCamera>(GetActor);
		}
	}
	// Player�����A�擾�A������
	{
		// �}���`�v���C�̎��v���C���[����
		if (bIsMultiMode)
		{
			// �ő�2�v���C���[�̑z�肵�����Ă��Ȃ����߁APlayerID�͌Œ�łP(�f�t�H���g��1�����������Player��ID��0�ł���)	
			UGameplayStatics::CreatePlayer(this, 1);
		}

		// �擾
		TArray<TObjectPtr<AActor>> GetActors;
		UGameplayStatics::GetAllActorsOfClass(this, ASlidePuzzle_PC::StaticClass(), GetActors);
		for (TObjectPtr<AActor> act : GetActors)
		{
			if (Cast<ASlidePuzzle_PC>(act))
			{
				PlayerList.Add(Cast<ASlidePuzzle_PC>(Cast<ASlidePuzzle_PC>(act)));
			}
		}

		// �����ŏ��������Ȃ���2��ڂ̃R���g���[������肭�쓮���Ȃ�(this������)
		for (TObjectPtr<ASlidePuzzle_PC> Controller : PlayerList)
		{
			Controller->Setup();
			// Test�p
			EnableInput(Controller);
			// ���x����Camera���_�ɂ���
			Controller->SetViewTarget(FixedCamera);
		}
	}
	

}
