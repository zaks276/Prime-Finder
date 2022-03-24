#ifndef FINDPRIMES_H
#define FINDPRIMES_H

#include <QMainWindow>
#include "primefinder.h"
#include <QThread>
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class FindPrimes;
}

class FindPrimes : public QMainWindow
{
    Q_OBJECT

public:
    explicit FindPrimes(QWidget *parent = 0);
    ~FindPrimes();
    void closeEvent(QCloseEvent *);
public slots:
    void startClicked();
    void printPrimes(int p, int t);


private:
    Ui::FindPrimes *ui;
    int threadDone = 0;
};

#endif // FINDPRIMES_H
