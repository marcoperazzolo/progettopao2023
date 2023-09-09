#include "widgetarticolo.h"

WidgetArticolo::WidgetArticolo(Articolo* art, QWidget* parent) : QWidget(parent), articolo(art)
{
    //Layout
    riga = new QHBoxLayout(this);
    testi = new QVBoxLayout(this);

    //Titolo
    titoloLabel = new QLabel(QString::fromStdString(art->getTitolo()), this);
    fontTitolo = titoloLabel->font();
    fontTitolo.setPointSize(14);
    titoloLabel->setFont(fontTitolo);

    //Descrizione
    descrizioneLabel = new QLabel(QString::fromStdString(art->getDescrizione()), this);
    descrizioneLabel->setWordWrap(true);

    //Disponibilità
    disponibilitaLabel = new QLabel(QString("Disponibilità: %1 ").arg(art->getDisponibilita()), this);

    //Immagine
    immagineLabel = new QLabel(this);
    if(dynamic_cast<CD*>(art)){
        immagine = QPixmap(":/img/cd.png");
    }
    if(dynamic_cast<DVD*>(art)){
        immagine = QPixmap(":/img/dvd.png");
    }
    if(dynamic_cast<Manuale*>(art)){
        immagine = QPixmap(":/img/manuale.png");

    }
    if(dynamic_cast<Romanzo*>(art)){
        immagine = QPixmap(":/img/romanzo.png");

    }
    if(dynamic_cast<Fumetto*>(art)){
        immagine = QPixmap(":/img/fumetto.png");
    }
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);

    //Aggiungo Layout e Widget
    testi->addWidget(titoloLabel);
    testi->addWidget(descrizioneLabel);
    testi->addWidget(disponibilitaLabel);
    testi->addStretch();
    riga->addWidget(immagineLabel);
    riga->addLayout(testi);

    //imposto layout
    riga->addStretch();
    setLayout(riga);
}


//REFRESH
void WidgetArticolo::refreshWidget(Articolo* art){
    //Aggiorno Labels da Articolo art
    setTitoloLabel(art->getTitolo());
    setDescrizioneLabel(art->getDescrizione());
    setDisponibilitaLabel(art->getDisponibilita());

    //Aggiorno immagine
    if(dynamic_cast<CD*>(art)){
        immagine = QPixmap(":/img/cd.png");
    }
    if(dynamic_cast<DVD*>(art)){
        immagine = QPixmap(":/img/dvd.png");
    }
    if(dynamic_cast<Manuale*>(art)){
        immagine = QPixmap(":/img/manuale.png");

    }
    if(dynamic_cast<Romanzo*>(art)){
        immagine = QPixmap(":/img/romanzo.png");

    }
    if(dynamic_cast<Fumetto*>(art)){
        immagine = QPixmap(":/img/fumetto.png");
    }
    //Aggiorno Articolo locale
    articolo=art;

    update();
}

void WidgetArticolo::refreshWidget(){
    //Aggiorno Labels da Articolo local
    setTitoloLabel(articolo->getTitolo());
    setDescrizioneLabel(articolo->getDescrizione());
    setDisponibilitaLabel(articolo->getDisponibilita());

    //Aggiorno immagine
    if(dynamic_cast<CD*>(articolo)){
        immagine = QPixmap(":/img/cd.png");
    }
    if(dynamic_cast<DVD*>(articolo)){
        immagine = QPixmap(":/img/dvd.png");
    }
    if(dynamic_cast<Manuale*>(articolo)){
        immagine = QPixmap(":/img/manuale.png");
    }
    if(dynamic_cast<Romanzo*>(articolo)){
        immagine = QPixmap(":/img/romanzo.png");
    }
    if(dynamic_cast<Fumetto*>(articolo)){
        immagine = QPixmap(":/img/fumetto.png");
    }

    update();
}

//SETTER
void WidgetArticolo::setTitoloLabel(const std::string& titolo){
    titoloLabel->setText(QString::fromStdString(titolo));
}
void WidgetArticolo::setDescrizioneLabel(const std::string& descrizione){
    descrizioneLabel->setText(QString::fromStdString(descrizione));
}
void WidgetArticolo::setDisponibilitaLabel(const int& disponibilita){
    disponibilitaLabel->setText(QString("Disponibilità: %1 ").arg(disponibilita));
}
void WidgetArticolo::setImmagine(const std::string& tipo){
    if(tipo == "CD")
        immagine = QPixmap(":/img/cd.png");
    if(tipo == "DVD")
        immagine = QPixmap(":/img/dvd.png");
    if(tipo == "Romanzo")
        immagine = QPixmap(":/img/romanzo.png");
    if(tipo == "Manuale")
        immagine = QPixmap(":/img/manuale.png");
    if(tipo == "Fumetto")
        immagine = QPixmap(":/img/fumetto.png");
}


//GETTER
Articolo* WidgetArticolo::getArticolo() const{
    return articolo;
}
QLabel* WidgetArticolo::getTitoloLabel() const{
    return titoloLabel;
}
QLabel* WidgetArticolo::getDescrizioneLabel() const{
    return descrizioneLabel;
}
QLabel* WidgetArticolo::getDisponibilitaLabel() const{
    return disponibilitaLabel;
}
QPixmap WidgetArticolo::getImmagine() const{
    return immagine;
}

