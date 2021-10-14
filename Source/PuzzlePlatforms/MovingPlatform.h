// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AddActiveTrigger();
	void RemoveActiveTrigger();
	
protected:

	/** Platform movement speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PlatformSpeed;

	/** Target location to move to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"))
	FVector TargetLocation;


private:

	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;

	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 1;
};
