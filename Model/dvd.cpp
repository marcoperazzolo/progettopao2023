#include "dvd.h"

DVD::DVD(string tit, string des, int dis, int annopub, int dur, string reg, double vot): Disco(tit, des, dis, annopub, dur), regista(reg), voto(vot) {}
    
DVD::~DVD()=default;

string DVD::getRegista() const{
    return regista;
}
double DVD::getVoto() const{
    return voto;
}

void DVD::setRegista(const string& newRegista){
    regista=newRegista;
}
void DVD::setVoto(double newVoto){
    voto=newVoto;
}

void DVD::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, int newAnnoPubblicazione, 
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    setAnnoPubblicazione(newAnnoPubblicazione);
    /*setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);
    setArgomento(newArgomento);*/
    setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    /*setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}

void DVD::modifica2(){
  string newTitolo;
  string newDescrizione;
  int newDisponibilita;
  int newAnnoPubblicazione;
  int newDurata;
  string newRegista;
  double newVoto;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAnnoPubblicazione;
  cin>>newDurata;
  cin>>newRegista;
  cin>>newVoto;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAnnoPubblicazione(newAnnoPubblicazione);
  setDurata(newDurata);
  setRegista(newRegista);
  setVoto(newVoto);
}

void DVD::mostraDettagli() const{
  std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
  <<", Durata: "<<getDurata()<<", Regista: "<<getRegista()<<", Voto della critica: "<<getVoto()<<std::endl;
}