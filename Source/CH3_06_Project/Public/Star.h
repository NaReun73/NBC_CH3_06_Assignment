#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star.generated.h"

UCLASS()
class CH3_06_PROJECT_API AStar : public AActor
{
	GENERATED_BODY()
	
public:	
	AStar();

protected:
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star|Properties")
	float RotationSpeed;

	void Spin(float DeltaTime);

	FTimerHandle MoveTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star|Properties")
	float MoveTime;

	void TeleportToRandomLocation();


public:	
	virtual void Tick(float DeltaTime) override;

};
