#ifndef DVD_H
#define DVD_H
#include "disco.h"
//c++ Model/dvd.cpp Model/disco.cpp Model/articolo.cpp main.cpp -o main

class DVD : public Disco {
private:
    string regista;
    double voto;

public:
    //costruttori
    DVD(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int annopub=0, int dur=0, string reg="Regista non definito", double vot=0.0);
    
    virtual ~DVD();

    //getter
    string getRegista() const;
    double getVoto() const;

    //setter
    void setRegista(const string& newRegista);
    void setVoto(double newVoto);

    //metodi
    virtual void modificaDettagli(const string& newTitolo="", const string& newDescrizione="", int newDisponibilita=0, int newAnnoPubblicazione=0, 
        const string& newAutore="", const string& newEditore="", int newPagine=0, const string& newGenereRomanzo="", int newNumero=0, const string& newArgomento="", 
        int newDurata=0, const string& newRegista="", double newVoto=0, const string& newArtista="", const string& newGenereCD="", int newNumeroBrani=0);
    virtual void modifica2();
    virtual void mostraDettagli() const;
};

#endif // DVD_H