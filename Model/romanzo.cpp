#include "romanzo.h"

Romanzo::Romanzo(string tit, string des, int dis, string aut,
                 string edi, int pag, string gen): Libro(tit, des, dis, aut, edi, pag), genere(gen) {}
    
Romanzo::~Romanzo()=default;

string Romanzo::getGenereRomanzo() const{
    return genere;
}

void Romanzo::setGenereRomanzo(const string& newGenere){
    genere=newGenere;
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
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
  setGenereRomanzo(newGenereRomanzo);
}


QJsonObject Romanzo::toJson() const {
    QJsonObject jsonObj;
    jsonObj["tipo"] = QString::fromStdString("Romanzo");

    jsonObj["titolo"] = QString::fromStdString(this->getTitolo());
    jsonObj["descrizione"] = QString::fromStdString(this->getDescrizione());
    jsonObj["disponibilita"] = this->getDisponibilita();
    jsonObj["autore"] = QString::fromStdString(this->getAutore());
    jsonObj["numpagine"] = this->getPagine();
    jsonObj["editore"] = QString::fromStdString(this->getEditore());

    jsonObj["genererom"] = QString::fromStdString(this->getGenereRomanzo());
    return jsonObj;
}

void Romanzo::fromJson(const QJsonObject& jsonObj) {
    QString tit = jsonObj["titolo"].toString();
    QString des = jsonObj["descrizione"].toString();
    int dis = jsonObj["disponibilita"].toInt();

    QString aut = jsonObj["autore"].toString();
    int numpag = jsonObj["numpagine"].toInt();
    QString edit = jsonObj["editore"].toString();

    QString genererom = jsonObj["genererom"].toString();

    this->setTitolo(tit.toStdString());
    this->setDescrizione(des.toStdString());
    this->setDisponibilita(dis);

    this->setAutore(aut.toStdString());
    this->setPagine(numpag);
    this->setEditore(edit.toStdString());
    this->setGenereRomanzo(genererom.toStdString());

}
