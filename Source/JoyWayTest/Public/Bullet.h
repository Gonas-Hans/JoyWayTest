// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Bullet.generated.h"

UCLASS()
class JOYWAYTEST_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	UPROPERTY(BlueprintReadOnly, Category = Bullet)
	USphereComponent* SphereComponent;

	UPROPERTY(BlueprintReadOnly, Category = Bullet)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(BlueprintReadOnly, Category = Bullet)
	UStaticMeshComponent* StaticMesh;


	//Damage overlapped actor
	UFUNCTION()
	void DamageActorOnBeginOverlap(class UPrimitiveComponent* HitComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	//Destroy this actor when it stop
	UFUNCTION()
	void DestroyProjectileStop(const FHitResult& ImpactResult);
	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Bullet)
	float Damage = 10.0f;

};
