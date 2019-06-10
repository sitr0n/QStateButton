#include "qloadingbar.h"
#include <cstdlib>
#include <QDebug>

QLoadingBar::QLoadingBar(QWidget *parent)
    : QProgressBar(parent)
    , QThread(parent)
{

}

void QLoadingBar::glideTo(int value, int timeSpan)
{
    QMutexLocker locker(&mutex);
    targetValue = value;
    refreshInterval = timeSpan / std::abs((this->value() - targetValue));
    qDebug() << refreshInterval;
}

void QLoadingBar::run()
{

}
