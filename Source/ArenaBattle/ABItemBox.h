// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "ABItemBox.generated.h"

UCLASS()
class ARENABATTLE_API AABItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABItemBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	virtual void PostLoad() override;	/*에디터나 게임 플레이 도중 혹은 디스크에서 로드되어 배치된 경우 제일 처음으로 호출된다.UActorComponent::OnComponentCreated()
		로드된 경우를 제외하고 모든 생성된 컴포넌트에 호출된다.*/
	virtual void PreRegisterAllComponents() override;	/*Actor의 생성 도중 호출되며, native root component를 가지고 있는 상태이다.UActorComponent::RegisterComponent()
		native root components를 가지고 있는 상태에서 호출된다.*/
	virtual void PostRegisterAllComponents() override;	/*모든 Actor 컴포넌트가 등록되고 호출딘다.*/
	virtual void PostActorCreated() override;	/*에디터나 게임 플레이 도중 생성되었을 때 호출되며 레벨에 의해 로드된 경우 호출되지 않는다.*/
	virtual void OnConstruction(const FTransform&) override;	/*블루프린트 생성을 호출하는 ExecuteConstruction의 끝으로 호출되며 모든 블루프린트로 생성되는 컴포넌트가 생성되고 등록된다.항상 게임 플레이 중 스폰된 Actor에만 호출된다.*/
	virtual void PreInitializeComponents() override;

private:
	UPROPERTY(VisibleAnywhere, Category = Box)
	UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere, Category = Box)
	UStaticMeshComponent* Box;

public:
	UPROPERTY(EditInstanceOnly, Category = Box)
	TSubclassOf<class AABWeapon> WeaponItemClass;

	UPROPERTY(VisibleAnywhere, Category = Effect)
	UParticleSystemComponent* Effect;

	//UPROPERTY(EditInstanceOnly, Category = Box)
	//class AABWeapon *ItemWeapon;

private:
	UFUNCTION()
	void onCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEffectFinished(class UParticleSystemComponent* PSystem);

};
