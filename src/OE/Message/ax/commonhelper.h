#ifndef COMMONHELPER_H
#define COMMONHELPER_H
#include <QString>
#include <QRect>

class QWidget;
class CommonHelper
{
public:
    /**
    * @brief : 设置QSS文件
    * @param : style 文件名
    * @author: 陈鲁勇
    * @date  : 2017年04月10日
    **/
    static void setStyle(const QString &style);
    /**
    * @brief : 设置语言包
    * @param : language 语言包的文件名
    * @author: 陈鲁勇
    * @date  : 2017年04月10日
    **/
    static void setLanguagePack(const QString& language);
    /**
    * @brief : 将窗口移动到中心
    * @param : widget 要移动的窗口
    * @param : parentRect 矩形几何数据
    * @author: 陈鲁勇
    * @date  : 2017年04月10日
    **/
    static void moveCenter(QWidget* widget, QRect parentRect = {});

    /**
     * @brief : setShadow 设置窗体阴影效果
     * @param : w 窗体指针
     * @param blurRadius 阴影清晰度，越小越清晰
     * @param dx x方向阴影位置和偏移量，正值在右方，值越大偏移越大
     * @param dy y方向阴影位置和偏移量，正值在下方，值越大偏移越大
     */
    static void setShadow(QWidget *w, qreal blurRadius = 10, qreal dx = 5, qreal dy = 5);

};

#endif // COMMONHELPER_H
