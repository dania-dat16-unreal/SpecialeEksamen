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


//https://answers.unrealengine.com/questions/51623/how-to-fullscreen-packaged-build.html - Helped finding commands for Screen altering.

//Sets the screen values based on the options menu after clicking apply.
void UMenuCPP::ApplyScreenSettings(FString resolution, bool fullscreen, bool vsync)
{
	if (GEngine)
	{
		UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings(); //Defines the GameUserSettings

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

//Gets the Screen values for setting the options visual values e.g. Checkboxes based on the current values.
void UMenuCPP::GetScreenSettings()
{
	if (GEngine)
	{
		UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings(); //Defines the GameUserSettings

		FIntPoint tmpResolution = MyGameSettings->GetScreenResolution(); //Temp value for checking

		//Prepares resolution variable to be used when instantiating options menu
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

		int tmpFullscreen = MyGameSettings->GetFullscreenMode(); //Temp value of the current mode

		//Prepares fulldscreen variable to be used when instantiating options menu
		if (tmpFullscreen == 0)
		{
			fullscreenCPP = true;
		}
		else
		{
			fullscreenCPP = false;
		}
		
		vsyncCPP = MyGameSettings->IsVSyncEnabled(); //Gets the current state of vsync and sets the variable.
	}
}

//https://docs.unrealengine.com/latest/INT/Engine/Performance/Scalability/ScalabilityReference/
void UMenuCPP::SetQuality(int qualityLevel)
{
	UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings(); //Defines the GameUserSettings

	//Sets the largest graphics groups to the level chosen, could have been done on individual buttons, but made it simple with a single button :) (Level 3 is Default)
	MyGameSettings->SetAntiAliasingQuality(qualityLevel);
	MyGameSettings->SetPostProcessingQuality(qualityLevel);
	MyGameSettings->SetShadowQuality(qualityLevel);
	MyGameSettings->SetTextureQuality(qualityLevel);
	MyGameSettings->SetVisualEffectQuality(qualityLevel);

	MyGameSettings->ApplySettings(false);
}
int UMenuCPP::GetQuality()
{
	UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings(); //Defines the GameUserSettings

	return MyGameSettings->GetAntiAliasingQuality(); //Returning a single of the settings as they've set together through code (Not checked)
}
