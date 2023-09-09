#include "manuale.h"

Manuale::Manuale(string tit, string des, int dis, string aut,
                 string edi, int pag, string arg): Libro(tit, des, dis, aut, edi, pag), argomento(arg) {}
    
Manuale::~Manuale()=default;

string Manuale::getArgomento() const{
    return argomento;
}

void Manuale::setArgomento(const string& newArgomento){
    argomento=newArgomento;
}


void Manuale::modifica2(){
  string newTitolo; 
  string newDescrizione; 
  int newDisponibilita;
  string newAutore;
  string newEditore;
  int newPagine;
  string newArgomento;
  cin>>newTitolo;
  cin>>newDescrizione;
  cin>>newDisponibilita;
  cin>>newAutore;
  cin>>newEditore;
  cin>>newPagine;
  cin>>newArgomento;
  setTitolo(newTitolo);
  setDescrizione(newDescrizione);
  setDisponibilita(newDisponibilita);
  setAutore(newAutore);
  setEditore(newEditore);
  setPagine(newPagine);
  setArgomento(newArgomento);
}



QJsonObject Manuale::toJson() const {
    QJsonObject jsonObj;
    jsonObj["tipo"] = QString::fromStdString("Manuale");

    jsonObj["titolo"] = QString::fromStdString(this->getTitolo());
    jsonObj["descrizione"] = QString::fromStdString(this->getDescrizione());
    jsonObj["disponibilita"] = this->getDisponibilita();
    jsonObj["autore"] = QString::fromStdString(this->getAutore());
    jsonObj["numpagine"] = this->getPagine();
    jsonObj["editore"] = QString::fromStdString(this->getEditore());

    jsonObj["argomento"] = QString::fromStdString(this->getArgomento());
    return jsonObj;
}

void Manuale::fromJson(const QJsonObject& jsonObj) {
    QString tit = jsonObj["titolo"].toString();
    QString des = jsonObj["descrizione"].toString();
    int dis = jsonObj["disponibilita"].toInt();

    QString aut = jsonObj["autore"].toString();
    int numpag = jsonObj["numpagine"].toInt();
    QString edit = jsonObj["editore"].toString();

    QString argom = jsonObj["argomento"].toString();

    this->setTitolo(tit.toStdString());
    this->setDescrizione(des.toStdString());
    this->setDisponibilita(dis);

    this->setAutore(aut.toStdString());
    this->setPagine(numpag);
    this->setEditore(edit.toStdString());

    this->setArgomento(argom.toStdString());

}
