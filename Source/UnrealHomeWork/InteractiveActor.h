// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ClickInterface.h"
#include "InteractiveActor.generated.h"

#define TEST_BIT(Bitmask, Bit) (((Bitmask) & (1 << static_cast<uint8>(Bit))) > 0)
#define SET_BIT(Bitmask, Bit) (Bitmask |= 1 << static_cast<uint8>(Bit))
#define CLEAR_BIT(Bitmask, Bit) (Bitmask &= ~(1 << static_cast<uint8>(Bit)))

UENUM(Meta = (Bitflags))
enum class EColor : uint8
{
	Red,
	Green,
	Blue,
	None
};


UCLASS()
class UNREALHOMEWORK_API AInteractiveActor : public AActor, public IClickInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractiveActor();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, Meta = (Bitmask, BitmaskEnum = EColor))
		uint8 ColorBits;



public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
