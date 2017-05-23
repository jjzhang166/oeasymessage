#ifndef OEASYSMS_H
#define OEASYSMS_H

#include <QWidget>

// Short Messaging ��Ѷ
class OEasySMS : public QWidget
{
    Q_OBJECT
public:
    explicit OEasySMS(QWidget *parent = 0);

    /// ��������
    void build(void);

signals:

    /// �ܾ������Ѷ
    void reject(void);

    /// ���������Ѷ
    void accept(void);

public slots:

    /// �رմ���
    void onClose(void);

};

#endif // OEASYSMS_H
