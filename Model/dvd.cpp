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
