#include "FinanceService.h"
#include <QFile>
#include <QTextStream>

FinanceService::FinanceService(const QString &file)
    : filename(file) {}

bool FinanceService::carregar(QList<Lancamento> &lista) {
    QFile f(filename);
    lista.clear();

    if (!f.open(QFile::ReadOnly | QFile::Text))
        return false;

    QTextStream ts(&f);
    while (!ts.atEnd()) {
        QString line = ts.readLine().trimmed();
        if (line.isEmpty()) continue;
        lista.append(Lancamento::fromLine(line));
    }
    return true;
}

bool FinanceService::salvar(const QList<Lancamento> &lista) {
    QFile f(filename);

    if (!f.open(QFile::WriteOnly | QFile::Text))
        return false;

    QTextStream ts(&f);
    for (const auto &l : lista)
        ts << l.toLine() << "\n";

    return true;
}

int FinanceService::proximoId(const QList<Lancamento> &lista) {
    int maxid = 0;
    for (auto &l : lista)
        if (l.id > maxid) maxid = l.id;
    return maxid + 1;
}
