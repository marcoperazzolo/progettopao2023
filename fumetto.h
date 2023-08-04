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

  // metodi
  // virtual void mostraDettagli() const override; //da implementare!!
};

#endif // FUMETTO_H
