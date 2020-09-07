#include "banknotes.h"

Banknotes::Banknotes()
{
    this->banknotesMap[10] = 600;
    this->banknotesMap[20] = 500;
    this->banknotesMap[50] = 400;
    this->banknotesMap[100] = 300;
}

void Banknotes::setBanknotes(QMap<int, int> banknotesMap)
{
    this->banknotesMap[10] += banknotesMap[10];
    this->banknotesMap[20] += banknotesMap[20];
    this->banknotesMap[50] += banknotesMap[50];
    this->banknotesMap[100] += banknotesMap[100];
}

QMap<int, int> Banknotes::getBanknotes()
{
    return this->banknotesMap;
}

int Banknotes::getTotal()
{
    int total = this->banknotesMap[10] * 10 + this->banknotesMap[20] * 20 + this->banknotesMap[50] * 50 + this->banknotesMap[100] * 100;

    return total;
}

void Banknotes::takeBanknote(int which)
{
    if (this->banknotesMap[which] > 0) {
        this->banknotesMap[which]--;
    }
}
