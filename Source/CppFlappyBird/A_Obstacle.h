// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "A_Obstacle.generated.h"

UCLASS()
class CPPFLAPPYBIRD_API AA_Obstacle : public AActor
{
	GENERATED_BODY()



public:	
	// Sets default values for this actor's properties
	AA_Obstacle();

	UPROPERTY(EditAnywhere)
	UBoxComponent* GapCollider;

	UPROPERTY(EditAnywhere)
	float Speed = 500.0f;
	
	void MoveForward(float DeltaTime);
	
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DownMesh;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* TopMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
