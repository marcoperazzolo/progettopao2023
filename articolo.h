#ifndef ARTICOLO_H
#define ARTICOLO_H

// includere view???
#include <iostream> //da togliere dopo test
#include <string>
using std::string;
// per compilare solo articolo tramite main usare: c++ Model/articolo.cpp main.cpp -o main

class Articolo {
private:
  string titolo;
  string descrizione;
  int disponibilita;
  int annoPubblicazione;

public:
  // costruttori
  Articolo(string tit = "Titolo non definito",
           string des = "Descrizione non definita", int dis = 0,
           int annopub = 0);

  virtual ~Articolo();

  // getter
  string getTitolo() const;
  string getDescrizione() const;
  int getDisponibilita() const;
  int getAnnoPubblicazione() const;

  // setter
  void setTitolo(const string &newTitolo);
  void setDescrizione(const string &newDescrizione);
  void setDisponibilita(int newDisponibilita);
  void setAnnoPubblicazione(int newAnnoPubblicazione);

  // metodi
  // virtual void mostraDettagli();//vedere se implementare, per ora crea solo
  // problemi
};

#endif // ARTICOLO_H
