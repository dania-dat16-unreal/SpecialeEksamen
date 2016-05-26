// Fill out your copyright notice in the Description page of Project Settings.

#include "RTSGame.h"
#include "MenuCPP.h"


// Sets default values for this component's properties
UMenuCPP::UMenuCPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMenuCPP::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UMenuCPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMenuCPP::ApplyScreenSettings(FString resolution, bool fullscreen, bool vsync)
{
	if (GEngine)
	{
		UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings();

		//Setting Resolution
		if (resolution == "800x600")
		{
			MyGameSettings->SetScreenResolution(FIntPoint(800, 600));
		}
		else if (resolution == "1280x800")
		{
			MyGameSettings->SetScreenResolution(FIntPoint(1280, 800));
		}
		else
		{
			MyGameSettings->SetScreenResolution(FIntPoint(1920, 1080));
		}

		//Setting to fullscreen if fullscreen true
		if (fullscreen)
		{
			MyGameSettings->SetFullscreenMode(EWindowMode::Fullscreen);
		}
		else
		{
			MyGameSettings->SetFullscreenMode(EWindowMode::Windowed);
		}

		//Setting V-Sync on if vsync true
		if (vsync)
		{
			MyGameSettings->SetVSyncEnabled(true);
		}
		else 
		{
			MyGameSettings->SetVSyncEnabled(false);
		}
		MyGameSettings->ApplySettings(false);
	}
}

void UMenuCPP::GetScreenSettings()
{
	if (GEngine)
	{
		UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings();

		FIntPoint tmpResolution = MyGameSettings->GetScreenResolution();

		if (tmpResolution == FIntPoint(800, 600))
		{
			resolutionOptionCPP = "800x600";
		}
		else if (tmpResolution == FIntPoint(1920, 1080))
		{
			resolutionOptionCPP = "1920x1080";
		}
		else 
		{
			resolutionOptionCPP = "1280x800";
		}

		int tmpFullscreen = MyGameSettings->GetFullscreenMode();

		if (tmpFullscreen == 0)
		{
			fullscreenCPP = true;
		}
		else
		{
			fullscreenCPP = false;
		}
		vsyncCPP = MyGameSettings->IsVSyncEnabled();
	}
}
