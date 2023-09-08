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
          string des = "Descrizione non definita", int dis = 0,
          string aut = "Autore non definito",
          string edi = "Editore non definito", int pag = 0, string gen="Genere non definito");
    
    virtual ~Romanzo();

    //getter
    virtual string getGenereRomanzo() const;//cambiato sia questo che quello in cd per conflitto

    //setter
    void setGenereRomanzo(const string& newGenere);

    //metodi
    virtual void modificaDettagli(const string& newTitolo="", const string& newDescrizione="", int newDisponibilita=0,
        const string& newAutore="", const string& newEditore="", int newPagine=0, const string& newGenereRomanzo="", int newNumero=0, const string& newArgomento="", 
        int newDurata=0, const string& newRegista="", double newVoto=0, const string& newArtista="", const string& newGenereCD="", int newNumeroBrani=0);
    virtual void modifica2();
    virtual void mostraDettagli() const;
};

#endif // ROMANZO_H
