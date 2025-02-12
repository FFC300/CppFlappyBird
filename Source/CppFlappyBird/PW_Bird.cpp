// Fill out your copyright notice in the Description page of Project Settings.


#include "PW_Bird.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APW_Bird::APW_Bird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->SetupAttachment(Mesh);
	
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetupAttachment(Mesh);
	BoxCollider->SetBoxExtent(FVector(20.0f, 20.0f, 20.0f));
	
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Mesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void APW_Bird::BeginPlay()
{
	Super::BeginPlay();

	//Sets simulating physics and locks X, Y movement and Rotation
	Mesh->SetSimulatePhysics(true);
	Mesh->BodyInstance.bLockRotation = true;
	Mesh->BodyInstance.bLockXTranslation = true;
	Mesh->BodyInstance.bLockYTranslation = true;

	//Enables collisions
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &APW_Bird::OnOverlapBegin);
	
}

// Called every frame
void APW_Bird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APW_Bird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APW_Bird::Jump);

}

void APW_Bird::Jump()
{
	UE_LOG(LogTemp, Warning, TEXT("Jumping"));
	Mesh->BodyInstance.SetLinearVelocity(FVector::UpVector * JumpForce, false);
}

void APW_Bird::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Obstacle"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hitted"));
		//UGameplayStatics::OpenLevel(this, FName(TEXT("World")), true);
	}
}