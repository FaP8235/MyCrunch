// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GAS/CGameplayAbilityTypes.h"
#include "GameplayWidget.generated.h"

class UValueGauge;
class UAbilitySystemComponent;
class UGameplayAbility;
class UAbilityListView;
class UStatsGauge;
class UShopWidget;
class UWidgetAnimation;
class UInventoryWidget;
/**
 * 
 */
UCLASS()
class UGameplayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	void ConfigureAbilities(const TMap<ECAbilityInputID, TSubclassOf<UGameplayAbility>>& Abilities);
	void ToggleShop();
	
private:
	UPROPERTY(meta=(BindWidget))
	UValueGauge* HealthBar;

	UPROPERTY(meta=(BindWidget))
	UValueGauge* ManaBar;

	UPROPERTY(meta=(BindWidget))
	UAbilityListView* AbilityListView;
	
	UPROPERTY(meta=(BindWidget))
	UStatsGauge* AttackDamageGauge;

	UPROPERTY(meta=(BindWidget))
	UStatsGauge* ArmorGauge;

	UPROPERTY(meta=(BindWidget))
	UStatsGauge* MoveSpeedGauge;

	UPROPERTY(meta=(BindWidget))
	UStatsGauge* IntelligenceGauge;
	
	UPROPERTY(meta=(BindWidget))
	UStatsGauge* StrengthGauge;

	UPROPERTY(meta=(BindWidget))
	UShopWidget* ShopWidget;

	UPROPERTY(meta=(BindWidget))
	UInventoryWidget* InventoryWidget;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	UWidgetAnimation* ShopPopupAnimation;
	
	void PlayShopPopupAnimation(bool bPlayForward);
	void SetOwningPawnInputEnabled(bool bPawnInputEnabled);
	void SetShowMouseCursor(bool bShowMouseCursor);
	void SetFocusToGameAndUI();
	void SetFocusToGameOnly();

	UPROPERTY()
	UAbilitySystemComponent* OwnerAbilitySystemComponent;
};
