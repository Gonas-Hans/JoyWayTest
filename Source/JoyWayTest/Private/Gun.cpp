// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshGun = CreateDefaultSubobject<USkeletalMeshComponent>(FName("SkeletalMesh"));
	RootComponent = SkeletalMeshGun;

	Muzzle = CreateDefaultSubobject<USceneComponent>(FName("Muzzle"));
	Muzzle->SetupAttachment(RootComponent);

	AmmoText = CreateDefaultSubobject<UTextRenderComponent>(FName("Ammo"));
	AmmoText->SetupAttachment(RootComponent);
}

void AGun::MakeShot()
{
	if (CurrentAmmo > 0)
	{
		FVector MuzzleLocation = Muzzle->GetComponentLocation();
		FRotator MuzzleRotation = Muzzle->GetComponentRotation();
		FTransform MuzzleTransform = FTransform(MuzzleRotation, MuzzleLocation, BulletScale);
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Instigator = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		SpawnParameters.Owner = this;
		
		ABullet* Bullet = GetWorld()->SpawnActor<ABullet>(BulletClass, MuzzleTransform, SpawnParameters);
		Bullet->Damage = BulletDamage;

		--CurrentAmmo;
		AmmoText->SetText(FText::FromString(FString::FromInt(CurrentAmmo)));
	}
}

void AGun::Reload()
{
	CurrentAmmo = DefaultAmmo;
	AmmoText->SetText(FText::FromString(FString::FromInt(CurrentAmmo)));
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = DefaultAmmo;
	AmmoText->SetText(FText::FromString(FString::FromInt(CurrentAmmo)));
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

