#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "banknotes.h"


class Withdraw
{
public:
    Withdraw();
    QMap<int, int> getWithdraw(Banknotes *banknotes, int sum);
};

#endif // WITHDRAW_H
