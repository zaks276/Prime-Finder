#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <QObject>

class PrimeFinder : public QObject
{
    Q_OBJECT
public:
    PrimeFinder(int s, int e, int c);

public slots:
    void findPrimeNum();

signals:
    void primeFound(int p, int c);
    void workDone();

private:
    bool isPrime(int n);
    int start;
    int end;
    int currentThread;
};

#endif // PRIMEFINDER_H
