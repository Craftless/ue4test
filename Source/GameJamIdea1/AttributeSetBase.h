// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.generated.h"


/**
 * 
 */

UENUM(BlueprintType)
enum class EAttributeType : uint8 {
	Strength,
	Intelligence
};


// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnHealthChangedDelegate, float, CurrentHealth, float, MaxHealth, bool, FullHealth, float, PreviousHealth, AActor*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnManaChangedDelegate, float, CurrentMana, float, MaxMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStrengthChangedDelegate, float, CurrentValue, float, MaxValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIntelligenceChangedDelegate, float, CurrentValue, float, MaxValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMainAttributeChangedDelegate, EAttributeType, Type, float, CurrentValue);



class UAbilitySystemComponent;

UCLASS(DefaultToInstanced, Blueprintable)
class GAMEJAMIDEA1_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void BeginPlay();

	UFUNCTION(BlueprintCallable)
	void AddBaseAndCurrentValueOfAttribute(UPARAM(ref) FGameplayAttributeData& Data, float Value);
	UFUNCTION(BlueprintCallable)
	void SetBaseAndCurrentValueOfAttribute(UPARAM(ref) FGameplayAttributeData& Data, float Value);
	UFUNCTION(BlueprintCallable)
	void UpdateAllAttributes();
	UFUNCTION(BlueprintPure)
	UAbilitySystemComponent* GetOwnerASC() const;

	UFUNCTION()
	void OnMainAttributeChangedFunction(EAttributeType Type, float CurrentAttributeValue);

	UAttributeSetBase();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData HealthRegen;
	float PreviousHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Mana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData ManaRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData AttackDamage;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, AttackDamage)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Intelligence;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData & Data) override;
	FOnHealthChangedDelegate OnHealthChanged;
	FOnManaChangedDelegate OnManaChanged;
	FOnStrengthChangedDelegate OnStrengthChanged;
	FOnIntelligenceChangedDelegate OnIntelligenceChanged;
	FOnMainAttributeChangedDelegate OnMainAttributeChanged;

	UFUNCTION(BlueprintPure)
	float CalculateBaseAttackDamage() const;
	UFUNCTION(BlueprintPure)
	AProjectCharacter* GetOwningProjectCharacter() const;

};
