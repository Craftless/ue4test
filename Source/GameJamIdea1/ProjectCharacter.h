// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayEffect.h"

#include "ProjectCharacter.generated.h"

UCLASS()
class GAMEJAMIDEA1_API AProjectCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AProjectCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const { return SystemComp; }

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UAbilitySystemComponent* SystemComp = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ProjectCharacter")
	class UAttributeSetBase* AttributeSetBase;

	UFUNCTION(BlueprintCallable)
	void AcquireAbility(TSubclassOf<class UGameplayAbility> AbilityToAcquire);
	UFUNCTION(BlueprintCallable)
	void AcquireAbilities(TArray<TSubclassOf<class UGameplayAbility>> AbilitiesToAcquire);

private:
	void MoveForward(float Value);
	void MoveRight(float Value);

};
