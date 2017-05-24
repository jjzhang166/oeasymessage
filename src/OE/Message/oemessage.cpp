#include "oemessage.h"
#include "oeprompt.h"
#include "oewebnotice.h"
#include "oesms.h"
OEMessage::OEMessage(QObject *parent) : QObject(parent) {
}



void OEMessage::BriefMessage(QWidget *parent, const QString &message,
                                int w, int h, const QString &style) {
    OEPrompt* prompt = new OEPrompt(parent, message, w, h, style);
    prompt->build();
}


void OEMessage::NetWorkWebNotice(const QString &title,
                    const QString &content,const QString &url) {
    new OEWebNotice(title, content, url);

}

void OEMessage::SMS(const QString &msg, OEMessage::SMSTYPE type, QWidget *parent) {
    OESms* sms = new OESms(msg,(OESms::TYPE)type,parent);
    sms->build();
}
