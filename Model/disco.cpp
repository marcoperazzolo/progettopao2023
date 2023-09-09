#include "disco.h"

Disco::Disco(string tit, string des, int dis, int dur): Articolo(tit, des, dis), durata(dur) {}

Disco::~Disco()=default;

int Disco::getDurata() const{
    return durata;
}

void Disco::setDurata(int newDurata){
    durata=newDurata;
}


void Disco::modifica2(){
  string newTitolo;
  string newDescrizione;
  int newDisponibilita;
  int newDurata;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newDurata;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setDurata(newDurata);
}


