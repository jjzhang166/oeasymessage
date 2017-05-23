#ifndef OEASYSMS_H
#define OEASYSMS_H

#include <QWidget>

// Short Messaging 简讯
class OEasySMS : public QWidget
{
    Q_OBJECT
public:
    explicit OEasySMS(QWidget *parent = 0);

    /// 构建窗口
    void build(void);

signals:

    /// 拒绝这个简讯
    void reject(void);

    /// 接受这个简讯
    void accept(void);

public slots:

    /// 关闭窗口
    void onClose(void);

};

#endif // OEASYSMS_H
