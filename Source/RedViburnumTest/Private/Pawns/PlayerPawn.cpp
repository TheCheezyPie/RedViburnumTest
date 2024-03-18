// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/BoxComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Controllers/MainPlayerController.h"
#include "Weapons/ShootingComponent.h"

APlayerPawn::APlayerPawn() : Super()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->bUsePawnControlRotation = true;

	TurretMesh->SetupAttachment(CameraBoom);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

	bUseControllerRotationYaw = true;

	Tags.Add("Player");
}

void APlayerPawn::BeginPlay()
{
	MainPlayerController = Cast<AMainPlayerController>(GetController());

	Super::BeginPlay();

	if (MainPlayerController.IsValid())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(MainPlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
		EnhancedInputComponent->BindAction(MouseMoveAction, ETriggerEvent::Triggered, this, &APlayerPawn::LookAround);\

		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &APlayerPawn::Shoot);
	}
}

void APlayerPawn::Move(const FInputActionValue& Value)
{
	FVector MovementVector = Value.Get<FVector>();

	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
		AddMovementInput(FVector(0.f, 0.f, 1.f), MovementVector.Z);
	}
}

void APlayerPawn::LookAround(const FInputActionValue& Value)
{
	FVector2D MouseDelta = Value.Get<FVector2D>();

	AddControllerYawInput(MouseDelta.X);
	AddControllerPitchInput(MouseDelta.Y);
}

void APlayerPawn::InitializeComponents()
{
	if (ShootingComponent)
	{
		ShootingComponent->OnAmmoChanged.AddUObject(this, &APlayerPawn::AmmoChanged);
	}

	Super::InitializeComponents();
}

void APlayerPawn::HealthChanged(float NewPercent)
{
	if (MainPlayerController.IsValid())
	{
		MainPlayerController->UpdateHealth(NewPercent);
	}
}

void APlayerPawn::AmmoChanged(int32 NewAmmo)
{
	if (MainPlayerController.IsValid())
	{
		MainPlayerController->UpdateAmmo(NewAmmo);
	}
}
