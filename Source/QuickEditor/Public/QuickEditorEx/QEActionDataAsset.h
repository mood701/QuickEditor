// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QEActionDataAsset.generated.h"


UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class QUICKEDITOR_API UQEActionBase : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent)
	void DoAction() const;

	virtual void DoAction_Implemention() const{};
};

UCLASS(BlueprintType, EditInlineNew)
class QUICKEDITOR_API UQEAction_RunPython : public UQEActionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FString Script;
	virtual void DoAction_Implemention() const override;
};

UCLASS(BlueprintType, EditInlineNew)
class QUICKEDITOR_API UQEAction_OpenWidget : public UQEActionBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, meta = (AllowedClasses = "EditorUtilityWidgetBlueprint"))
	FSoftObjectPath WidgetBlueprintPath;
	UFUNCTION(BlueprintCallable)
	virtual void DoAction_Implemention() const override;
};

UCLASS()
class QUICKEDITOR_API UQEActionDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = QEAction)
	FString InEntryName; 
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category=QEAction)
	FString InEntryIcon;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Instanced, Category = QEAction)
	UQEActionBase* Action;
};
