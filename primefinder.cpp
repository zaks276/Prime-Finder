#include "primefinder.h"

PrimeFinder::PrimeFinder(int s, int e, int c)
{
    start = s;
    end = e;
    currentThread = c + 1;
}

void PrimeFinder::findPrimeNum()
{
    for(int i = start; i < end; i++)
    {
        if(isPrime(i))
        {
            emit primeFound(i, currentThread);
        }

    }
    emit workDone();
}

bool PrimeFinder::isPrime(int n)
{
      if (n == 0 || n == 1)
          return false;
      else
      {
         for (int i = 2; i <= n / 2; ++i)
         {
             if (n % i == 0)
                 return false;

         }
      }
      return true;
}
