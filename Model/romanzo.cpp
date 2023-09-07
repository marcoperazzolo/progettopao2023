#include "romanzo.h"

Romanzo::Romanzo(string tit, string des, int dis, int annopub, string aut,
                 string edi, int pag, string gen): Libro(tit, des, dis, annopub, aut, edi, pag), genere(gen) {}
    
Romanzo::~Romanzo()=default;

string Romanzo::getGenereRomanzo() const{
    return genere;
}

void Romanzo::setGenereRomanzo(const string& newGenere){
    genere=newGenere;
}

void Romanzo::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, int newAnnoPubblicazione, 
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    setAnnoPubblicazione(newAnnoPubblicazione);
    setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    setGenereRomanzo(newGenereRomanzo);
    /*setNumero(newNumero);
    setArgomento(newArgomento);
    setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}
void Romanzo::modifica2(){
  string newTitolo; 
  string newDescrizione; 
  int newDisponibilita; 
  int newAnnoPubblicazione;
  string newAutore;
  string newEditore;
  int newPagine;
  string newGenereRomanzo;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAnnoPubblicazione;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  cin>>newGenereRomanzo;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAnnoPubblicazione(newAnnoPubblicazione);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
  setGenereRomanzo(newGenereRomanzo);
}
void Romanzo::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()<<", Genere: "<<getGenereRomanzo()<<std::endl;
}