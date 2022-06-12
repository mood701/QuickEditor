// Fill out your copyright notice in the Description page of Project Settings.


#include "QuickEditorEx/QEActionDataAsset.h"
#include "IPythonScriptPlugin.h"
#include "EditorUtilitySubsystem.h"
#include "EditorUtilityWidgetBlueprint.h"


void UQEAction_RunPython::DoAction_Implemention() const
{
	IPythonScriptPlugin::Get()->ExecPythonCommand(*Script);
}

void UQEAction_OpenWidget::DoAction_Implemention() const
{
	UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
	if (EditorUtilitySubsystem)
	{
		UEditorUtilityWidgetBlueprint* Widget = Cast<UEditorUtilityWidgetBlueprint>(WidgetBlueprintPath.TryLoad());
		if (Widget)
		{
			EditorUtilitySubsystem->SpawnAndRegisterTab(Widget);
		}
	}
}
