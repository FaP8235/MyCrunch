// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CCharacter.h"
#include "InputActionValue.h"
#include "GAS/CGameplayAbilityTypes.h"
#include "CPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class ACPlayerCharacter : public ACCharacter
{
	GENERATED_BODY()

public:
	ACPlayerCharacter();
	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "View")
	USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleDefaultsOnly, Category = "View")
	UCameraComponent* ViewCam;


	/**********************************************************/
	/*                          Input                         */
	/**********************************************************/
private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* JumpInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* LookInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TMap<ECAbilityInputID, UInputAction*> GameplayAbilityInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* GameplayInputMappingContext;

	void HandleLookInput(const FInputActionValue& InputActionValue);
	void HandleMoveInput(const FInputActionValue& InputActionValue);
	void HandleAbilityInput(const FInputActionValue& InputActionValue, ECAbilityInputID InputID);
	void SetInputEnabledFromPlayerController(bool bEnabled);

	FVector GetLookRightDir() const;
	FVector GetLookFwdDir() const;
	FVector GetMoveFwdDir() const;

	/**********************************************************/
	/*                           Stun                         */
	/**********************************************************/
	virtual void OnStun() override;
	virtual void OnRecoverFromStun() override;


	/**********************************************************/
	/*                    Death and Respawn                   */
	/**********************************************************/
	virtual void OnDead() override;
	virtual void OnRespawn() override;
};
