// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

UCLASS()
class PROJECT_UNREAL_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostInitializeComponents() override;

private:
	// 언리얼 자체에서 관리하는 함수는 UFUNCTION()	붙여야 함
	UFUNCTION()
	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Door;

	//UPROPERTY(VisibleAnywhere)
	//UStaticMeshComponent* DoorFrame;
	
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* Trigger;

	//UPROPERTY(VisibleAnywhere)
	//class USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	bool IsUnrock = true;
};
