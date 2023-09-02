#ifndef DISCO_H
#define DISCO_H
#include"articolo.h"
//c++ Model/disco.cpp Model/articolo.cpp main.cpp -o main

class Disco : public Articolo {
private:
    int durata;

public:
    //costruttori
    Disco(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int annopub=0, int dur=0);
    
    virtual ~Disco();

    //getter
    int getDurata() const;

    //setter
    void setDurata(int newDurata);

    //metodi
    //virtual void mostraDettagli() const override; //da implementare?-
};

#endif // DISCO_H