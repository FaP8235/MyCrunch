// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayEffectTypes.h"
#include "LevelGauge.generated.h"

class UImage;
class UTextBlock;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class ULevelGauge : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	FName PercentMaterialParamName = "Percent";

	UPROPERTY(meta = (BindWidget))
	UImage* LevelProgressImage;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LevelText;

	FNumberFormattingOptions NumberFormattingOptions;

	const UAbilitySystemComponent* OwnerASC;

	void UpdateGauge(const FOnAttributeChangeData& Data);
};
