// Fill out your copyright notice in the Description page of Project Settings.


#include "A_ObstacleSpawner.h"

// Sets default values
AA_ObstacleSpawner::AA_ObstacleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UArrowComponent>(TEXT("Root"));
	Root->SetupAttachment(RootComponent);

	ObstacleDestroyer = CreateDefaultSubobject<UBoxComponent>(TEXT("ObstacleDestroyer"));
	ObstacleDestroyer->SetupAttachment(Root);
	ObstacleDestroyer->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	
}


// Called when the game starts or when spawned
void AA_ObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();

	ObstacleDestroyer->OnComponentBeginOverlap.AddDynamic(this, &AA_ObstacleSpawner::OnOverlapBegin);

	FVector SpawnLocation = GetActorLocation();
	const FRotator SpawnRotation = GetActorRotation();

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	for (int i = 0; i < NumObstacles; i++)
	{
		if (ObstacleBlueprint)
		{
			AA_Obstacle* NewObstacle = GetWorld()->SpawnActor<AA_Obstacle>(ObstacleBlueprint, FVector(SpawnLocation.X, SpawnLocation.Y, FMath::RandRange(500, 1230)), SpawnRotation, SpawnParameters);

			if (NewObstacle)
			{
				Obstacles.Add(NewObstacle);
				SpawnLocation += FVector(ObstacleGap, 0, 0);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No se ha asignado ningún Blueprint a CubeBlueprint"));
			return;
		}
	}
	
}

// Called every frame
void AA_ObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AA_ObstacleSpawner::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Obstacle trigger reset"));
	if (OtherActor->ActorHasTag(FName("ObstacleActor")))
	{
		AA_Obstacle* Obstacle = Cast<AA_Obstacle>(OtherActor);
		
		Obstacles.Remove(Obstacle);
		Obstacles.Add(Obstacle);

		AA_Obstacle* LastObstacle = Obstacles[(Obstacles.Num() - 2)];
		FVector LastLocation = LastObstacle->GetActorLocation();
		FVector NewLocation = FVector(LastLocation.X, LastLocation.Y, 0) + FVector(ObstacleGap, 0, FMath::RandRange(500, 1230));

		Obstacle->SetActorLocation(NewLocation);
		
		
	}
}

