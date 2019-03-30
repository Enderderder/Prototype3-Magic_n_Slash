// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionMoveObject.generated.h"

UCLASS()
class MAGIC_N_SLASH_API AInteractionMoveObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionMoveObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	FVector MoveToOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	TMap<class AInteractionMoveObject*, bool> InteractConditions;

	UPROPERTY(BlueprintReadWrite, Category = "Moving")
	bool ConditionsMet;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Moving")
	bool IsUseable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interact")
	bool InteractableIsActive;

	UPROPERTY(BlueprintReadWrite, Category = "Moving")
	bool IsActivated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
	float MoveTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MoveToOffsetPosition();
	UFUNCTION(BlueprintImplementableEvent, Category = "Moving", meta = (DisplayName = "OnMoveToOffsetPosition"))
	void Receive_MoveToOffsetPosition();

	UFUNCTION()
	void MoveToOriginalPosition();
	UFUNCTION(BlueprintImplementableEvent, Category = "Moving", meta = (DisplayName = "OnMoveToOriginPosition"))
	void Recieve_MoveToOriginalPosition();

	UFUNCTION(BlueprintCallable)
	void CheckIsActivated();
};