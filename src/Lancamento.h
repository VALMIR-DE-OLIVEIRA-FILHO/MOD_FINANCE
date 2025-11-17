#ifndef LANCAMENTO_H
#define LANCAMENTO_H

#include <QString>
#include <QStringList>


enum TipoOperacao {
    COMPRA,
    VENDA,
    PAGAMENTO,
    RECEBIMENTO
};

struct Lancamento {
    int id;
    QString descricao;
    double valor;
    double custo;
    TipoOperacao tipo;
    QString data; // formato YYYY-MM-DD

    QString toLine() const {
        return QString("%1|%2|%3|%4|%5|%6")
            .arg(id)
            .arg(descricao)
            .arg(valor)
            .arg(custo)
            .arg(tipo)
            .arg(data);
    }

    static Lancamento fromLine(const QString &line) {
        QStringList p = line.split("|");
        Lancamento l;
        l.id = p[0].toInt();
        l.descricao = p[1];
        l.valor = p[2].toDouble();
        l.custo = p[3].toDouble();
        l.tipo = (TipoOperacao)p[4].toInt();
        l.data = p[5];
        return l;
    }
};

#endif
