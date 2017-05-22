#include "oeprompt.h"

#include "ax/commonhelper.h"

#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>

#define DEFULT_STYLE "\
QLabel{\
    color:#FFFFFF;\
    font:15px;\
    font-weight:500;\
    background-color:rgb(0,0,0,90);\
    padding:3px;\
    border-radius:5;\
}\
"

int OEPrompt::count_ = 0;


OEPrompt::OEPrompt(QWidget *parent, const QString &message,\
             int w, int h, const QString &style):
    QLabel(parent), first_(++count_ == 7) {

    setText(message);
    setFixedSize(w, h);
    setAlignment(Qt::AlignCenter);

    if (style.isEmpty())
        setStyleSheet(DEFULT_STYLE);
    else
        setStyleSheet(style);

    // 居中下方四分之三处
    startx_ = (parent->width() - width()) >> 1;
    starty_ = parent->height();
    endy_ = ((parent->height() * 3) >> 2) - (count_ * height());

#ifdef COMMONHELPER_H
    /// 阴影背景
    CommonHelper::setShadow(this);
#endif
}

OEPrompt::~OEPrompt() {
    if (first_)
        count_ = 0;

}

void OEPrompt::build(void) {
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

void OEPrompt::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton)
        onClose();
}

void OEPrompt::animationFinished(void) {
    QTimer::singleShot(2000, this, SLOT(onClose()));
}

void OEPrompt::onClose(void) {
    delete this;
}
