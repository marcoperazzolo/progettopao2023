#ifndef FUMETTO_H
#define FUMETTO_H
#include "libro.h"
// c++ Model/fumetto.cpp Model/libro.cpp Model/articolo.cpp main.cpp -o main

class Fumetto : public Libro {
private:
  int numero;
public:
  // costruttori
  Fumetto(string tit = "Titolo non definito",
          string des = "Descrizione non definita", int dis = 0, int annopub = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0, int num = 0);

  virtual ~Fumetto();

  // getter
  int getNumero() const;

  //setter
  void setNumero(int newNumero);

  // metodi
  virtual void modificaDettagli(const string& newTitolo="", const string& newDescrizione="", int newDisponibilita=0, int newAnnoPubblicazione=0, 
    const string& newAutore="", const string& newEditore="", int newPagine=0, const string& newGenereRomanzo="", int newNumero=0, const string& newArgomento="", 
    int newDurata=0, const string& newRegista="", double newVoto=0, const string& newArtista="", const string& newGenereCD="", int newNumeroBrani=0);
  virtual void modifica2();
  virtual void mostraDettagli() const;
};

#endif // FUMETTO_H