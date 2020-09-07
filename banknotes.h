#ifndef BANKNOTES_H
#define BANKNOTES_H

#include <QMap>
#include <QObject>

class Banknotes
{
public:
    Banknotes();
    void setBanknotes(QMap<int, int> banknotesMap);
    QMap<int, int> getBanknotes();
    int getTotal();
    void takeBanknote(int which);

private:
    QMap<int, int> banknotesMap;
};

#endif // BANKNOTES_H
