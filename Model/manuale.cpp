#include "manuale.h"

Manuale::Manuale(string tit, string des, int dis, int annopub, string aut,
                 string edi, int pag, string arg): Libro(tit, des, dis, annopub, aut, edi, pag), argomento(arg) {}
    
Manuale::~Manuale()=default;

string Manuale::getArgomento() const{
    return argomento;
}

void Manuale::setArgomento(const string& newArgomento){
    argomento=newArgomento;
}

void Manuale::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, int newAnnoPubblicazione, 
        const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
        int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    setAnnoPubblicazione(newAnnoPubblicazione);
    setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    /*setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);*/
    setArgomento(newArgomento);
    /*setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}
void Manuale::modifica2(){
  string newTitolo; 
  string newDescrizione; 
  int newDisponibilita; 
  int newAnnoPubblicazione;
  string newAutore;
  string newEditore;
  int newPagine;
  string newArgomento;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAnnoPubblicazione;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  cin>>newArgomento;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAnnoPubblicazione(newAnnoPubblicazione);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
  setArgomento(newArgomento);
}

void Manuale::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()<<", Argomento: "<<getArgomento()<<std::endl;
}