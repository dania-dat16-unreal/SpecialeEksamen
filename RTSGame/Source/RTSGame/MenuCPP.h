// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "MenuCPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTSGAME_API UMenuCPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMenuCPP();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ScreenSettings")
		FString resolutionOptionCPP;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ScreenSettings")
		bool fullscreenCPP;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ScreenSettings")
		bool vsyncCPP;

	UFUNCTION(BlueprintCallable, Category = "ScreenSettings")
		virtual void ApplyScreenSettings(FString resolution, bool fullscreen, bool vsync);

	UFUNCTION(BlueprintCallable, Category = "ScreenSettings")
		virtual void GetScreenSettings();
	
	UFUNCTION(BlueprintCallable, Category = "GraphicQuality")
		virtual void SetQuality(int qualityLevel);
	UFUNCTION(BlueprintCallable, Category = "GraphicQuality")
		virtual int GetQuality();
	
};
