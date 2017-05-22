#ifndef OE_H
#define OE_H

#include <QWidget>
class QPushButton;
class OE : public QWidget
{
    Q_OBJECT

public:
    OE(QWidget *parent = 0);
    ~OE();

public slots:
    void onBriefSlot(void);

private:

    QPushButton *promptBtn_;
};

#endif // OE_H
