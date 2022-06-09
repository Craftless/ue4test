// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorTimeDilation.h"

// Sets default values for this component's properties
UActorTimeDilation::UActorTimeDilation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UActorTimeDilation::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UActorTimeDilation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActorTimeDilation::ChangeTimeDilation(float amount, bool isSelfAffected)
{
	if (!isSelfAffected)
	{
		AActor *Owner = this->GetOwner();
		if (!ensure(Owner))
			return;
		Owner->CustomTimeDilation = 1 / amount;
	}

	UWorld *World = this->GetWorld();
	if (!ensure(World))
		return;
	AWorldSettings *WorldSettings = World->GetWorldSettings();
	if (!ensure(WorldSettings))
		return;
	WorldSettings->SetTimeDilation(amount);
}

void UActorTimeDilation::ResetTimeDilation()
{
	UWorld *World = this->GetWorld();
	if (!ensure(World))
		return;
	AWorldSettings *WorldSettings = World->GetWorldSettings();
	if (!ensure(WorldSettings))
		return;
	WorldSettings->SetTimeDilation(1.f);

	AActor *Owner = this->GetOwner();
	if (!ensure(Owner))
		return;
	Owner->CustomTimeDilation = 1;
}
