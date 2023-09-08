#ifndef MANUALE_H
#define MANUALE_H
#include "libro.h"

class Manuale : public Libro {
private:
    string argomento;
public:
    //costruttori
    Manuale(string tit = "Titolo non definito",
          string des = "Descrizione non definita", int dis = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0,string arg="Argomento non definito");
    
    virtual ~Manuale();

    //getter
    string getArgomento() const;

    //setter
    void setArgomento(const string& newArgomento);

    //metodi
    virtual void modificaDettagli(const string& newTitolo="", const string& newDescrizione="", int newDisponibilita=0,
        const string& newAutore="", const string& newEditore="", int newPagine=0, const string& newGenereRomanzo="", int newNumero=0, const string& newArgomento="", 
        int newDurata=0, const string& newRegista="", double newVoto=0, const string& newArtista="", const string& newGenereCD="", int newNumeroBrani=0);
    virtual void modifica2();
    virtual void mostraDettagli() const;
};

#endif // MANUALE_H