// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacterWidget.h"
#include "ABCharacterStatComponent.h"
#include "Components/ProgressBar.h"

void UABCharacterWidget::BindCharacterStat(UABCharacterStatComponent* NewCharacterStat)
{
	ABCHECK(NewCharacterStat != nullptr);

	currentCharacterStat = NewCharacterStat;
	NewCharacterStat->OnHPChanged.AddUObject(this, &UABCharacterWidget::UpdateHPWidget);

}

void UABCharacterWidget::NativeConstruct()
{
	Super::NativeConstruct();
	HPProgerssBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBar")));
	ABCHECK(HPProgerssBar != nullptr);
	UpdateHPWidget();
}

void UABCharacterWidget::UpdateHPWidget()
{
	if (currentCharacterStat.IsValid())
	{
		if (HPProgerssBar != nullptr)
		{
			HPProgerssBar->SetPercent(currentCharacterStat->GetHpRatio());
		}
	}
}

