// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GMB_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class CPPFLAPPYBIRD_API AGMB_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	public:

	AGMB_GameMode();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	int Score;

	UPROPERTY()
	int ScoreBuffer;

	UPROPERTY()
	int Lvl;

	UFUNCTION(BlueprintCallable, Category = Game)
	void AddPoints(int Points);
};
