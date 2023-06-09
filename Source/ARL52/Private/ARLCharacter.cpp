// Fill out your copyright notice in the Description page of Project Settings.


#include "ARLCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AARLCharacter::AARLCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a springarm component and attaches it to the character for a third person view
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AARLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AARLCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called every frame
void AARLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Binds an action to move the player character forward
	PlayerInputComponent->BindAxis("MoveForward", this, &AARLCharacter::MoveForward);

	// Binds an action to turn the character
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

}

