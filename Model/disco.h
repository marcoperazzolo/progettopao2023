#ifndef DISCO_H
#define DISCO_H
#include"articolo.h"

class Disco : public Articolo {
private:
    int durata;//specificare unità di misura

public:
    //costruttori
    Disco(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int dur=0);
    
    virtual ~Disco();

    //getter
    int getDurata() const;

    //setter
    void setDurata(int newDurata);

    //metodi
    virtual void modificaDettagli(const string& newTitolo="", const string& newDescrizione="", int newDisponibilita=0,
        const string& newAutore="", const string& newEditore="", int newPagine=0, const string& newGenereRomanzo="", int newNumero=0, const string& newArgomento="", 
        int newDurata=0, const string& newRegista="", double newVoto=0, const string& newArtista="", const string& newGenereCD="", int newNumeroBrani=0);
    virtual void modifica2();
    virtual void mostraDettagli() const;
};

#endif // DISCO_H