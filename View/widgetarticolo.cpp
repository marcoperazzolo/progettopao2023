#include "widgetarticolo.h"

WidgetArticolo::WidgetArticolo(const std::string& titolo, const std::string& descrizione, int disponibilita, QWidget* parent) : QWidget(parent)
{
    this->disponibilità = disponibilita;
    //creo layout
    riga = new QHBoxLayout(this);
    testi = new QVBoxLayout(this);

    //converto std::string -> QString
    qTitolo = QString::fromStdString(titolo);
    qDescrizione = QString::fromStdString(descrizione);

    //creo etichette
    titoloLabel = new QLabel(qTitolo, this);
    fontTitolo = titoloLabel->font();
    fontTitolo.setPointSize(14);
    titoloLabel->setFont(fontTitolo);

    descrizioneLabel = new QLabel(qDescrizione, this);
    descrizioneLabel->setWordWrap(true);

    disponibilitaLabel = new QLabel(QString("Disponibilità: %1 ").arg(disponibilita), this);

    //creo immagine
    immagineLabel = new QLabel(this);
    QPixmap immagine(":img/dvd.png");
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);

    //aggiungo etichette
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

WidgetArticolo* WidgetArticolo::clone() {
    WidgetArticolo* nuovo = new WidgetArticolo(this->getTitolo(), this->getDescrizione(), this->getDisponibilita());
    //nuovo->setTitolo(this->getTitolo());
    //nuovo->setDescrizione(this->getDescrizione());
    //nuovo->setDisponibilita(this->getDisponibilita());
    return nuovo;
}

std::string WidgetArticolo::getTitolo() const{
    return qTitolo.toStdString();
}

std::string WidgetArticolo::getDescrizione() const{
    return qDescrizione.toStdString();
}

int WidgetArticolo::getDisponibilita() const{
    return disponibilità;
}

void WidgetArticolo::setTitolo(const std::string& titolo){
    qTitolo = QString::fromStdString(titolo);
    titoloLabel->setText(qTitolo);
}

void WidgetArticolo::setDescrizione(const std::string& descrizione){
    qDescrizione = QString::fromStdString(descrizione);
    descrizioneLabel->setText(qDescrizione);
}

void WidgetArticolo::setDisponibilita(const int& disponibilita){
    disponibilitaLabel->setText(QString("Disponibilità: %1 ").arg(disponibilita));
}
