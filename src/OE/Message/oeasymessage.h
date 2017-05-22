#ifndef OEASYMESSAGE_H
#define OEASYMESSAGE_H

#include <QObject>

class OEasyMessage : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief 自动消失提示框
     * @param parent 指名父窗口
     * @param message 所要提示的消息
     * @param w 宽
     * @param h 高
     * @param style 提示框样式：注意字体大小和宽高效果要配合好
     */
    static void BriefMessage(QWidget *parent, const QString &message = QString(),
                          int w = 200, int h = 25, const QString &style = QString());



signals:

public slots:

private:

    explicit OEasyMessage(QObject *parent = 0);
};

#endif // OEASYMESSAGE_H
