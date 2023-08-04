#include "articolo.h"


//costruttori
Articolo::Articolo(string tit, string des, int dis, int annopub)
    : titolo(tit), descrizione(des), disponibilita(dis),
      annoPubblicazione(annopub) {}

Articolo::~Articolo() = default;

//getter
string Articolo::getTitolo() const { return titolo; }
string Articolo::getDescrizione() const { return descrizione; }
int Articolo::getDisponibilita() const { return disponibilita; }
int Articolo::getAnnoPubblicazione() const { return annoPubblicazione; }

//setter
void Articolo::setTitolo(const string &newTitolo) { titolo = newTitolo; }
void Articolo::setDescrizione(const string &newDescrizione) {
  descrizione = newDescrizione;
}
void Articolo::setDisponibilita(int newDisponibilita) {
  disponibilita = newDisponibilita;
}
void Articolo::setAnnoPubblicazione(int newAnnoPubblicazione) {
  annoPubblicazione = newAnnoPubblicazione;
}
