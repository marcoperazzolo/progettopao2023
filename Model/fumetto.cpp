#include "fumetto.h"

Fumetto::Fumetto(string tit, string des, int dis, int annopub, string aut, string edi, int pag, int num)
    : Libro(tit, des, dis, annopub, aut, edi, pag), numero(num) {}

Fumetto::~Fumetto() = default;

int Fumetto::getNumero() const {
    return numero;
}

void Fumetto::setNumero(int newNumero){
    numero=newNumero;
}

void Fumetto::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, int newAnnoPubblicazione, 
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    setAnnoPubblicazione(newAnnoPubblicazione);
    setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    //setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);
    /*setArgomento(newArgomento);
    setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}
void Fumetto::modifica2(){
  string newTitolo; 
  string newDescrizione; 
  int newDisponibilita; 
  int newAnnoPubblicazione;
  string newAutore;
  string newEditore;
  int newPagine;
  int newNumero;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAnnoPubblicazione;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  cin>>newNumero;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAnnoPubblicazione(newAnnoPubblicazione);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
  setNumero(newNumero);
}

void Fumetto::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()<<", Rivista numero: "<<getNumero()<<std::endl;
}