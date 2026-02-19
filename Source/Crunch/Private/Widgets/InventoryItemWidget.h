// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/ItemWidget.h"
#include "Inventory/InventoryItem.h"
#include "InventoryItemWidget.generated.h"

class UTextBlock;
class UInventoryItem;
class UInventoryItemDragDropOp;

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInventoryItemDropped, UInventoryItemWidget* /*DestinationWidget*/, UInventoryItemWidget* /*SourceWidget*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnButtonClick, const FInventoryItemHandle& /*ItemHandle*/);
/**
 * 
 */
UCLASS()
class UInventoryItemWidget : public UItemWidget
{
	GENERATED_BODY()
	
public:
	FOnInventoryItemDropped OnInventoryItemDropped;
	FOnButtonClick OnLeftButtonClicked;
	FOnButtonClick OnRightButtonClicked;
	virtual void NativeConstruct() override;
	bool IsEmpty() const;
	void UpdateInventoryItem(const UInventoryItem* Item);
	void SetSlotNumber(int NewSlotNumber);
	void EmptySlot();
	FORCEINLINE int GetSlotNumber() const { return SlotNumber; }
	void UpdateStackCount();
	UTexture2D* GetIconTexture() const;

	FORCEINLINE const UInventoryItem* GetInventoryItem() const { return InventoryItem; }
	FInventoryItemHandle GetItemHandle() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	UTexture2D* EmptyTexture;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StackCountText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CooldownCountText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CooldownDurationText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ManaCostText;

	UPROPERTY()
	const UInventoryItem* InventoryItem;

	int SlotNumber;

	virtual void RightButtonClicked() override;
	virtual void LeftButtonClicked() override;

	/***********************************************/
	/*                    Drag Drop                */
	/***********************************************/
private:
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	UPROPERTY(EditDefaultsOnly, Category = "Drag Drop")
	TSubclassOf<UInventoryItemDragDropOp> DragDropOpClass;
};
