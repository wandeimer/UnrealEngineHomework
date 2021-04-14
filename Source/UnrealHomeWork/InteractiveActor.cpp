// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveActor.h"

// Sets default values
AInteractiveActor::AInteractiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;


}

// Called when the game starts or when spawned
void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StaticMeshComponent->AddRelativeRotation(FRotator(0.f, 0.f, 1.f));

	FVector Color(0.f, 0.f, 0.f);

	if (TEST_BIT(ColorBits, EColor::Red))
	{
		Color.X = 1.f;
	}
	else
	{
		Color.X = 0.f;
	}
	if (TEST_BIT(ColorBits, EColor::Green))
	{
		Color.Y = 1.f;
	}
	else
	{
		Color.Y = 0.f;
	}
	if (TEST_BIT(ColorBits, EColor::Blue))
	{
		Color.Z = 1.f;
	}
	else
	{
		Color.Z = 0.f;
	}
	StaticMeshComponent->SetVectorParameterValueOnMaterials(FName("Color"), Color);
}

