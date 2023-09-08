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
        immagine = QPixmap(":img/dvd.png");
    }
    if(dynamic_cast<DVD*>(art)){
        immagine = QPixmap(":img/dvd.png");
    }
    if(dynamic_cast<Manuale*>(art)){
        immagine = QPixmap(":img/dvd.png");

    }
    if(dynamic_cast<Romanzo*>(art)){
        immagine = QPixmap(":img/dvd.png");

    }
    if(dynamic_cast<Fumetto*>(art)){
        immagine = QPixmap(":img/dvd.png");
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
        immagine = QPixmap(":img/dvd.png");
    }
    if(dynamic_cast<DVD*>(art)){
        immagine = QPixmap(":img/dvd.png");
    }
    if(dynamic_cast<Manuale*>(art)){
        immagine = QPixmap(":img/dvd.png");
    }
    if(dynamic_cast<Romanzo*>(art)){
        immagine = QPixmap(":img/dvd.png");
    }
    if(dynamic_cast<Fumetto*>(art)){
        immagine = QPixmap(":img/dvd.png");
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
    if(CD* cd = dynamic_cast<CD*>(articolo))
        immagine = QPixmap(":img/dvd.png");
    if(DVD* dvd = dynamic_cast<DVD*>(articolo))
        immagine = QPixmap(":img/dvd.png");
    if(Manuale* manuale = dynamic_cast<Manuale*>(articolo))
        immagine = QPixmap(":img/dvd.png");
    if(Romanzo* romanzo = dynamic_cast<Romanzo*>(articolo))
        immagine = QPixmap(":img/dvd.png");
    if(Fumetto* fumetto = dynamic_cast<Fumetto*>(articolo))
        immagine = QPixmap(":img/dvd.png");

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
        immagine = QPixmap(":img/dvd.png");
    if(tipo == "DVD")
        immagine = QPixmap(":img/dvd.png");
    if(tipo == "Romanzo")
        immagine = QPixmap(":img/dvd.png");
    if(tipo == "Manuale")
        immagine = QPixmap(":img/dvd.png");
    if(tipo == "Fumetto")
        immagine = QPixmap(":img/dvd.png");
}


/*
void WidgetArticolo::setDurata(int durata){
    durataLabel->setText((QString("Durata: %1 ").arg(durata)));
}
void WidgetArticolo::setArtista(std::string artista){
    artistaLabel->setText(QString::fromStdString(artista));
}
void WidgetArticolo::setGenereMusicale(std::string genere){
    genereLabel->setText(QString::fromStdString(genere));
}
void WidgetArticolo::setNumeroBrani(int numero){
    numeroLabel->setText((QString("Num. Brani: %1 ").arg(numero)));
}
void WidgetArticolo::setRegista(std::string regista){
    registaLabel->setText(QString::fromStdString(regista));
}
void WidgetArticolo::setVoto(double voto){
    votoLabel->setText(QString("Voto: %1 ").arg(voto));
}
void WidgetArticolo::setAutore(std::string autore){
    autoreLabel->setText(QString::fromStdString(autore));
}
void WidgetArticolo::setPagine(int pagine){
    pagineLabel->setText((QString("Pagine: %1 ").arg(pagine)));
}
void WidgetArticolo::setEditore(std::string editore){
    editoreLabel->setText(QString::fromStdString(editore));
}
void WidgetArticolo::setGenere(std::string genere){
    genereLabel->setText(QString::fromStdString(genere));
}
void WidgetArticolo::setArgomento(std::string argomento){
    argomentoLabel->setText(QString::fromStdString(argomento));
}
void WidgetArticolo::setNumFumetto(int numero){
    numeroLabel->setText((QString("Numero: %1 ").arg(numero)));
}
*/

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

/* GETTERS VECCHI
//Disco
QLabel* WidgetArticolo::getDurataLabel() const{
    return durataLabel;
}
//CD
QLabel* WidgetArticolo::getArtistaLabel() const{
    return artistaLabel;
}
QLabel* WidgetArticolo::getGenereMusicaleLabel() const{
    return genereMusicaleLabel;
}
QLabel* WidgetArticolo::getNumbraniLabel() const{
    return numbraniLabel;
}
//DVD
QLabel* WidgetArticolo::getRegistaLabel(){
    return registaLabel;
}
QLabel* WidgetArticolo::getVotoLabel() const{
    return votoLabel;
}

//Libro
QLabel* WidgetArticolo::getAutoreLabel() const{
    return autoreLabel;
}
QLabel* WidgetArticolo::getPagineLabel() const{
    return pagineLabel;
}
QLabel* WidgetArticolo::getEditoreLabel() const{
    return editoreLabel;
}
//Romanzo
QLabel* WidgetArticolo::getGenereLabel() const{
    return genereLabel;
}
//Manuale
QLabel* WidgetArticolo::getArgomentoLabel() const{
    return argomentoLabel;
}
//Fumetto
QLabel* WidgetArticolo::getNumeroLabel() const{
    return numeroLabel;
}
WidgetArticolo::WidgetArticolo(const std::string& titolo, const std::string& descrizione, int disponibilita, QWidget* parent) : QWidget(parent)
{
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
}*/

/*WidgetArticolo* WidgetArticolo::clone() {
    WidgetArticolo* nuovo = new WidgetArticolo(this->getTitolo(), this->getDescrizione(), this->getDisponibilita());
    //nuovo->setTitolo(this->getTitolo());
    //nuovo->setDescrizione(this->getDescrizione());
    //nuovo->setDisponibilita(this->getDisponibilita());
    return nuovo;
}*/
