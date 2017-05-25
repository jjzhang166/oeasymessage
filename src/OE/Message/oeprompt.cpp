#include "oeprompt.h"

#include "OE/Help/commonhelper.h"

#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QTimer>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

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
#include <QApplication>
#include <QDesktopWidget>
int OEPrompt::count_ = 0;

OEPrompt::OEPrompt(QWidget *parent, const QString &message,
             int w, int h, const QString &style):
    QLabel(parent), first_(++count_ == 10) {
    setFixedSize(w, h);
    if (w < fontMetrics().width(message))
        setAlignment(Qt::AlignLeft);
    else
        setAlignment(Qt::AlignCenter);

    QString elided_text = fontMetrics().elidedText(message, Qt::ElideRight,
                                          w - (w / 3), Qt::TextShowMnemonic);
    setText(elided_text);


    // 居中下方四分之三处
    QWidget* temp_parent = parent;
    if (temp_parent == nullptr) {
        temp_parent = QApplication::desktop();
        Qt::WindowFlags flags = windowFlags();
        flags |= Qt::FramelessWindowHint /*| Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint*/ | Qt::Tool;
        setWindowFlags(flags);
    }

    if (style.isEmpty())
        setStyleSheet(DEFULT_STYLE);
    else
        setStyleSheet(style);


    startx_ = (temp_parent->width() - width()) >> 1;
    starty_ = temp_parent->height();
    endy_ = ((temp_parent->height() * 7) >> 3) - (count_ * height());


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
