// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "A_Obstacle.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "A_ObstacleSpawner.generated.h"

UCLASS()
class CPPFLAPPYBIRD_API AA_ObstacleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_ObstacleSpawner();

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<AA_Obstacle> ObstacleBlueprint;

	UPROPERTY(EditAnywhere)
	TArray<AA_Obstacle*> Obstacles;
	
	UPROPERTY(EditAnywhere)
	UArrowComponent* Root;

	UPROPERTY(EditAnywhere)
	UBoxComponent* ObstacleDestroyer;

	UPROPERTY(EditAnywhere)
	int ObstacleGap = 1000;

	UPROPERTY(EditAnywhere)
	int NumObstacles = 10;


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
