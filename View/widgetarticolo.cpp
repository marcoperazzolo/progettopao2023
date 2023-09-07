#include "widgetarticolo.h"

WidgetArticolo::WidgetArticolo(Articolo* art, QWidget* parent) : QWidget(parent)
{
    articolo = art;
    //creo layout
    riga = new QHBoxLayout(this);
    testi = new QVBoxLayout(this);

    //converto std::string -> QString
    qTitolo = QString::fromStdString(art->getTitolo());
    qDescrizione = QString::fromStdString(art->getDescrizione());

    //creo etichette
    titoloLabel = new QLabel(qTitolo, this);
    fontTitolo = titoloLabel->font();
    fontTitolo.setPointSize(14);
    titoloLabel->setFont(fontTitolo);

    descrizioneLabel = new QLabel(qDescrizione, this);
    descrizioneLabel->setWordWrap(true);

    disponibilitaLabel = new QLabel(QString("Disponibilità: %1 ").arg(art->getDisponibilita()), this);

    //creo immagine
    immagineLabel = new QLabel(this);
    if(CD* cd = dynamic_cast<CD*>(art)){
        setCDLabels(cd->getDurata(), cd->getArtista(), cd->getGenere(), cd->getNumeroBrani());
    }
    if(DVD* dvd = dynamic_cast<DVD*>(art)){
        setDVDLabels(dvd->getDurata(), dvd->getRegista(), dvd->getVoto());
    }
    if(Manuale* manuale = dynamic_cast<Manuale*>(art)){
        setManualeLabels(manuale->getAutore(), manuale->getPagine(), manuale->getEditore(), manuale->getArgomento());
    }
    if(Romanzo* romanzo = dynamic_cast<Romanzo*>(art)){
        setRomanzoLabels(romanzo->getAutore(), romanzo->getPagine(), romanzo->getEditore(), romanzo->getGenere());
    }
    if(Fumetto* fumetto = dynamic_cast<Fumetto*>(art)){
        setFumettoLabels(fumetto->getAutore(), fumetto->getPagine(), fumetto->getEditore(), fumetto->getNumero());
    }


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



//REFRESH
void WidgetArticolo::refreshWidget(Articolo* articolo){
    //prendo valori dall'articolo (local)
    setTitolo(articolo->getTitolo());
    qDescrizione = QString::fromStdString(articolo->getDescrizione());

    //li setto nelle label
    titoloLabel->setText(qTitolo);
    descrizioneLabel->setText(qDescrizione);
    disponibilitaLabel->setText((QString("Disponibilità: %1 ").arg(articolo->getDisponibilita())));

    //aggiorno immagine: DA FINIRE
    if(dynamic_cast<Disco*>(articolo)){
        immagine = QPixmap(":img/dvd.png");
    }
    if(dynamic_cast<Libro*>(articolo)){
        immagine = QPixmap(":img/libro.png");
    }
    immagineLabel->setPixmap(immagine);
    this->articolo=articolo;

}



//SETTER
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

void WidgetArticolo::setCDLabels(int durata, std::string artista, std::string genereMusicale, int numeroBrani){
    durataLabel = new QLabel(QString("Durata: %1 ").arg(durata), this);
    artistaLabel = new QLabel(QString::fromStdString(artista), this);
    genereMusicaleLabel = new QLabel(QString::fromStdString(genereMusicale), this);
    numbraniLabel = new QLabel(QString("Num. Brani: %1 ").arg(numeroBrani), this);
    immagine = QPixmap(":img/dvd.png");
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);
}

void WidgetArticolo::setDVDLabels(int durata, std::string regista, double votoCritica){
    durataLabel = new QLabel(QString("Durata: %1 ").arg(durata), this);
    registaLabel = new QLabel(QString::fromStdString(regista), this);
    votoLabel = new QLabel(QString("Voto: %1 ").arg(votoCritica), this);
    immagine = QPixmap(":img/dvd.png");
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);
}

void WidgetArticolo::setManualeLabels(std::string autore, int pagine, std::string editore, std::string argomento){
    autoreLabel = new QLabel(QString::fromStdString(autore), this);
    pagineLabel = new QLabel(QString("Num. pagine: %1 ").arg(pagine), this);
    editoreLabel = new QLabel(QString::fromStdString(editore), this);
    argomentoLabel = new QLabel(QString::fromStdString(argomento), this);
    immagine = QPixmap(":img/libro.png");
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);
}

void WidgetArticolo::setRomanzoLabels(std::string autore, int pagine, std::string editore, std::string genere){
    autoreLabel = new QLabel(QString::fromStdString(autore), this);
    pagineLabel = new QLabel(QString("Num. pagine: %1 ").arg(pagine), this);
    editoreLabel = new QLabel(QString::fromStdString(editore), this);
    genereLabel = new QLabel(QString::fromStdString(genere), this);
    immagine = QPixmap(":img/libro.png");
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);

}
void WidgetArticolo::setFumettoLabels(std::string autore, int pagine, std::string editore, int numfumetto){
    autoreLabel = new QLabel(QString::fromStdString(autore), this);
    pagineLabel = new QLabel(QString("Num. pagine: %1 ").arg(pagine), this);
    editoreLabel = new QLabel(QString::fromStdString(editore), this);
    numeroLabel = new QLabel(QString("Num. fumetto: %1 ").arg(numfumetto), this);
    immagine = QPixmap(":img/libro.png");
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);
}


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

//GETTER
Articolo* WidgetArticolo::getArticolo() const{
    return articolo;
}
QString WidgetArticolo::getqTitolo() const{
    return qTitolo;
}
QString WidgetArticolo::getqDescrizione() const{
    return qDescrizione;
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
/*WidgetArticolo::WidgetArticolo(const std::string& titolo, const std::string& descrizione, int disponibilita, QWidget* parent) : QWidget(parent)
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

/* NON SO SE SERVE
 * WidgetArticolo* WidgetArticolo::clone() {
    WidgetArticolo* nuovo = new WidgetArticolo(this->getTitolo(), this->getDescrizione(), this->getDisponibilita());
    //nuovo->setTitolo(this->getTitolo());
    //nuovo->setDescrizione(this->getDescrizione());
    //nuovo->setDisponibilita(this->getDisponibilita());
    return nuovo;
}*/
