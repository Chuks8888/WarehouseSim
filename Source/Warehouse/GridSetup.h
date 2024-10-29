// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "gridLayout.h"

#include "GridSetup.generated.h"

UCLASS(Blueprintable)
class WAREHOUSE_API AGridSetup : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AGridSetup();

protected:
	
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
		void SpawnObjects(UBlueprint* Actor, FString World, int width, int length, bool& OutputSuccess);

	virtual void Tick(float DeltaTime) override;
private:
	gridLayout layout;
};
