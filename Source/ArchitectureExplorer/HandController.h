// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "HandController.generated.h"

UCLASS()
class ARCHITECTUREEXPLORER_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHandController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetHand(EControllerHand Hand) { 
		MotionController->SetTrackingSource(Hand); 
		MotionController->SetShowDeviceModel(true);
	}

	void PairController(AHandController* Controller);

	void Grip();
	void Release();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	// Callbacks

	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
	void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

	// Helpers

	bool CanClimb() const;

	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

	UPROPERTY(EditDefaultsOnly)
	class UHapticFeedbackEffect_Base* HapticEffect;

	bool bCanClimb = false;

	bool bIsClimbing = false;

	FVector ClimbingStartLocation;

	AHandController* OtherController;
	
};
