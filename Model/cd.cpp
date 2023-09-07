#include "cd.h"

CD::CD(string tit, string des, int dis, int annopub, int dur, string art, string gen, int numBr): Disco(tit, des, dis, annopub, dur), artista(art), genere(gen), numBrani(numBr) {}
    
CD::~CD()=default;

string CD::getArtista() const{
    return artista;
}
string CD::getGenereCD() const{
    return genere;
}
int CD::getNumeroBrani() const{
    return numBrani;
}


void CD::setArtista(const string& newArtista){
    artista=newArtista;
}
void CD::setGenereCD(const string& newGenere){
    genere=newGenere;
}
void CD::setNumeroBrani(int newNumeroBrani){
    numBrani=newNumeroBrani;
}

void CD::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, int newAnnoPubblicazione, 
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    setAnnoPubblicazione(newAnnoPubblicazione);
    /*setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);
    setArgomento(newArgomento);*/
    setDurata(newDurata);
    /*setRegista(newRegista);
    setVoto(newVoto);*/
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);
}

void CD::modifica2(){
  string newTitolo;
  string newDescrizione;
  int newDisponibilita;
  int newAnnoPubblicazione;
  int newDurata;
  string newArtista;
  string newGenereCD;
  int newNumeroBrani;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAnnoPubblicazione;
  cin>>newDurata;
  cin>>newArtista;
  cin>>newGenereCD;
  cin>>newNumeroBrani;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAnnoPubblicazione(newAnnoPubblicazione);
  setDurata(newDurata);
  setArtista(newArtista);
  setGenereCD(newGenereCD);
  setNumeroBrani(newNumeroBrani);
}

void CD::mostraDettagli() const{
  std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
  <<", Durata: "<<getDurata()<<", Artista: "<<getArtista()<<", Genere: "<<getGenereCD()<<", Numero brani: "<<getNumeroBrani()<<std::endl;
}