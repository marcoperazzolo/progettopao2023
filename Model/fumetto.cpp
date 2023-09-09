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



QJsonObject Fumetto::toJson() const {
    QJsonObject jsonObj;
    jsonObj["tipo"] = QString::fromStdString("Fumetto");
    jsonObj["titolo"] = QString::fromStdString(this->getTitolo());
    jsonObj["descrizione"] = QString::fromStdString(this->getDescrizione());
    jsonObj["disponibilita"] = this->getDisponibilita();
    jsonObj["autore"] = QString::fromStdString(this->getAutore());
    jsonObj["numpagine"] = this->getPagine();
    jsonObj["editore"] = QString::fromStdString(this->getEditore());
    jsonObj["numfumetto"] = this->getNumero();
    return jsonObj;
}

void Fumetto::fromJson(const QJsonObject& jsonObj) {
    QString tit = jsonObj["titolo"].toString();
    QString des = jsonObj["descrizione"].toString();
    int dis = jsonObj["disponibilita"].toInt();

    QString aut = jsonObj["autore"].toString();
    int numpag = jsonObj["numpagine"].toInt();
    QString edit = jsonObj["edit"].toString();

    int numfum = jsonObj["numfumetto"].toInt();

    //Fumetto* fumetto = new Fumetto();

    this->setTitolo(tit.toStdString());
    this->setDescrizione(des.toStdString());
    this->setDisponibilita(dis);

    this->setAutore(aut.toStdString());
    this->setPagine(numpag);
    this->setEditore(edit.toStdString());

    this->setNumero(numfum);

    //return fumetto;
}
