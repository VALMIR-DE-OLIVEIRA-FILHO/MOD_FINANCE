#ifndef FINANCESERVICE_H
#define FINANCESERVICE_H

#include "Lancamento.h"
#include <QList>
#include <QString>

class FinanceService {
public:
    FinanceService(const QString &filename);

    bool carregar(QList<Lancamento> &dest);
    bool salvar(const QList<Lancamento> &src);

    int proximoId(const QList<Lancamento> &lista);

private:
    QString filename;
};

#endif
