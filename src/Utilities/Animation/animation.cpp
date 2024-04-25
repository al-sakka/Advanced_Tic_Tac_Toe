#include "../../../includes/Utilities/Animation/animation.h"


// Function to create a fade animation for a widget
void createFadeAnimation(QWidget* widget, bool fadeIn)
{
    // Create an opacity effect
    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(widget);
    widget->setGraphicsEffect(opacityEffect);

    // Create a property animation to animate the opacity
    QPropertyAnimation *animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(500); // Duration in milliseconds

    if (fadeIn) {
        animation->setStartValue(0.0); // Start from fully transparent
        animation->setEndValue(1.0);   // End at fully opaque
    } else {
        animation->setStartValue(1.0); // Start from fully opaque
        animation->setEndValue(0.0);   // End at fully transparent
    }

    // Start the animation
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
