// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleCheckPoint.generated.h"

UCLASS()
class MAGIC_N_SLASH_API ASimpleCheckPoint : public AActor
{
	GENERATED_BODY()
	
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* EditorOnlyMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* CheckPointPlayerRespawnLocation;

public:	
	// Sets default values for this actor's properties
	ASimpleCheckPoint();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Instance Config")
	int32 CheckPointIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to get the transform of the respawn point
	FTransform GetRespawnTransform() const;




};
