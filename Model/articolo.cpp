#include "articolo.h"

Articolo::Articolo(string tit, string des, int dis, int annopub): titolo(tit), descrizione(des), disponibilita(dis), annoPubblicazione(annopub) {}

Articolo::~Articolo()=default;

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
string Articolo::getGenere() const{}

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

void Articolo::mostraDettagli() const{
  std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()<<std::endl;
}