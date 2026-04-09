#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

UCLASS()
class CH3_06_PROJECT_API ASpawnManager : public AActor
{

	GENERATED_BODY()
	
public:	
	ASpawnManager();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<TSubclassOf<AActor>> SpawnList;


	UPROPERTY(EditAnywhere, Category = "Spawn")
	int SpawnCount;


public:	
	virtual void Tick(float DeltaTime) override;

};
