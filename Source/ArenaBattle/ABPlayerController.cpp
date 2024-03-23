// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPlayerController.h"

void AABPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	ABLOG_S(Warning);
}

void AABPlayerController::BeginPlay()
{
	ABLOG_S(Warning);
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}

//void AABPlayerController::SetupInputComponent()
//{
//	ABLOG_S(Warning);
//	Super::SetupInputComponent();
//	InputComponent->BindAxis(TEXT("LeftRight"), this, &AABPlayerController::LeftRight);
//}
//
//void AABPlayerController::LeftRight(float NewAxisValue)
//{
//	ABLOG_S(Warning);
//}
