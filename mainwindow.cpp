#include "mainwindow.h"
#include "qstatebutton.h"
#include "qloadingbar.h"
#include <QIcon>
#include <memory>
#include <QDebug>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    auto wrapper = new QWidget(this);
    auto button = new QStateButton(this);
    button->addState("Start", new QIcon());
    button->addState("Stop");
    button->addState("Pause");
    button->setMinimumSize(QSize(50,50));
    wrapper->setLayout(new QHBoxLayout);
    wrapper->layout()->addWidget(button);
    auto bar = new QLoadingBar(this);
    //    bar->glideTo(5, 5);
    //    wrapper->layout()->addWidget(bar);
    setCentralWidget(wrapper);

    connect(button, &QStateButton::state_change, this,
            [=](QString state){
        qDebug() << QString("Signal[%1]").arg(state);
    });
}

MainWindow::~MainWindow()
{

}
