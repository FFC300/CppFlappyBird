// Fill out your copyright notice in the Description page of Project Settings.


#include "GMB_GameMode.h"

AGMB_GameMode::AGMB_GameMode()
{
	Score = 0;
	Lvl = 1;
}

void AGMB_GameMode::AddPoints(int Points)
{
	Score += Points;
	ScoreBuffer += Points;
	
	if (ScoreBuffer == 100)
	{
		Lvl++;
		ScoreBuffer = 0;
	}

	UE_LOG(LogTemp, Warning, TEXT("Puntaje actual: %d"), Score );
	
}
