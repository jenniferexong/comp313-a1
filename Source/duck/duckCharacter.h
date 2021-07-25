// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DuckCharacter.generated.h"

UCLASS(config = Game)
class ADuckCharacter : public ACharacter
{
    GENERATED_BODY()

    /** Camera boom positioning the camera behind the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent *CameraBoom;

    /** Follow camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent *FollowCamera;

public:
    ADuckCharacter();

    /* Accessor for initial score */
    UFUNCTION(BlueprintPure, Category = "Score")
    int GetInitialScore();

    /* Accessor for current score */
    UFUNCTION(BlueprintPure, Category = "Score")
    int GetCurrentScore();

    /* Accessor for ducklings that died */
    UFUNCTION(BlueprintPure, Category = "Score")
    int GetDucklingsDead();

    /* Accessor for ducklings that grew up*/
    UFUNCTION(BlueprintPure, Category = "Score")
    int GetDucklingsGrown();

    /* Checks if the game is over */
    UFUNCTION(BlueprintPure, Category = "Score")
    bool IsGameOver();

    /** 
     * Increments number of ducklings died 
     */
    UFUNCTION(BlueprintCallable, Category = "Score")
    void SetDucklingDied();

    /** 
     * Increases death counts and decreases grown count
     */
    UFUNCTION(BlueprintCallable, Category = "Score")
    void SetFullyGrownDied();

    /** 
     * Increments number of ducklings that have grown up 
     */
    UFUNCTION(BlueprintCallable, Category = "Score")
    void SetDucklingGrown();

    /** 
     * Update player score 
     * @param score The amount to add to the current score
     */
    UFUNCTION(BlueprintCallable, Category = "Score")
    void UpdateScore(int score);

    /** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    float BaseTurnRate;

    /** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
    float BaseLookUpRate;

protected:
    /** Resets HMD orientation in VR. */
    void OnResetVR();

    /** Called for forwards/backward input */
    void MoveForward(float Value);

    /** Called for side to side input */
    void MoveRight(float Value);

    /** 
     * Called via input to turn at a given rate. 
     * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
     */
    void TurnAtRate(float Rate);

    /**
     * Called via input to turn look up/down at a given rate. 
     * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
     */
    void LookUpAtRate(float Rate);

    /** Handler for when a touch input begins. */
    void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

    /** Handler for when a touch input stops. */
    void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
    // End of APawn interface

private:
    UPROPERTY(EditAnywhere, Category = "Score")
    int InitialScore = 0;

    UPROPERTY(EditAnywhere, Category = "Score")
    int CurrentScore = 0;

    UPROPERTY(EditAnywhere, Category = "Score")
    int DucklingsDead = 0;

    UPROPERTY(EditAnywhere, Category = "Score")
    int DucklingsGrown = 0;

public:
    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent *GetCameraBoom() const { return CameraBoom; }
    /** Returns FollowCamera subobject **/
    FORCEINLINE class UCameraComponent *GetFollowCamera() const { return FollowCamera; }
};
