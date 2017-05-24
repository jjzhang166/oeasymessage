#ifndef OEASYMESSAGE_H
#define OEASYMESSAGE_H

#include <QObject>


class OEMessage : public QObject
{
    Q_OBJECT
public:
    enum SMSTYPE {
        Default = 0,
        Emergency = 1,
        Simple,
        Prompt
    };

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


    /**
    * @brief : 右下角划出新闻类信息
    * @param : title 标题信息
    * @param : content 消息纲要,支持富文本。
    * @param : url 详情的网页链接
    */
    static void NetWorkWebNotice(const QString &title, const QString &content,
                                 const QString &url);


    static void SMS(const QString & msg, SMSTYPE type = Default, QWidget *parent = 0);
signals:

public slots:

private:

    explicit OEMessage(QObject *parent = 0);
};

#endif // OEASYMESSAGE_H
