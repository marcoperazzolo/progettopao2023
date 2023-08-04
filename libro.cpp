#include "libro.h"

//costruttori
Libro::Libro(string tit, string des, int dis, int annopub, string aut,
             string edi, int pag)
    : Articolo(tit, des, dis, annopub), autore(aut), editore(edi), pagine(pag) {
}

Libro::~Libro() = default;

//getter
string Libro::getAutore() const { return autore; }
string Libro::getEditore() const { return editore; }
int Libro::getPagine() const { return pagine; }
