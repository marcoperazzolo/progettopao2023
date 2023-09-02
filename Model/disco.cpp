#include "disco.h"

Disco::Disco(string tit, string des, int dis, int annopub, int dur): Articolo(tit, des, dis, annopub), durata(dur) {}

Disco::~Disco()=default;

int Disco::getDurata() const{
    return durata;
}

void Disco::setDurata(int newDurata){
    durata=newDurata;
}