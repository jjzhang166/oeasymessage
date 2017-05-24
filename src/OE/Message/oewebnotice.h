#ifndef OEASYWEBNOTICE_H
#define OEASYWEBNOTICE_H
#include <memory>
#include <QWidget>

class QPushButton;
class QLabel;

class OEWebNotice : public QWidget
{
    Q_OBJECT

signals:

    /**
    * @brief : 网页被用户打开
    * @param : 被打开的Url地址
    */
    void WebNoticeUrlOpen(QString url);

public:
    /**
    * @brief : 右下角划出新闻类信息
    * @param : title 标题信息
    * @param : content 消息纲要,支持富文本。
    * @param : url 详情的网页链接
    */
    explicit OEWebNotice(const QString &title = QString(),
                 const QString &content = QString(),const QString &url = QString());


    ///// ui /////
    static void setCloseStyle(const QString &style) {
        closeStyle_ = style;
    }

    static void setUrlStyle(const QString &style) {
        urlStyle_ = style;
    }
    static void setTitleStyle(const QString &style) {
        titleStyle_ = style;
    }
    static void setContentStyle(const QString &style) {
        contentStyle_ = style;
    }

public slots:

    /**
    * @brief : 窗口展示
    */
    virtual void onShow(void);

    /**
    * @brief : 窗口关闭
    */
    virtual void onClose(void);


private slots:

    /**
    * @brief : 展示动画已经完成
    */
    void animationFinished(void);

    /**
    * @brief : 使用默认浏览器打开网站
    */
    void openUrl(void);


private:
    QString url_;
    static QString closeStyle_;
    static QString urlStyle_;
    static QString titleStyle_;
    static QString contentStyle_;
    std::shared_ptr<QLabel> contentLabel_;
    std::shared_ptr<QLabel> titleLabel_;
    std::shared_ptr<QPushButton> closeButton_;
    std::shared_ptr<QPushButton> urlButton_;
    QPoint endPoint_;
};

#endif // OEASYWEBNOTICE_H
