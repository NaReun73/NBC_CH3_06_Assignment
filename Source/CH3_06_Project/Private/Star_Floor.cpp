#include "Star_Floor.h"

AStar_Floor::AStar_Floor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	StartLocation = GetActorLocation();
	MoveSpeed = FMath::RandRange(50.0f, 200.0f);
	MaxRange = FMath::RandRange(300.0f, 900.0f);
}

void AStar_Floor::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0.0f, 0.0f, 90.0f));
	GetWorld()->GetTimerManager().SetTimer(DestroyTimeHandle, this, &AStar_Floor::DestroyStar_Floor, 10.0f, false);
	
}

void AStar_Floor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FVector::Dist(StartLocation, GetActorLocation()) <= MaxRange)
	{
		AddActorLocalOffset(FVector(0.0f, 0.0f, MoveSpeed * DeltaTime), true);
	}
	else
	{
		StartLocation = GetActorLocation();
		MoveSpeed *= -1;
	}

}

void AStar_Floor::DestroyStar_Floor()
{
	Destroy();
}