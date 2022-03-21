#include "findprimes.h"
#include "ui_findprimes.h"

FindPrimes::FindPrimes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindPrimes)
{
    ui->setupUi(this);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startClicked()));

}

FindPrimes::~FindPrimes()
{
    delete ui;
}

void FindPrimes::startClicked()
{
    ui->startButton->setDisabled(true);
    ui->thread1TextEdit->clear();
    ui->thread2TextEdit->clear();
    ui->thread3TextEdit->clear();
    ui->thread4TextEdit->clear();

    int noOfThreads = ui->threadSpinBox->value();
    int start = ui->startSpinBox->value();
    int end = ui->endSpinBox->value();
    threadDone = noOfThreads;
    int segments = end/noOfThreads;

    for(int i = 0; i < noOfThreads; i++)
    {
        int currentStart = start + (segments * i);
        int currentEnd = start + segments + (segments * i);

        QThread* thread = new QThread;
        PrimeFinder* worker = new PrimeFinder(currentStart, currentEnd, i);

        worker->moveToThread(thread);

        connect(thread, SIGNAL(started()), worker, SLOT(findPrimeNum()));
        connect(worker, SIGNAL(workDone()), thread, SLOT(quit()));
        connect(worker, SIGNAL(workDone()), worker, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        connect(worker, SIGNAL(primeFound(int,int)), this, SLOT(printPrimes(int,int)));

        thread->start();
        --threadDone;

    }
    if(threadDone == 0){
        ui->startButton->setEnabled(true);
    }
}

void FindPrimes::printPrimes(int p, int t)
{
    if(t == 1)
        ui->thread1TextEdit->append(QString::number(p));
    else if(t == 2)
        ui->thread2TextEdit->append(QString::number(p));
    else if(t == 3)
        ui->thread3TextEdit->append(QString::number(p));
    else if(t == 4)
        ui->thread4TextEdit->append(QString::number(p));
}

void FindPrimes::closeEvent(QCloseEvent *event){
    if(threadDone != 0)
    {
        bool alert = QMessageBox::information(this, "Alert", "Are you sure you want to quit?", QMessageBox::Yes | QMessageBox::No);
        if(alert == true)
            event->accept();
        else
            event->ignore();
    }
}


