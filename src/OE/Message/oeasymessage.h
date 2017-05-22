#ifndef OEASYMESSAGE_H
#define OEASYMESSAGE_H

#include <QObject>

class OEasyMessage : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief �Զ���ʧ��ʾ��
     * @param parent ָ��������
     * @param message ��Ҫ��ʾ����Ϣ
     * @param w ��
     * @param h ��
     * @param style ��ʾ����ʽ��ע�������С�Ϳ��Ч��Ҫ��Ϻ�
     */
    static void BriefMessage(QWidget *parent, const QString &message = QString(),
                          int w = 200, int h = 25, const QString &style = QString());



signals:

public slots:

private:

    explicit OEasyMessage(QObject *parent = 0);
};

#endif // OEASYMESSAGE_H
