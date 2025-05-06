#ifndef CUSTOMCOMBOBOX_H
#define CUSTOMCOMBOBOX_H
#include <QComboBox>

class CustomComboBox : public QComboBox
{
    Q_OBJECT

public:
    using QComboBox::QComboBox;

protected:
    void showPopup() override {
        QComboBox::showPopup(); // Appelle le comportement standard
        emit popupShown();      // Émet ton signal
    }

signals:
    void popupShown();
};

#endif // CUSTOMCOMBOBOX_H
