#ifndef ROMANZO_H
#define ROMANZO_H
#include "libro.h"
// c++ Model/romanzo.cpp Model/libro.cpp Model/articolo.cpp main.cpp -o main

class Romanzo : public Libro {
private:
    string genere;
public:
    //costruttori
    Romanzo(string tit = "Titolo non definito",
          string des = "Descrizione non definita", int dis = 0, int annopub = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0, string gen="Genere non definito");
    
    virtual ~Romanzo();

    //getter
    string getGenere() const;

    //setter
    void setGenere(const string& newGenere);

    //metodi
    virtual void mostraDettagli() const; //da implementare!! (mettere anche override?)
};

#endif // ROMANZO_H