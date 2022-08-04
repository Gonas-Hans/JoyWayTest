// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class JOYWAYTEST_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	UPROPERTY(BlueprintReadOnly, Category = Gun)
	USkeletalMeshComponent* SkeletalMeshGun;
	
	UPROPERTY(BlueprintReadOnly, Category = Gun)
	USceneComponent* Muzzle;
	
	UPROPERTY(BlueprintReadOnly, Category = Gun)
	UTextRenderComponent* AmmoText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Gun)
	int32 DefaultAmmo = 30;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Gun)
	int32 CurrentAmmo = 0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Gun)
	FVector BulletScale = FVector(1.0f, 1.0f, 1.0f);

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Gun)
	float BulletDamage = 10;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Gun)
	TSubclassOf<ABullet> BulletClass;

	//Spawn bullet actor
	UFUNCTION(BlueprintCallable, Category = Gun)
	void MakeShot();

	//Set Ammo as Default
	UFUNCTION(BlueprintCallable, Category = Gun)
	void Reload();
	
};
