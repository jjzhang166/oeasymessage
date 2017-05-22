#include "commonhelper.h"

#include <QFile>
#include <QTranslator>
#include <QApplication>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QDesktopWidget>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

void CommonHelper::setStyle(const QString &style) {
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

void CommonHelper::setLanguagePack(const QString &language) {
    // 加载中文包
    QTranslator translator;
    translator.load(language);
    qApp->installTranslator(&translator);
}

void CommonHelper::moveCenter(QWidget *widget, QRect parentRect) {
    if (parentRect.isEmpty()) {
        parentRect = QRect(QApplication::desktop()->pos(),
              QApplication::desktop()->size());
    }
    qDebug() << parentRect;
    widget->move (((parentRect.width() + parentRect.x() - widget->width()) >> 1),
          ((parentRect.height() - widget->height()) >> 1));
}

void CommonHelper::setShadow(QWidget *w, qreal blurRadius, qreal dx, qreal dy) {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(blurRadius);
    shadow->setColor(QColor(0, 0, 0, 160));
    shadow->setOffset(dx, dy);
    w->setGraphicsEffect(shadow);
}
