#include "oe.h"
#include <QPushButton>
#include <QTimer>


#include "OE/OEasyMessage"
#include "OE/Message/ax/commonhelper.h"

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

OE::OE(QWidget *parent)
    : QWidget(parent) {
    setGeometry(0,0,300,300);
#ifdef COMMONHELPER_H
    CommonHelper::moveCenter(this);
#endif

    /// @info : BriefMessage:
    promptBtn_ = new QPushButton(this);
    promptBtn_->setText("BriefMessage（OE - Prompt）");
    connect(promptBtn_,SIGNAL(pressed()),
            this,SLOT(onBriefSlot()));

}

OE::~OE(void) {

}

void OE::onBriefSlot(void) {
    if (promptBtn_->isDown()) {
        OEasyMessage::BriefMessage(this,
                    QString::number(rand()) + "撒暗示的撒暗示的撒暗示撒暗示的撒暗示的撒暗示1",
                                   rand()%200+150);

        QTimer::singleShot(100, this,
                    SLOT(onBriefSlot()));
    }
}

