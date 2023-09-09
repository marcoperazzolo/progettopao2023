#include "dvd.h"

DVD::DVD(string tit, string des, int dis, int dur, string reg, double vot): Disco(tit, des, dis, dur), regista(reg), voto(vot) {}
    
DVD::~DVD()=default;

string DVD::getRegista() const{
    return regista;
}
double DVD::getVoto() const{
    return voto;
}

void DVD::setRegista(const string& newRegista){
    regista=newRegista;
}
void DVD::setVoto(double newVoto){
    voto=newVoto;
}

void DVD::modificaDettagli(const string& newTitolo, const string& newDescrizione, int newDisponibilita, 
  const string& newAutore, const string& newEditore, int newPagine, const string& newGenereRomanzo, int newNumero, const string& newArgomento, 
  int newDurata, const string& newRegista, double newVoto, const string& newArtista, const string& newGenereCD, int newNumeroBrani){
    setTitolo(newTitolo);
    setDescrizione(newDescrizione);
    setDisponibilita(newDisponibilita);
    /*setAutore(newAutore);
    setEditore(newEditore);
    setPagine(newPagine);
    setGenereRomanzo(newGenereRomanzo);
    setNumero(newNumero);
    setArgomento(newArgomento);*/
    setDurata(newDurata);
    setRegista(newRegista);
    setVoto(newVoto);
    /*setArtista(newArtista);
    setGenereCD(newGenereCD);
    setNumeroBrani(newNumeroBrani);*/
}

void DVD::modifica2(){
  string newTitolo;
  string newDescrizione;
  int newDisponibilita;
  int newDurata;
  string newRegista;
  double newVoto;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newDurata;
  cin>>newRegista;
  cin>>newVoto;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setDurata(newDurata);
  setRegista(newRegista);
  setVoto(newVoto);
}

void DVD::mostraDettagli() const{
  std::cout<<"Titolo: "<<getTitolo()<<", Descrizione: "<<getDescrizione()<<", Disponibilita': "<<getDisponibilita()
  <<", Durata: "<<getDurata()<<", Regista: "<<getRegista()<<", Voto della critica: "<<getVoto()<<std::endl;
}

QJsonObject DVD::toJson() const {
    QJsonObject jsonObj;
    jsonObj["tipo"] = QString::fromStdString("DVD");
    jsonObj["titolo"] = QString::fromStdString(this->getTitolo());
    jsonObj["descrizione"] = QString::fromStdString(this->getDescrizione());
    jsonObj["disponibilita"] = this->getDisponibilita();
    jsonObj["durata"] = this->getDurata();
    jsonObj["regista"] = QString::fromStdString(regista);
    jsonObj["voto"] = voto;
    jsonObj["durata"] = this->getDurata();
    return jsonObj;
}

void DVD::fromJson(const QJsonObject& jsonObj) {
    QString tit = jsonObj["titolo"].toString();
    QString des = jsonObj["descrizione"].toString();
    int dis = jsonObj["disponibilita"].toInt();

    int dur = jsonObj["durata"].toInt();

    QString reg = jsonObj["regista"].toString();
    int vot = jsonObj["voto"].toInt();

    this->setTitolo(tit.toStdString());
    this->setDescrizione(des.toStdString());
    this->setDisponibilita(dis);
    this->setDurata(dur);

    this->setRegista(reg.toStdString());
    this->setVoto(vot);
}
