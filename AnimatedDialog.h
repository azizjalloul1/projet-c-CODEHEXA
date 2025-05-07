#ifndef ANIMATEDDIALOG_H
#define ANIMATEDDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

class AnimatedDialog : public QDialog {
    Q_OBJECT
public:
    explicit AnimatedDialog(const QString& title, const QString& message, QWidget* parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle(title);
        setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);

        // Main layout
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->setContentsMargins(20, 20, 20, 20);

        // Shadow effect
        QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(this);
        shadow->setBlurRadius(15);
        shadow->setOffset(0, 5);
        setGraphicsEffect(shadow);

        // Message label
        QLabel* label = new QLabel(message);
        label->setStyleSheet("font-size: 16px; font-weight: bold; color: #333;");
        label->setWordWrap(true);
        layout->addWidget(label, 0, Qt::AlignCenter);

        // OK button
        QPushButton* okButton = new QPushButton("OK");
        okButton->setStyleSheet("QPushButton { background-color: #0078D7; color: white; padding: 8px 16px; border-radius: 8px; }"
                                "QPushButton:hover { background-color: #005a9e; }");
        connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
        layout->addWidget(okButton, 0, Qt::AlignCenter);

        // Background style
        setStyleSheet("QDialog { background-color: white; border-radius: 12px; }");

        // Animation
        QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
        animation->setDuration(500);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
};
#endif // ANIMATEDDIALOG_H
