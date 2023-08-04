#include "romanzo.h"

Romanzo::Romanzo(string tit, string des, int dis, int annopub, string aut,
                 string edi, int pag, string gen)
    : Libro(tit, des, dis, annopub, aut, edi, pag), genere(gen) {}

Romanzo::~Romanzo() = default;

string Romanzo::getGenere() const { return genere; }
