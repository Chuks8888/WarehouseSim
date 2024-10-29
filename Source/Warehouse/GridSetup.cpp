// Fill out your copyright notice in the Description page of Project Settings.


#include "GridSetup.h"
#include "Engine/Blueprint.h"
#include "Engine/World.h"
#include "Editor/EditorEngine.h"

// Sets default values
AGridSetup::AGridSetup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't nSeed it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGridSetup::BeginPlay()
{
	Super::BeginPlay();
}

void AGridSetup::SpawnObjects(UBlueprint* Actor, FString World, int width, int length, bool& OutputSuccess)
{
	if (!Actor)
	{
		OutputSuccess = false;
		return;	
	}

	if (!Actor->GeneratedClass->IsChildOf(AActor::StaticClass()))
	{
		OutputSuccess = false;
		return;
	}

	UWorld* world = nullptr;
	world = Cast<UWorld>(StaticLoadObject(UWorld::StaticClass(), nullptr, *World));

	if (!world)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::FString("world not loaded"));
		OutputSuccess = false;
		return;
	}

	FVector spawnloc = FVector();
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			spawnloc.Set(0.0f + 100.0f * j, 0.0f + 100.0f * i, 0.0f);
			world->SpawnActor(Actor->GeneratedClass, &spawnloc);
		}
	}
}

void AGridSetup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}