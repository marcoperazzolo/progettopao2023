#include "romanzo.h"

Romanzo::Romanzo(string tit, string des, int dis, int annopub, string aut,
                 string edi, int pag, string gen): Libro(tit, des, dis, annopub, aut, edi, pag), genere(gen) {}
    
Romanzo::~Romanzo()=default;

string Romanzo::getGenere() const{
    return genere;
}

void Romanzo::setGenere(const string& newGenere){
    genere=newGenere;
}

void Romanzo::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()
    <<", Genere: "<<getGenere()<<std::endl;
}