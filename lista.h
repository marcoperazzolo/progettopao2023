#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"
#include "articolo.h"

class Lista {
  private:
    Nodo* start;

  public:
    //costruttori
    Lista();

    ~Lista();

    //getter

    //metodi

    //aggiunge in Testa
    void aggiungiArticolo(const Articolo& nuovoArt);
    void modificaArticolo(
    //da rivedere
    Nodo* cercaArticolo(const std::string& Titolo) const;
};
    void inserisciArticolo(Articolo* nuovoArticolo);
    Articolo* cercaArticolo(const std::string& titolo) const;
    void cancellaArticolo(const std::string& titolo);

#endif // LISTA_H
