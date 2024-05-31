// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacterStatComponent.h"
#include "ABGameInstance.h"

// Sets default values for this component's properties
UABCharacterStatComponent::UABCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
	
	level = 1;
}


// Called when the game starts
void UABCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UABCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetLevel(level);
}

void UABCharacterStatComponent::SetLevel(int newLevel)
{
	auto ABGameInstance = Cast<UABGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	ABCHECK(ABGameInstance != nullptr)
	CurrentStatData = ABGameInstance->GetABCharacterData(newLevel);
	if (CurrentStatData != nullptr)
	{
		level = newLevel;
		CurrentHP = CurrentStatData->MaxHP;
	}
	else {
		ABLOG(Error, TEXT("Leval ( %d ) does not exist."), newLevel);
	}
}

void UABCharacterStatComponent::SetDamage(float NewDamage)
{
	ABCHECK(CurrentStatData != nullptr);
	CurrentHP = FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP);
	if (CurrentHP <= 0)
	{
		OnHPIsZero.Broadcast();
	}
}

float UABCharacterStatComponent::GetAttack()
{
	ABCHECK(CurrentStatData != nullptr, 0.0f);
	return CurrentStatData->Attack;
}


// Called every frame
void UABCharacterStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

