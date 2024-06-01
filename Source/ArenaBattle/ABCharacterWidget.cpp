// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacterWidget.h"

void UABCharacterWidget::BindCharacterStat(UABCharacterStatComponent* NewCharacterStat)
{
	ABCHECK(NewCharacterStat != nullptr);

	currentCharacterStat = NewCharacterStat;

	NewCharacterStat->OnHPChanged.AddLambda([this]()->void {
	if (currentCharacterStat.IsValid())
	{
		ABLOG(Warning, TEXT(" HPRatio : %f "), currentCharacterStat->GetHpRatio());
	}
	});

}

