#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Star_Floor.generated.h"

UCLASS()
class CH3_06_PROJECT_API AStar_Floor : public AActor
{
	GENERATED_BODY()
	
public:
	AStar_Floor();

protected:
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Star_Floor|Property")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star_Floor|Property")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Star_Floor|Property")
	float MaxRange;

	FTimerHandle DestroyTimeHandle;

public:
	virtual void Tick(float DeltaTime) override;
	void DestroyStar_Floor();
};
