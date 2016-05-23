// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UnitMasterScript.h"
#include "Components/ActorComponent.h"
#include "BuildingMasterScript.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTSGAME_API UBuildingMasterScript : public UActorComponent
{
	GENERATED_BODY()
private:
	float BuildLerpTime;
public:	
	// Sets default values for this component's properties
	UBuildingMasterScript();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	virtual void BuildBuilding(float DeltaTime);
	virtual void BuildUnit(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float BuildTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float BuildTimeCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		FVector BuildLerpPosition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool IsBuilding;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool IsBuildingUnit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		FVector BuildOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		UBillboardComponent * SpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		UUnitMasterScript * myUnitToBuild;
};