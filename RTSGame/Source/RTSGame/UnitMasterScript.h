// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "UnitMasterScript.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTSGAME_API UUnitMasterScript : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnitMasterScript();
	float test;
	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	virtual AActor * GetActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool IsSelected;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		bool HasNewGoal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		FVector Goal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float ProductionTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		float ProductionTimeCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
		FString Name;
};
