#ifndef LIBRO_H
#define LIBRO_H
#include "articolo.h"
//c++ Model/libro.cpp Model/articolo.cpp main.cpp -o main

class Libro : public Articolo {
private:
    string autore;
    string editore;
    int pagine;

public:
    //costruttori
    Libro(string tit = "Titolo non definito", string des="Descrizione non definita", int dis=0, int annopub=0, string aut = "Autore non definito", string edi="Editore non definito", int pag=0);
    
    virtual ~Libro();

    //getter
    string getAutore() const;
    string getEditore() const;
    int getPagine() const;

    //setter
    void setAutore(const string& newAutore);
    void setEditore(const string& newEditore);
    void setPagine(int newPagine);

    //metodi
    virtual void modificaDettagli(const string& newTitolo="", const string& newDescrizione="", int newDisponibilita=0, int newAnnoPubblicazione=0, 
        const string& newAutore="", const string& newEditore="", int newPagine=0, const string& newGenereRomanzo="", int newNumero=0, const string& newArgomento="", 
        int newDurata=0, const string& newRegista="", double newVoto=0, const string& newArtista="", const string& newGenereCD="", int newNumeroBrani=0);
    virtual void modifica2();
    virtual void mostraDettagli() const;
};

#endif // LIBRO_H