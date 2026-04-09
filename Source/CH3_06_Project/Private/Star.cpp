#include "Star.h"

AStar::AStar()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	RotationSpeed = FMath::RandRange(50.0f, 200.0f);
	MoveTime = FMath::RandRange(2.0f, 10.0f);
}

void AStar::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(MoveTimerHandle, this, &AStar::TeleportToRandomLocation, MoveTime, true);
	
}

void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Spin(DeltaTime);

}

void AStar::Spin(float DeltaTime)
{
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void AStar::TeleportToRandomLocation()
{
	FVector CurrentLocation = GetActorLocation();
	FVector RandomOffset(FMath::RandRange(-100.f, 100.f), FMath::RandRange(-100.f, 100.f), 0.0f);

	SetActorLocation(CurrentLocation + RandomOffset);
}