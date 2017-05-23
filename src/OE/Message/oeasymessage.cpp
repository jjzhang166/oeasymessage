#include "oeasymessage.h"
#include "oeprompt.h"
#include "oeasywebnotice.h"

OEasyMessage::OEasyMessage(QObject *parent) : QObject(parent) {
}



void OEasyMessage::BriefMessage(QWidget *parent, const QString &message,
                                int w, int h, const QString &style) {
    OEPrompt* prompt = new OEPrompt(parent, message, w, h, style);
    prompt->build();
}


void OEasyMessage::NetWorkWebNotice(const QString &title,
                    const QString &content,const QString &url) {
    new OEasyWebNotice(title, content, url);

}
