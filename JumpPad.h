// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "SuCharacter.h"
#include "JumpPad.generated.h"


UCLASS()
class SU_API AJumpPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJumpPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
		USceneComponent* root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM;
	UPROPERTY(EditAnywhere)
		UShapeComponent* box;
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* part;
	UPROPERTY(EditAnywhere)
		UAudioComponent* jumpSound;
	int count;

	
	
	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
