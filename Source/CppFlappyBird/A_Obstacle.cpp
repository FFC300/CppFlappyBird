// Fill out your copyright notice in the Description page of Project Settings.


#include "A_Obstacle.h"

#include <ThirdParty/ShaderConductor/ShaderConductor/External/DirectXShaderCompiler/include/dxc/DXIL/DxilConstants.h>

#include "SkeletonTreeBuilder.h"

// Sets default values
AA_Obstacle::AA_Obstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		
	GapCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("GapCollider"));
	GapCollider->SetupAttachment(RootComponent);

	DownMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Down"));
	DownMesh->SetupAttachment(GapCollider);

	TopMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Top"));
	TopMesh->SetupAttachment(GapCollider);
}

// Called when the game starts or when spawned
void AA_Obstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_Obstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward(DeltaTime);
}

void AA_Obstacle::MoveForward(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + (FVector::LeftVector * DeltaTime * Speed);
	this->SetActorLocation(NewLocation);
}
