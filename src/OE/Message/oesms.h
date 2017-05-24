#ifndef OEASYSMS_H
#define OEASYSMS_H

#include <QWidget>

class QLabel;

// Short Messaging 简讯
class OESms : public QWidget
{
    Q_OBJECT
public:

    enum TYPE {
        Default = 0,
        Emergency = 1,
        Simple,
        Prompt
    };


    explicit OESms(const QString & msg, OESms::TYPE type = Default, QWidget *parent = 0);

    /// 构建窗口
    void build(void);

    /// 设置信息类型
    void setIcon(TYPE type);

signals:

    /// 拒绝这个简讯
    void reject(void);

    /// 接受这个简讯
    void accept(void);

public slots:


private slots:

    void animationFinished(void);
private:

private:

    QLabel* icoLabel_;
    QLabel* messageLabel_;

    int startx_;
    int starty_;
    int endx_;


};

#endif // OEASYSMS_H
