#include "SpawnManager.h"

ASpawnManager::ASpawnManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < SpawnCount; i++)
	{
		int RandomIndex = FMath::RandRange(0, SpawnList.Num() - 1);
		FVector RandomLocation = GetActorLocation() + FVector(FMath::RandRange(-500, 500), FMath::RandRange(-500, 500), FMath::RandRange(100, 300));
		GetWorld()->SpawnActor<AActor>(SpawnList[RandomIndex], RandomLocation, FRotator::ZeroRotator);
	}
	
}

void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

