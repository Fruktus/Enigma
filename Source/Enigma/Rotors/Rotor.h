// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Helpers/EnigmaLetter.h"
#include "RotorsTypes.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rotor.generated.h"

UCLASS()
class ENIGMA_API ARotor : public AActor
{
	GENERATED_BODY()

private:
	static const int MAX_OFFSET = 25;
	int offset = 0;
	float stepDegree = 360.0/26;

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	EPossibleRotors rotorType;

private:
	std::string getRotor();
	int withOverflow(int val);
	int withUnderflow(int val);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ARotor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int getOutputIndex(int16 index);
	int getReversedOutputIndex(int16 index);

	void increaseOffset(bool applyOffset = false);
	void setOffset(int offset);

	UFUNCTION(BlueprintCallable)
	int getOffset();

	UFUNCTION(BlueprintImplementableEvent)
	void animateNewOffset(float rotation);
};
