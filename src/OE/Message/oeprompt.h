#ifndef OEPROMPT_H
#define OEPROMPT_H

#include <QLabel>


class OEPrompt : public QLabel
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
    explicit OEPrompt(QWidget *parent, const QString &message = QString(),
                   int w = 200, int h = 25, const QString &style = QString());
    ~OEPrompt(void);

    /**
     * @brief 弹出提示
     */
    void build(void);

public slots:

    void onClose(void);

protected:

    void mousePressEvent(QMouseEvent *e);

private slots:

    void animationFinished(void);


private:

    int startx_;
    int starty_;
    int endy_;
    static int count_;
    bool first_;

};

#endif // OEPROMPT_H
