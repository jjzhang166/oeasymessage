#include "oeasywebnotice.h"



#include <QDesktopServices>
#include <QPushButton>
#include <QLabel>
#include <QUrl>
#include <QPropertyAnimation>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif




QString OEasyWebNotice::closeStyle_ = " \
        QPushButton{\
            color : black;\
            background-color: transparent;\
        }\
        QPushButton:hover {\
            color : white;\
            background: rgb(216, 64, 39);\
        }\
        QPushButton:pressed {\
            color : white;\
            background: rgb(166, 44, 21);\
        }\
        ";

QString OEasyWebNotice::urlStyle_ = " \
        QPushButton{\
            color : black;\
            background-color: transparent;\
        }\
        QPushButton:hover {\
            color : white;\
        background: rgb(1, 136, 251);\
        }\
        QPushButton:pressed {\
            color : white;\
            background: rgb(111, 156, 255);\
        }\
        ";

QString OEasyWebNotice::titleStyle_ = " \
        QLabel { \
        font-size: 18px;\
        \
        }";
QString OEasyWebNotice::contentStyle_ = " \
        QLabel { \
        font-size: 14px;\
        \
        }";



OEasyWebNotice::OEasyWebNotice(const QString &title, const QString &content, const QString &url)
    : QWidget(), url_(url),
    contentLabel_(new QLabel(this)), titleLabel_(new QLabel(this)),
    closeButton_(new QPushButton(titleLabel_.get())), urlButton_(new QPushButton(this)) {

    /// 窗口置顶
    Qt::WindowFlags flags = windowFlags();
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);

    /// 设置窗口规格
    setFixedSize(350,200);

    /// 去掉系统标题栏
    Qt::WindowFlags flag = windowFlags();
    setWindowFlags(flag | Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);

    /// 设置自定义标题
    titleLabel_->setStyleSheet(titleStyle_);
    titleLabel_->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    QString elided_text = fontMetrics().elidedText("  " + title, Qt::ElideRight,
                                                   width() - 30 - (width() / 3), Qt::TextShowMnemonic);
    titleLabel_->setText(elided_text);
    titleLabel_->setFixedSize(width(), 40);

    /// 内容
    contentLabel_->setStyleSheet(contentStyle_);
    contentLabel_->setWordWrap(true);
    contentLabel_->setAlignment(Qt::AlignTop);
    elided_text = fontMetrics().elidedText("    " + content, Qt::ElideRight,
                                            width() * 6, Qt::TextShowMnemonic);
    contentLabel_->setText(elided_text);
    contentLabel_->setFixedSize(width() - 30,height());
    contentLabel_->move(15, 40);

    /// 关闭按钮
    closeButton_->setFixedSize(30,30);
    closeButton_->setStyleSheet(closeStyle_);
    closeButton_->setText("X");
    closeButton_->move(titleLabel_->width()- closeButton_->width() -2,
                       (titleLabel_->height() - closeButton_->height()) >> 1);
    closeButton_->raise();
    connect(closeButton_.get(),SIGNAL(clicked()),
            this, SLOT(deleteLater()));

    /// Web 查看按钮
    urlButton_->setFixedSize(60,30);
    urlButton_->setStyleSheet(urlStyle_);
    urlButton_->setText(QStringLiteral("查看(look)"));
    urlButton_->move(width()- urlButton_->width() -2,
                     height() - urlButton_->height() -2);
    urlButton_->raise();
    connect(urlButton_.get(), SIGNAL(clicked()),
            this, SLOT(openUrl()));
    onShow();
}


void OEasyWebNotice::onShow() {
    QRect rect = QApplication::desktop()->availableGeometry();
    const int &endy = rect.height() - height();
    QPropertyAnimation *animation= new QPropertyAnimation(this,"pos");
    animation->setDuration(2000);
    animation->setStartValue(QPoint(rect.width() - width(), rect.height()));
    animation->setEndValue(QPoint(rect.width() - width(), endy));
    animation->setEasingCurve(QEasingCurve::OutCubic);

    connect(animation, SIGNAL(finished()),
            this, SLOT(animationFinished()));
    show();
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void OEasyWebNotice::animationFinished(void) {
    QTimer::singleShot(10000, this, SLOT(onClose()));
}

void OEasyWebNotice::openUrl(void) {
    QDesktopServices::openUrl(QUrl(url_));
    emit WebNoticeUrlOpen(url_);
    delete this;
}

void OEasyWebNotice::onClose(void) {
    disconnect(closeButton_.get(),SIGNAL(clicked()),
            this, SLOT(onClose()));

    QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InCirc);
    connect(animation, SIGNAL(finished()),
            this, SLOT(deleteLater()));
    show();
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
