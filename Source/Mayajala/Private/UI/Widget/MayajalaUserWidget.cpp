// Copyright AshSlave


#include "UI/Widget/MayajalaUserWidget.h"

void UMayajalaUserWidget::SetWidgetController(UObject * InWidgetController)
{
    WidgetController = InWidgetController;
    WidgetControllerSet();
}