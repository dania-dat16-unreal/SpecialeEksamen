// Fill out your copyright notice in the Description page of Project Settings.

#include "RTSGame.h"
#include "UnitMasterScript.h"


// Sets default values for this component's properties
UUnitMasterScript::UUnitMasterScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UUnitMasterScript::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UUnitMasterScript::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

AActor * UUnitMasterScript::GetActor()
{
	return GetOwner();
}


