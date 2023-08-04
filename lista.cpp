#include "lista.h"

//costruttori
Lista::Lista(Nodo* n=nullptr): start(n) {};

Lista::~Lista() {
  Nodo* aux = start;
        while (aux) {
            Nodo* next = aux->next;
            delete aux;
            aux = next;
}

//metodi
Lista::aggiungiArticolo(const Articolo& nuovoArt) {
        Nodo* nuovoNodo = new Nodo(nuovoArt);
        nuovoNodo->next = start;
        start = nuovoNodo;
    }

//da rivedere
Lista::cercaArticolo(const std::string& Titolo) const {
        Nodo* current = start;
        while (current) {
            if (current->articolo.getTitolo() == Titolo) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Articolo non trovato, DA IMPLEMENTARE LISTA VUOTA
}
