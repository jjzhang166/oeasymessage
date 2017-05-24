#include "oeasysms.h"
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QPropertyAnimation>
#include <QApplication>
#include <QLabel>
OEasySMS::OEasySMS(const QString & msg, SMSTYPE type, QWidget *parent) : QWidget(parent)
{
    icoLabel_ = new QLabel(this);
    messageLabel_ = new QLabel(this);

    messageLabel_->setText(msg);

    setIcon(type);


    QRect parent_rect;

    /// 设置位置 (set pos)
    if (parent == nullptr)
        parent_rect = QApplication::desktop()->availableGeometry();
    else
        parent_rect = parent->rect();

    startx_ = parent_rect.width();
    starty_ = parent_rect.height() / 4 * 3 ;
    endy_ = parent_rect.width() - width();
}

void OEasySMS::build()
{
    QPropertyAnimation *animation= new QPropertyAnimation(this,"pos");
    animation->setDuration(500);
    animation->setStartValue(QPoint(startx_, starty_));
    animation->setEndValue(QPoint(startx_, endy_));
    animation->setEasingCurve(QEasingCurve::OutCubic);

    connect(animation, SIGNAL(finished()),
            this, SLOT(animationFinished()));
    show();
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void OEasySMS::setIcon(OEasySMS::SMSTYPE type)
{
    QString icoStyle = " QLabel{\
                    border-image: url(%1);\
                    }";


    switch (type) {
    case Emergency:
        icoStyle.arg(":ico/msg/emergency");
        break;
    case Simple:
        icoStyle.arg(":ico/msg/briefmsg");
        break;
    case Prompt:
        icoStyle.arg(":ico/msg/prompt");
        break;
    }
}

void OEasySMS::onClose()
{

}

void OEasySMS::animationFinished()
{

}
