#include "oe.h"
#include <QPushButton>
#include <QTimer>
#include <QGridLayout>


#include "OE/OEasyMessage"
#include "OE/Message/ax/commonhelper.h"

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

#define AUTO_TEST

OE::OE(QWidget *parent)
    : QWidget(parent) {
    setGeometry(0,0,300,300);
#ifdef COMMONHELPER_H
    CommonHelper::moveCenter(this);
#endif

    QGridLayout* layout = new QGridLayout;

    /// @info : BriefMsg;
    promptBtn_ = new QPushButton();
    promptBtn_->setText("BriefMessage（OE - Prompt）");
    connect(promptBtn_,SIGNAL(pressed()),
            this,SLOT(onBriefSlot()));
    layout->addWidget(promptBtn_);


    /// @info : NetWebMsg;
    netwebmsg_ = new QPushButton();
    netwebmsg_->setText("NetWorkWebNotice（OE - WebNotice）");
    connect(netwebmsg_,SIGNAL(pressed()),
            this,SLOT(onNetWebSlot()));
    layout->addWidget(netwebmsg_);

    setLayout(layout);
}

OE::~OE(void) {

}
#include <QInputDialog>

void OE::onBriefSlot(void) {
#ifdef AUTO_TEST
    if (promptBtn_->isDown()) {
        OEasyMessage::BriefMessage(this,
                    QString::number(rand()) + "OEasyMessage is good!",
                                   rand()%200+150);

        QTimer::singleShot(100, this,
                    SLOT(onBriefSlot()));
    }
#else
    bool isOK;
    QString text = QInputDialog::getText(NULL, "Input Dialog",
                                        "Please input your content",
                                        QLineEdit::Normal,"OEasy is good!",
                                        &isOK);

    OEasyMessage::BriefMessage(this,text);
#endif
}

void OE::onNetWebSlot()
{
#ifdef AUTO_TEST
    if (netwebmsg_->isDown()) {
        QString str;
        for (int i = rand() % 255; i > 0; --i)
            str += QStringLiteral("OE | ");
        OEasyMessage::NetWorkWebNotice(str,str,"http://git.oschina.net/Mr_ChenLuYong");

        QTimer::singleShot(1000, this,
                    SLOT(onNetWebSlot()));
    }
#else
    bool isOK;
    QString title = QInputDialog::getText(NULL, "Input Dialog",
                                        QStringLiteral("请输入新闻标题"),
                                        QLineEdit::Normal, QStringLiteral("高潮来临，男女兴奋过度不知所措"),
                                        &isOK);

    QString content = QInputDialog::getText(NULL, "Input Dialog",
                                        QStringLiteral("请输入新闻简介"),
                                        QLineEdit::Normal,QStringLiteral("钱塘江涨潮，高潮来时，众皆惊呼壮观，对即将扑面而来的高潮，桥头年轻男女显然有点不知所措。"),
                                        &isOK);
    QString url = QInputDialog::getText(NULL, "Input Dialog",
                                        "Please input your url",
                                        QLineEdit::Normal,"http://git.oschina.net/Mr_ChenLuYong/oeasymessage",
                                        &isOK);
    OEasyMessage::NetWorkWebNotice(title,content,url);
#endif
}

