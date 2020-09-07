#include "withdraw.h"
#include "banknotes.h"

#include <QDebug>

Withdraw::Withdraw()
{
}

QMap<int, int> Withdraw::getWithdraw(Banknotes *banknotes, int sum)
{
    QMap<int, int> loadedBanknotes = banknotes->getBanknotes();
    QMap<int, int> givedBanknotes;
    givedBanknotes[10] = 0;
    givedBanknotes[20] = 0;
    givedBanknotes[50] = 0;
    givedBanknotes[100] = 0;
    
    if (sum == 0 || sum > banknotes->getTotal()) {
        return QMap<int, int>();
	}
    
    if (sum >= 100 && loadedBanknotes[100] > 0) {
        while (sum >= 100 && loadedBanknotes[100] > 0) {
            givedBanknotes[100]++;
            loadedBanknotes[100]--;
            sum -= 100;
            banknotes->takeBanknote(100);
        }
    }

    if (sum >= 50 && loadedBanknotes[50] > 0) {
        while (sum >= 50 && loadedBanknotes[50] > 0) {
            givedBanknotes[50]++;
            loadedBanknotes[50]--;
            sum -= 50;
            banknotes->takeBanknote(50);
        }
    }

    if (sum >= 20 && loadedBanknotes[20] > 0){
        while (sum >= 20 && loadedBanknotes[20] > 0) {
            givedBanknotes[20]++;
            loadedBanknotes[20]--;
            sum -= 20;
            banknotes->takeBanknote(20);
        }
    }

    if (sum >= 10 && loadedBanknotes[10] > 0) {
        while (sum >= 10 && loadedBanknotes[10] > 0) {
            givedBanknotes[10]++;
            loadedBanknotes[10]--;
            sum -= 10;
            banknotes->takeBanknote(10);
        }
    }

    if (sum != 0) {
        return QMap<int, int>();
    }

    return givedBanknotes;
}
