#include "fumetto.h"

Fumetto::Fumetto(string tit, string des, int dis, string aut, string edi, int pag, int num)
    : Libro(tit, des, dis, aut, edi, pag), numero(num) {}

Fumetto::~Fumetto() = default;

int Fumetto::getNumero() const {
    return numero;
}

void Fumetto::setNumero(int newNumero){
    numero=newNumero;
}

void Fumetto::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, 
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
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
  string newAutore;
  string newEditore;
  int newPagine;
  int newNumero;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  cin>>newNumero;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
  setNumero(newNumero);
}

void Fumetto::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()<<", Rivista numero: "<<getNumero()<<std::endl;
}