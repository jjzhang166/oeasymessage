#ifndef OEASYSMS_H
#define OEASYSMS_H

#include <QWidget>

class QLabel;

// Short Messaging 简讯
class OEasySMS : public QWidget
{
    Q_OBJECT
public:

    enum SMSTYPE {
        Emergency = 0,
        Simple = 1,
        Prompt
    };


    explicit OEasySMS(const QString & msg, SMSTYPE type = Emergency, QWidget *parent = 0);

    /// 构建窗口
    void build(void);

    /// 设置信息类型
    void setIcon(SMSTYPE type);

signals:

    /// 拒绝这个简讯
    void reject(void);

    /// 接受这个简讯
    void accept(void);

public slots:

    /// 关闭窗口
    void onClose(void);

private slots:

    void animationFinished(void);
private:

private:

    QLabel* icoLabel_;
    QLabel* messageLabel_;

    int startx_;
    int starty_;
    int endy_;


};

#endif // OEASYSMS_H
