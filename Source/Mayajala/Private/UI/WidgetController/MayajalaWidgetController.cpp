// Copyright AshSlave


#include "UI/WidgetController/MayajalaWidgetController.h"

void UMayajalaWidgetController::SetWidgetControllerParams(const FWidgetControllerParams & WCParams)
{
    PlayerController = WCParams.PlayerController;
    PlayerState = WCParams.PlayerState;
    AbilitySystemComponent = WCParams.AbilitySystemComponent;
    AttributeSet = WCParams.AttributeSet;
}

void UMayajalaWidgetController::BroadcastInitialValues()
{
}

void UMayajalaWidgetController::BindCallbacksToDependencies()
{
}