#include "fumetto.h"

Fumetto::Fumetto(string tit, string des, int dis, int annopub, string aut, string edi, int pag, int num)
    : Libro(tit, des, dis, annopub, aut, edi, pag), numero(num) {}

Fumetto::~Fumetto() = default;

int Fumetto::getNumero() const {
    return numero;
}

void Fumetto::setNumero(int newNumero){
    numero=newNumero;
}