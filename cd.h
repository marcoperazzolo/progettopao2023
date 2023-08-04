#ifndef CD_H
#define CD_H

#include "disco.h"
// c++ Model/cd.cpp Model/disco.cpp Model/articolo.cpp main.cpp -o main

class CD : public Disco {
private:
  string artista;
  string genere;
  int numBrani;

public:
  // costruttori
  CD(string tit = "Titolo non definito",
     string des = "Descrizione non definita", int dis = 0, int annopub = 0,
     int dur = 0, string art = "Artista non definito",
     string gen = "Genere non definito", int numBr = 0);

  virtual ~CD();

  // getter
  string getArtista() const;
  string getGenere() const;
  int getNumeroBrani() const;

  // metodi
  // virtual void mostraDettagli() const override; //da implementare!!
};

#endif // CD_H
