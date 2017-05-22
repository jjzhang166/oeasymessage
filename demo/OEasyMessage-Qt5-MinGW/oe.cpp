#include "oe.h"
#include <QPushButton>
#include "OE/OEasyMessage"

OE::OE(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(333,333);
    QPushButton *promptBtn = new QPushButton(this);
    promptBtn->show();

    connect(promptBtn,SIGNAL(clicked()),
            this,SLOT(onBriefSlot()));
}

OE::~OE()
{

}

void OE::onBriefSlot()
{
    OEasyMessage::BriefMessage(this,QString::number(rand()));
}
