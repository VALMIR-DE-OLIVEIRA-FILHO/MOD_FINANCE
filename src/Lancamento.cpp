#ifndef LANCAMENTO_H
#define LANCAMENTO_H

#include <string>

class Lancamento {
public:
    Lancamento(const std::string &tipo, double valor, const std::string &data);
    
    std::string tipo;
    double valor;
    std::string data;
};

#endif
