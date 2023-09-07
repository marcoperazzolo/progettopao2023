#include "articolo.h"

Articolo::Articolo(string tit, string des, int dis, int annopub): titolo(tit), descrizione(des), disponibilita(dis), annoPubblicazione(annopub) {}
Articolo::Articolo(const Articolo& a): titolo(a.titolo), descrizione(a. descrizione), disponibilita(a.disponibilita), annoPubblicazione(a.annoPubblicazione) {}
Articolo::~Articolo()=default;

bool Articolo::operator==(const Articolo& a) const{
  if(titolo==a.titolo && descrizione==a.descrizione && disponibilita==a.disponibilita && annoPubblicazione==a.annoPubblicazione)
    return true;
  return false;
}

string Articolo::getTitolo() const{
  return titolo;
}
string Articolo::getDescrizione() const{
  return descrizione;
}
int Articolo::getDisponibilita() const{
  return disponibilita;
}
int Articolo::getAnnoPubblicazione() const{
  return annoPubblicazione;
}

string Articolo::getAutore() const{return 0;}//return 0 per evitare warning
string Articolo::getEditore() const{return 0;}
int Articolo::getPagine() const{return 0;}
string Articolo::getGenereRomanzo() const{return 0;}
int Articolo::getNumero() const{return 0;}
string Articolo::getArgomento() const{return 0;}
int Articolo::getDurata() const{return 0;}
string Articolo::getArtista() const{return 0;}
string Articolo::getGenereCD() const{return 0;}
int Articolo::getNumeroBrani() const{return 0;}
string Articolo::getRegista() const{return 0;}
double Articolo::getVoto() const{return 0;}

void Articolo::setTitolo(const string& newTitolo) {
  titolo=newTitolo;
}
void Articolo::setDescrizione(const string& newDescrizione) {
  descrizione=newDescrizione;
}
void Articolo::setDisponibilita(int newDisponibilita) {
  disponibilita=newDisponibilita;
}
void Articolo::setAnnoPubblicazione(int newAnnoPubblicazione) {
  annoPubblicazione=newAnnoPubblicazione;
}

void Articolo::setAutore(const string& newAutore){}
void Articolo::setEditore(const string& newEditore){}
void Articolo::setPagine(int newPagine){}
void Articolo::setGenereRomanzo(const string& newGenere){}
void Articolo::setNumero(int newNumero){}
void Articolo::setArgomento(const string& newArgomento){}

void Articolo::setDurata(int newDurata){}
void Articolo::setRegista(const string& newRegista){}
void Articolo::setVoto(double newVoto){}
void Articolo::setArtista(const string& newArtista){}
void Articolo::setGenereCD(const string& newGenere){}
void Articolo::setNumeroBrani(int newNumeroBrani){}

void Articolo::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, int newAnnoPubblicazione, 
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
    setArgomento(newArgomento);
    setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}
void Articolo::modifica2(){
  string newTitolo;
  string newDescrizione;
  int newDisponibilita;
  int newAnnoPubblicazione;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAnnoPubblicazione;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAnnoPubblicazione(newAnnoPubblicazione);
}
void Articolo::mostraDettagli() const{
  std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()<<std::endl;
}