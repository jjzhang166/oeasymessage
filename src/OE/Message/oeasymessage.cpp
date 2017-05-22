#include "oeasymessage.h"
#include "oeprompt.h"

OEasyMessage::OEasyMessage(QObject *parent) : QObject(parent) {
}



void OEasyMessage::BriefMessage(QWidget *parent, const QString &message,
                                int w, int h, const QString &style) {
    OEPrompt* prompt = new OEPrompt(parent, message, w, h, style);
    prompt->build();
}
