// Fill out your copyright notice in the Description page of Project Settings.

#include "Su.h"
#include "JumpPad.h"


// Sets default values
AJumpPad::AJumpPad()
{
 	
	
	PrimaryActorTick.bCanEverTick = true;
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;
	box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SM->AttachToComponent(root,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	box->bGenerateOverlapEvents = true;
	box->SetWorldScale3D(FVector(1, 1, 1));
	box->OnComponentBeginOverlap.AddDynamic(this, &AJumpPad::OnBeginOverlap);
	jumpSound = CreateDefaultSubobject<UAudioComponent>(TEXT("JUMpSound"));
	jumpSound->AttachTo(root);
	part = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PARTICLE"));
	
}

// Called when the game starts or when spawned
void AJumpPad::BeginPlay()
{
	Super::BeginPlay();
	jumpSound->Deactivate();//deactivate sound onstart
	part->DeactivateSystem();//deactivate particles onstart
}

// Called every frame
void AJumpPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		
	
}

void AJumpPad::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp,class AActor * OtherActor,class UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Green,TEXT(""));//debug message
	
	
	ACharacter* character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);//init character
	
	
	character->LaunchCharacter(FVector(0.f,0.f,3000.f),NULL,NULL);//launch actor
	
	jumpSound->Activate();//activate Sound
	
	
	

	part->ActivateSystem();//activate particles

}

void AJumpPad::OnEndOverlap(class UPrimitiveComponent* OverlappedComp,AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{	
	
	part->DeactivateSystem();//deactivate particles after jump
}

