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
    virtual void mostraDettagli() const; //da implementare?-
};

#endif // LIBRO_H