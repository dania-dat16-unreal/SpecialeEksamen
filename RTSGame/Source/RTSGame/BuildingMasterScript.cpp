// Fill out your copyright notice in the Description page of Project Settings.

#include "RTSGame.h"
#include "BuildingMasterScript.h"

// Sets default values for this component's properties
UBuildingMasterScript::UBuildingMasterScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UBuildingMasterScript::BeginPlay()
{
	Super::BeginPlay();
	SpawnPoint = GetOwner()->FindComponentByClass<UBillboardComponent>();
	// ...

}


// Called every frame
void UBuildingMasterScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsBuilding)
		BuildBuilding(DeltaTime);

	if (myUnitToBuild != nullptr)
	{
		IsBuildingUnit = true;
		BuildUnit(DeltaTime);

	}
}

void UBuildingMasterScript::BuildBuilding(float DeltaTime)
{
	BuildLerpTime = (DeltaTime / BuildTime) + BuildLerpTime;
	BuildTimeCounter = DeltaTime + BuildTimeCounter;
	FVector lerp = FMath::Lerp(FVector(BuildLerpPosition + BuildOffset), BuildLerpPosition, BuildLerpTime);
	//GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, lerp.ToString());
	GetOwner()->SetActorLocation(lerp, false, false, ETeleportType::None);

	if (BuildTime < BuildTimeCounter)
	{
		FVector finalpos = FVector(lerp.X, lerp.Y, 0);
		GetOwner()->SetActorLocation((finalpos), false, false, ETeleportType::None);
		IsBuilding = false;
	}
}

void UBuildingMasterScript::BuildUnit(float DeltaTime)
{
	myUnitToBuild->ProductionTimeCounter += DeltaTime;
	
	if (myUnitToBuild->ProductionTimeCounter > myUnitToBuild->ProductionTime)
	{
		myUnitToBuild->GetActor()->SetActorLocation(SpawnPoint->GetComponentLocation());
		myUnitToBuild = nullptr;
		IsBuildingUnit = false;
	}
}
