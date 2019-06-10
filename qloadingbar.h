#ifndef QLOADINGBAR_H
#define QLOADINGBAR_H

#include <QProgressBar>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class QLoadingBar : public QProgressBar, public QThread
{
    Q_OBJECT
public:
    explicit QLoadingBar(QWidget *parent = nullptr);
    void glideTo(int value, int timeSpan);

    void run();

signals:

public slots:

private:
    QMutex mutex;
    QWaitCondition cond;
    int refreshInterval;
    int targetValue;
};

#endif // QLOADINGBAR_H
