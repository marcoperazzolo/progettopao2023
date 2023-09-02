#ifndef MANUALE_H
#define MANUALE_H
#include "libro.h"
// c++ Model/manuale.cpp Model/libro.cpp Model/articolo.cpp main.cpp -o main

class Manuale : public Libro {
private:
    string argomento;
public:
    //costruttori
    Manuale(string tit = "Titolo non definito",
          string des = "Descrizione non definita", int dis = 0, int annopub = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0,string arg="Argomento non definito");
    
    virtual ~Manuale();

    //getter
    string getArgomento() const;

    //setter
    void setArgomento(const string& newArgomento);

    //metodi
    //virtual void mostraDettagli() const override; //da implementare!! 
};

#endif // MANUALE_H