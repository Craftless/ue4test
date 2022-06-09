// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectCharacter.h"

// Sets default values
AProjectCharacter::AProjectCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AProjectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent -> BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent -> BindAxis("Turn", this, &APawn::AddControllerYawInput);

	PlayerInputComponent -> BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent -> BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent -> BindAxis("MoveForward", this, &AProjectCharacter::MoveForward);
	PlayerInputComponent -> BindAxis("MoveRight", this, &AProjectCharacter::MoveRight);
	
}

void AProjectCharacter::MoveForward(float Value) 
{
	if (Value == 0 || !ensure(GetController())) return;
	FRotator YawRotation(0, GetController() -> GetControlRotation().Yaw, 0);

	FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(ForwardVector, Value);
}

void AProjectCharacter::MoveRight(float Value) 
{
	if (Value == 0 || !ensure(GetController())) return;
	FRotator YawRotation(0, GetController() -> GetControlRotation().Yaw, 0);

	FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(RightVector, Value);
}