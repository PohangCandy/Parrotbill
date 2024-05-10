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

	virtual void PostLoad() override;	/*�����ͳ� ���� �÷��� ���� Ȥ�� ��ũ���� �ε�Ǿ� ��ġ�� ��� ���� ó������ ȣ��ȴ�.UActorComponent::OnComponentCreated()
		�ε�� ��츦 �����ϰ� ��� ������ ������Ʈ�� ȣ��ȴ�.*/
	virtual void PreRegisterAllComponents() override;	/*Actor�� ���� ���� ȣ��Ǹ�, native root component�� ������ �ִ� �����̴�.UActorComponent::RegisterComponent()
		native root components�� ������ �ִ� ���¿��� ȣ��ȴ�.*/
	virtual void PostRegisterAllComponents() override;	/*��� Actor ������Ʈ�� ��ϵǰ� ȣ����.*/
	virtual void PostActorCreated() override;	/*�����ͳ� ���� �÷��� ���� �����Ǿ��� �� ȣ��Ǹ� ������ ���� �ε�� ��� ȣ����� �ʴ´�.*/
	virtual void OnConstruction(const FTransform&) override;	/*�������Ʈ ������ ȣ���ϴ� ExecuteConstruction�� ������ ȣ��Ǹ� ��� �������Ʈ�� �����Ǵ� ������Ʈ�� �����ǰ� ��ϵȴ�.�׻� ���� �÷��� �� ������ Actor���� ȣ��ȴ�.*/
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
