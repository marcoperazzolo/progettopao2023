#include "libro.h"

Libro::Libro(string tit, string des, int dis, int annopub, string aut, string edi, int pag): Articolo(tit, des, dis, annopub), autore(aut), editore(edi), pagine(pag) {}
    
Libro::~Libro()=default;

string Libro::getAutore() const{
    return autore;
}
string Libro::getEditore() const{
    return editore;
}
int Libro::getPagine() const{
    return pagine;
}

void Libro::setAutore(const string& newAutore){
    autore=newAutore;
}
void Libro::setEditore(const string& newEditore){
    editore=newEditore;
}
void Libro::setPagine(int newPagine){
    pagine=newPagine;
}

void Libro::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, int newAnnoPubblicazione, 
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
    setNumero(newNumero);
    setArgomento(newArgomento);
    setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}
void Libro::modifica2(){
  string newTitolo; 
  string newDescrizione; 
  int newDisponibilita; 
  int newAnnoPubblicazione;
  string newAutore;
  string newEditore;
  int newPagine;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAnnoPubblicazione;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAnnoPubblicazione(newAnnoPubblicazione);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
} 
void Libro::mostraDettagli() const{
    std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()<<", Anno di pubblicazione: "<<getAnnoPubblicazione()
    <<", Autore: "<<getAutore()<<", Editore: "<<getEditore()<<", Numero di pagine: "<<getPagine()<<std::endl;
}