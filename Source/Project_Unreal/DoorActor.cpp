// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Components/BoxComponent.h"
#include "Project_UnrealCharacter.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DOOR"));	
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>DoorMesh(TEXT("StaticMesh'/Game/EF_FirstFloor/Shared/GenericPropsInterior/Door_a.Door_a'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>DoorMaterial(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (DoorMesh.Succeeded())
	{
		// Door에 StaticMesh 설정
		Door->SetStaticMesh(DoorMesh.Object);
		Door->SetMaterial(0, DoorMaterial.Object);

	}

	Door->SetWorldScale3D(FVector(1.25f, 1.25f, 1.25f));

	// Door을 RootComponent 아래에 붙이기
	// 계속 지가 루트되길래 루트 하나 따로 만들어 둠
	//DefaultSceneRoot->SetupAttachment(RootComponent);
	Door->SetupAttachment(RootComponent);

	//// Trigger를 Door 아래에 붙이기
	//Trigger->SetupAttachment(Door);

	//Door->SetCollisionProfileName(TEXT("MyCollectible"));
	//Trigger->SetCollisionProfileName(TEXT("MyCollectible"));

	//// Trigger 범위 지정
	//Trigger->SetBoxExtent(FVector(50.f, 50.f, 30.f));

	
}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//Trigger->OnComponentBeginOverlap.AddDynamic(this, &ADoorActor::OnCharacterOverlap);
}

void ADoorActor::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Cast : Casting을 하는데 잘못되었을 경우 Null로 반환
	AProject_UnrealCharacter* MyCharacter = Cast<AProject_UnrealCharacter>(OtherActor);

	if (MyCharacter) 
	{
		  	//FAttachmentTransformRules::SnapToTargetIncludingScale,
			//WeaponSoket);

		UE_LOG(LogTemp, Warning, TEXT("Tigger"));
		IsUnrock = false;
	}
}

