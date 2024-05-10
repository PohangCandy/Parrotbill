// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Character.h"
#include "ABCharacter.generated.h"

UCLASS()
class ARENABATTLE_API AABCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AABCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	enum class EcontrolMode
	{
		GTA,
		DIABLO
	};

	void SetControlMode(EcontrolMode NewControlMode);
	EcontrolMode CurrentControlMode = EcontrolMode::GTA;
	FVector DirectionToMove = FVector::ZeroVector;

	float ArmLengthTo = 0.0f;
	FRotator ArmRotationTo = FRotator::ZeroRotator;
	float ArmLengthSpeed = 0.0f;
	float ArmRotationSpeed = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;
	virtual void PossessedBy(AController* NewController) override;

	virtual void PostLoad() override;	/*에디터나 게임 플레이 도중 혹은 디스크에서 로드되어 배치된 경우 제일 처음으로 호출된다.UActorComponent::OnComponentCreated()
		로드된 경우를 제외하고 모든 생성된 컴포넌트에 호출된다.*/
	virtual void PreRegisterAllComponents() override;	/*Actor의 생성 도중 호출되며, native root component를 가지고 있는 상태이다.UActorComponent::RegisterComponent()
		native root components를 가지고 있는 상태에서 호출된다.*/
	virtual void PostRegisterAllComponents() override;	/*모든 Actor 컴포넌트가 등록되고 호출딘다.*/
	virtual void PostActorCreated() override;	/*에디터나 게임 플레이 도중 생성되었을 때 호출되며 레벨에 의해 로드된 경우 호출되지 않는다.*/
	virtual void OnConstruction(const FTransform&) override;	/*블루프린트 생성을 호출하는 ExecuteConstruction의 끝으로 호출되며 모든 블루프린트로 생성되는 컴포넌트가 생성되고 등록된다.항상 게임 플레이 중 스폰된 Actor에만 호출된다.*/
	virtual void PreInitializeComponents() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	class AABWeapon* CurrentWeapon;

	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UABCharacterStatComponent* CharacterStat;

	void SetWeapon(class AABWeapon* NewWeapon);
	bool CanSetWeapon();

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void Turn(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void ViewChange();
	void Attack();
	void AttackStartComboState();
	void AttackEndComboState();
	void AttackCheck();


	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsAttacking;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool CanNextCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	bool IsComboInputOn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 CurrentCombo;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	int32 MaxCombo;
	
	UPROPERTY()
	class UABAnimInstance* ABAnim;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRange;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
	float AttackRadius;
};
