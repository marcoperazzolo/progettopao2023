#ifndef DVD_H
#define DVD_H

#include "disco.h"
// c++ Model/dvd.cpp Model/disco.cpp Model/articolo.cpp main.cpp -o main

class DVD : public Disco {
private:
  string regista;
  double voto;

public:
  // costruttori
  DVD(string tit = "Titolo non definito",
      string des = "Descrizione non definita", int dis = 0, int annopub = 0,
      int dur = 0, string reg = "Regista non definito", double vot = 0.0);

  virtual ~DVD();

  // getter
  string getRegista() const;
  double getVoto() const;

  // metodi
  // virtual void mostraDettagli() const override; //da implementare!!
};

#endif // DVD_H
