#include "disco.h"

Disco::Disco(string tit, string des, int dis, int dur): Articolo(tit, des, dis), durata(dur) {}

Disco::~Disco()=default;

int Disco::getDurata() const{
    return durata;
}

void Disco::setDurata(int newDurata){
    durata=newDurata;
}

void Disco::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita,
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    /*setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);
    setArgomento(newArgomento);*/
    setDurata(newDurata);
    /*setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
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

void Disco::mostraDettagli() const{
  std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()
  <<", Durata: "<<getDurata()<<std::endl;
}