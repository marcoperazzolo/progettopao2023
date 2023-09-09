#include "cd.h"

CD::CD(string tit, string des, int dis, int dur, string art, string gen, int numBr): Disco(tit, des, dis, dur), artista(art), genere(gen), numBrani(numBr) {}
    
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


void CD::modifica2(){
  string newTitolo;
  string newDescrizione;
  int newDisponibilita;
  int newDurata;
  string newArtista;
  string newGenereCD;
  int newNumeroBrani;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newDurata;
  cin>>newArtista;
  cin>>newGenereCD;
  cin>>newNumeroBrani;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setDurata(newDurata);
  setArtista(newArtista);
  setGenereCD(newGenereCD);
  setNumeroBrani(newNumeroBrani);
}


QJsonObject CD::toJson() const {
    QJsonObject jsonObj;
    jsonObj["tipo"] = QString::fromStdString("CD");
    jsonObj["titolo"] = QString::fromStdString(this->getTitolo());
    jsonObj["descrizione"] = QString::fromStdString(this->getDescrizione());
    jsonObj["disponibilita"] = this->getDisponibilita();
    jsonObj["durata"] = this->getDurata();
    jsonObj["artista"] = QString::fromStdString(artista);
    jsonObj["genereCD"] = QString::fromStdString(genere);
    jsonObj["numBrani"] = numBrani;
    return jsonObj;
}

void CD::fromJson(const QJsonObject& jsonObj) {
    QString tit = jsonObj["titolo"].toString();
    QString des = jsonObj["descrizione"].toString();
    int dis = jsonObj["disponibilita"].toInt();

    QString art = jsonObj["artista"].toString();
    int dur = jsonObj["durata"].toInt();
    QString genCD = jsonObj["genereCD"].toString();
    int numBr = jsonObj["numBrani"].toInt();

    //CD* cd = new CD();
    this->setTitolo(tit.toStdString());
    this->setDescrizione(des.toStdString());
    this->setDisponibilita(dis);
    this->setArtista(art.toStdString());
    this->setDurata(dur);
    this->setGenereCD(genCD.toStdString());
    this->setNumeroBrani(numBr);
    //return cd;
}
