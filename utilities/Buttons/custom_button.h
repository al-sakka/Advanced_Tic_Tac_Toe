#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <QPushButton>

class Custom_Button : public QPushButton
{

    Q_OBJECT

public:
    explicit Custom_Button(const QString &text, QWidget *parent = nullptr);
    ~Custom_Button();

private slots:
    void handlePressed();
    void handleReleased();

private:
    void setPressedEffect(bool enabled);
};

#endif // CUSTOM_BUTTON_H
