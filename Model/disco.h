#ifndef DISCO_H
#define DISCO_H
#include"articolo.h"

class Disco : public Articolo {
private:
    int durata;

public:
    //costruttori
    Disco(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int dur=0);
    
    virtual ~Disco();

    //getter
    int getDurata() const;

    //setter
    void setDurata(int newDurata);

    //metodi
    virtual void modifica2();

};

#endif // DISCO_H
