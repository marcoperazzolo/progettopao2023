#include "finestraaggiungiarticolo.h"

FinestraAggiungiArticolo::FinestraAggiungiArticolo(QWidget* parent) : QDialog(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    tipoArticoloComboBox = new QComboBox;
    tipoArticoloComboBox->addItem("Seleziona...");
    tipoArticoloComboBox->addItem("CD");
    tipoArticoloComboBox->addItem("DVD");
    tipoArticoloComboBox->addItem("Manuale");
    tipoArticoloComboBox->addItem("Fumetto");
    tipoArticoloComboBox->addItem("Romanzo");
    layout->addWidget(tipoArticoloComboBox);

    tipoArticolo = tipoArticoloComboBox->currentText();
    connect(tipoArticoloComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FinestraAggiungiArticolo::tipoArticoloCambiato);

    //Creo QLineEdit
    titoloLineEdit = new QLineEdit(this);
    descrizioneLineEdit = new QLineEdit(this);
    disponibilitaLineEdit = new QLineEdit(this);
    durataLineEdit = new QLineEdit(this);
    registaLineEdit = new QLineEdit(this);
    votoLineEdit = new QLineEdit(this);
    artistaLineEdit = new QLineEdit(this);
    genereMusicaleLineEdit = new QLineEdit(this);
    numBraniLineEdit = new QLineEdit(this);
    autoreLineEdit = new QLineEdit(this);
    editoreLineEdit = new QLineEdit(this);
    numPagineLineEdit = new QLineEdit(this);
    genereLineEdit = new QLineEdit(this);
    argomentoLineEdit = new QLineEdit(this);
    numFumettoLineEdit = new QLineEdit(this);

    //LABELS
    titoloLabel = new QLabel("Titolo:", this);
    descrizioneLabel = new QLabel("Descrizione:", this);
    disponibilitaLabel = new QLabel("Disponibilità:", this);
    durataLabel = new QLabel("Durata:", this);
    registaLabel = new QLabel("Regista:", this);
    votoLabel = new QLabel("Voto:", this);
    artistaLabel = new QLabel("Artista:", this);
    genereMusicaleLabel = new QLabel("Genere:", this);
    numBraniLabel = new QLabel("Numero Brani:", this);
    autoreLabel = new QLabel("Autore:", this);
    editoreLabel = new QLabel("Editore:", this);
    numPagineLabel = new QLabel("Pagine:", this);
    genereLabel = new QLabel("Genere:", this);
    argomentoLabel = new QLabel("Argomento:", this);
    numFumettoLabel = new QLabel("Numero:", this);

    //Aggiungo Labels e LineEdit
    layout->addWidget(titoloLabel);
    layout->addWidget(titoloLineEdit);
    layout->addWidget(descrizioneLabel);
    layout->addWidget(descrizioneLineEdit);
    layout->addWidget(disponibilitaLabel);
    layout->addWidget(disponibilitaLineEdit);
    layout->addWidget(durataLabel);
    layout->addWidget(durataLineEdit);
    layout->addWidget(registaLabel);
    layout->addWidget(registaLineEdit);
    layout->addWidget(votoLabel);
    layout->addWidget(votoLineEdit);
    layout->addWidget(artistaLabel);
    layout->addWidget(artistaLineEdit);
    layout->addWidget(genereMusicaleLabel);
    layout->addWidget(genereMusicaleLineEdit);
    layout->addWidget(numBraniLabel);
    layout->addWidget(numBraniLineEdit);
    layout->addWidget(autoreLabel);
    layout->addWidget(autoreLineEdit);
    layout->addWidget(editoreLabel);
    layout->addWidget(editoreLineEdit);
    layout->addWidget(numPagineLabel);
    layout->addWidget(numPagineLineEdit);
    layout->addWidget(genereLabel);
    layout->addWidget(genereLineEdit);
    layout->addWidget(argomentoLabel);
    layout->addWidget(argomentoLineEdit);
    layout->addWidget(numFumettoLabel);
    layout->addWidget(numFumettoLineEdit);
    //Nascondo
    titoloLineEdit->hide();
    descrizioneLineEdit->hide();
    disponibilitaLineEdit->hide();
    durataLineEdit->hide();
    registaLineEdit->hide();
    votoLineEdit->hide();
    artistaLineEdit->hide();
    genereMusicaleLineEdit->hide();
    numBraniLineEdit->hide();
    autoreLineEdit->hide();
    editoreLineEdit->hide();
    numPagineLineEdit->hide();
    genereLineEdit->hide();
    argomentoLineEdit->hide();
    numFumettoLineEdit->hide();
    titoloLabel->hide();
    descrizioneLabel->hide();
    disponibilitaLabel->hide();
    durataLabel->hide();
    registaLabel->hide();
    votoLabel->hide();
    artistaLabel->hide();
    genereMusicaleLabel->hide();
    numBraniLabel->hide();
    autoreLabel->hide();
    editoreLabel->hide();
    numPagineLabel->hide();
    genereLabel->hide();
    argomentoLabel->hide();
    numFumettoLabel->hide();

    //BUTTONS
    confermaCDButton = new QPushButton("Conferma", this);
    confermaDVDButton = new QPushButton("Conferma", this);
    confermaManualeButton = new QPushButton("Conferma", this);
    confermaRomanzoButton = new QPushButton("Conferma", this);
    confermaFumettoButton = new QPushButton("Conferma", this);
    annullaButton = new QPushButton("Annulla", this);
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(confermaCDButton);
    buttonLayout->addWidget(confermaDVDButton);
    buttonLayout->addWidget(confermaManualeButton);
    buttonLayout->addWidget(confermaRomanzoButton);
    buttonLayout->addWidget(confermaFumettoButton);
    confermaCDButton->hide();
    confermaDVDButton->hide();
    confermaManualeButton->hide();
    confermaRomanzoButton->hide();
    confermaFumettoButton->hide();

    buttonLayout->addWidget(annullaButton);
    layout->addLayout(buttonLayout);

    //CONNECT
    connect(annullaButton, &QPushButton::clicked, this, &FinestraAggiungiArticolo::reject);
    connect(confermaCDButton, &QPushButton::clicked, this, &FinestraAggiungiArticolo::confermaAggiuntaCD);
    connect(confermaDVDButton, &QPushButton::clicked, this, &FinestraAggiungiArticolo::confermaAggiuntaDVD);
    connect(confermaManualeButton, &QPushButton::clicked, this, &FinestraAggiungiArticolo::confermaAggiuntaManuale);
    connect(confermaFumettoButton, &QPushButton::clicked, this, &FinestraAggiungiArticolo::confermaAggiuntaFumetto);
    connect(confermaRomanzoButton, &QPushButton::clicked, this, &FinestraAggiungiArticolo::confermaAggiuntaRomanzo);



    setLayout(layout);
    setWindowTitle("Aggiungi Articolo");
}

void FinestraAggiungiArticolo::tipoArticoloCambiato() {
    // Nascondi tutti i campi prima di mostrarne uno
    titoloLineEdit->hide();
    descrizioneLineEdit->hide();
    disponibilitaLineEdit->hide();
    durataLineEdit->hide();
    registaLineEdit->hide();
    votoLineEdit->hide();
    artistaLineEdit->hide();
    genereMusicaleLineEdit->hide();
    numBraniLineEdit->hide();
    autoreLineEdit->hide();
    editoreLineEdit->hide();
    numPagineLineEdit->hide();
    genereLineEdit->hide();
    argomentoLineEdit->hide();
    numFumettoLineEdit->hide();
    titoloLabel->hide();
    descrizioneLabel->hide();
    disponibilitaLabel->hide();
    durataLabel->hide();
    registaLabel->hide();
    votoLabel->hide();
    artistaLabel->hide();
    genereMusicaleLabel->hide();
    numBraniLabel->hide();
    autoreLabel->hide();
    editoreLabel->hide();
    numPagineLabel->hide();
    genereLabel->hide();
    argomentoLabel->hide();
    numFumettoLabel->hide();

    confermaCDButton->hide();
    confermaDVDButton->hide();
    confermaManualeButton->hide();
    confermaRomanzoButton->hide();
    confermaFumettoButton->hide();
    tipoArticolo = tipoArticoloComboBox->currentText();

    if (tipoArticolo == "Seleziona...") {
        titoloLineEdit->hide();
        descrizioneLineEdit->hide();
        disponibilitaLineEdit->hide();
        durataLineEdit->hide();
        registaLineEdit->hide();
        votoLineEdit->hide();
        artistaLineEdit->hide();
        genereMusicaleLineEdit->hide();
        numBraniLineEdit->hide();
        autoreLineEdit->hide();
        editoreLineEdit->hide();
        numPagineLineEdit->hide();
        genereLineEdit->hide();
        argomentoLineEdit->hide();
        numFumettoLineEdit->hide();
        titoloLabel->hide();
        descrizioneLabel->hide();
        disponibilitaLabel->hide();
        durataLabel->hide();
        registaLabel->hide();
        votoLabel->hide();
        artistaLabel->hide();
        genereMusicaleLabel->hide();
        numBraniLabel->hide();
        autoreLabel->hide();
        editoreLabel->hide();
        numPagineLabel->hide();
        genereLabel->hide();
        argomentoLabel->hide();
        numFumettoLabel->hide();

        confermaCDButton->hide();
        confermaDVDButton->hide();
        confermaManualeButton->hide();
        confermaRomanzoButton->hide();
        confermaFumettoButton->hide();
    }
    if (tipoArticolo == "CD") {
        titoloLabel->show();
        titoloLineEdit->show();
        descrizioneLabel->show();
        descrizioneLineEdit->show();
        disponibilitaLabel->show();
        disponibilitaLineEdit->show();
        durataLabel->show();
        durataLineEdit->show();    ;
        artistaLabel->show();
        artistaLineEdit->show();
        genereMusicaleLabel->show();
        genereMusicaleLineEdit->show();
        numBraniLabel->show();
        numBraniLineEdit->show();
        confermaCDButton->show();
}
    if (tipoArticolo == "DVD") {
        titoloLabel->show();
        titoloLineEdit->show();
        descrizioneLabel->show();
        descrizioneLineEdit->show();
        disponibilitaLabel->show();
        disponibilitaLineEdit->show();
        durataLabel->show();
        durataLineEdit->show();    ;
        registaLabel->show();
        registaLineEdit->show();
        votoLabel->show();
        votoLineEdit->show();
        confermaDVDButton->show();
    }
    if (tipoArticolo == "Romanzo") {
        titoloLabel->show();
        titoloLineEdit->show();
        descrizioneLabel->show();
        descrizioneLineEdit->show();
        disponibilitaLabel->show();
        disponibilitaLineEdit->show();
        autoreLabel->show();
        autoreLineEdit->show();
        numPagineLabel->show();
        numPagineLineEdit->show();
        editoreLabel->show();
        editoreLineEdit->show();
        genereLabel->show();
        genereLineEdit->show();
        confermaRomanzoButton->show();
    }
    if (tipoArticolo == "Fumetto") {
        titoloLineEdit->show();
        titoloLabel->show();
        descrizioneLabel->show();
        descrizioneLineEdit->show();
        disponibilitaLabel->show();
        disponibilitaLineEdit->show();
        autoreLabel->show();
        autoreLineEdit->show();    ;
        editoreLabel->show();
        editoreLineEdit->show();
        numPagineLabel->show();
        numPagineLineEdit->show();
        numFumettoLabel->show();
        numFumettoLineEdit->show();
        confermaFumettoButton->show();
    }
    if (tipoArticolo == "Manuale") {
        titoloLineEdit->show();
        titoloLabel->show();
        descrizioneLabel->show();
        descrizioneLineEdit->show();
        disponibilitaLabel->show();
        disponibilitaLineEdit->show();
        autoreLabel->show();
        autoreLineEdit->show();    ;
        editoreLabel->show();
        editoreLineEdit->show();
        numPagineLabel->show();
        numPagineLineEdit->show();
        argomentoLabel->show();
        argomentoLineEdit->show();
        confermaManualeButton->show();
    }
}

void FinestraAggiungiArticolo::confermaAggiuntaCD(){
    CD* cd = new CD();
    string newTitolo = (QString(titoloLineEdit->text())).toStdString();
    string newDescrizione = (QString(descrizioneLineEdit->text())).toStdString();
    cd->setTitolo(newTitolo);
    cd->setDescrizione(newDescrizione);
    bool ok;
    int dis = (QString(disponibilitaLineEdit->text())).toInt(&ok);
    if(ok){
        cd->setDisponibilita(dis);
    } else {
        cd->setDisponibilita(-1);
    }
    int dur = (QString(durataLineEdit->text())).toInt(&ok);
    if(ok){
        cd->setDurata(dur);
    } else {
        cd->setDurata(-1);
    }
    string newArtista = (QString(artistaLineEdit->text())).toStdString();
    cd->setArtista(newArtista);
    string newGenere = (QString(genereMusicaleLineEdit->text())).toStdString();
    cd->setGenereCD(newGenere);
    int brani = (QString(numBraniLineEdit->text())).toInt(&ok);
    if(ok){
        cd->setNumeroBrani(brani);
    } else {
        cd->setNumeroBrani(-1);
        }

    emit segnaleNuovoArticolo(cd);
    close();
}

void FinestraAggiungiArticolo::confermaAggiuntaDVD(){
    DVD* dvd = new DVD();
    string newTitolo = (QString(titoloLineEdit->text())).toStdString();
    string newDescrizione = (QString(descrizioneLineEdit->text())).toStdString();
    dvd->setTitolo(newTitolo);
    dvd->setDescrizione(newDescrizione);
    bool ok;
    int dis = (QString(disponibilitaLineEdit->text())).toInt(&ok);
    if(ok){
        dvd->setDisponibilita(dis);
    } else {
        dvd->setDisponibilita(-1);
    }
    int dur = (QString(durataLineEdit->text())).toInt(&ok);
    if(ok){
        dvd->setDurata(dur);
    } else {
        dvd->setDurata(-1);
    }
    string newRegista = (QString(registaLineEdit->text())).toStdString();
    dvd->setRegista(newRegista);
    int newVoto = (QString(votoLineEdit->text())).toInt(&ok);
    if(ok){
        dvd->setVoto(newVoto);
    } else {
        dvd->setVoto(-1.0);
    }


    emit segnaleNuovoArticolo(dvd);
    close();
}

void FinestraAggiungiArticolo::confermaAggiuntaManuale(){
    Manuale* manuale = new Manuale();
    string newTitolo = (QString(titoloLineEdit->text())).toStdString();
    string newDescrizione = (QString(descrizioneLineEdit->text())).toStdString();
    manuale->setTitolo(newTitolo);
    manuale->setDescrizione(newDescrizione);
    bool ok;
    int dis = (QString(disponibilitaLineEdit->text())).toInt(&ok);
    if(ok){
        manuale->setDisponibilita(dis);
    } else {
        manuale->setDisponibilita(-1);
    }
    string newAutore = (QString(autoreLineEdit->text())).toStdString();
    manuale->setAutore(newAutore);
    int newNumPagine = (QString(numPagineLineEdit->text())).toInt(&ok);
    if(ok){
        manuale->setPagine(newNumPagine);
    } else {
        manuale->setPagine(-1);
    }
    std::string newEditore = (QString(editoreLineEdit->text())).toStdString();
    manuale->setEditore(newEditore);
    std::string newArgomento = (QString(argomentoLineEdit->text())).toStdString();
    manuale->setArgomento(newArgomento);

    emit segnaleNuovoArticolo(manuale);
    close();
}

void FinestraAggiungiArticolo::confermaAggiuntaRomanzo(){
    Romanzo* romanzo = new Romanzo();
    string newTitolo = (QString(titoloLineEdit->text())).toStdString();
    string newDescrizione = (QString(descrizioneLineEdit->text())).toStdString();
    romanzo->setTitolo(newTitolo);
    romanzo->setDescrizione(newDescrizione);
    bool ok;
    int dis = (QString(disponibilitaLineEdit->text())).toInt(&ok);
    if(ok){
        romanzo->setDisponibilita(dis);
    } else {
        romanzo->setDisponibilita(-1);
    }
    string newAutore = (QString(autoreLineEdit->text())).toStdString();
    romanzo->setAutore(newAutore);
    int newNumPagine = (QString(numPagineLineEdit->text())).toInt(&ok);
    if(ok){
        romanzo->setPagine(newNumPagine);
    } else {
        romanzo->setPagine(-1);
    }
    string newEditore = (QString(editoreLineEdit->text())).toStdString();
    romanzo->setEditore(newEditore);
    string newGenere = (QString(genereLineEdit->text())).toStdString();
    romanzo->setGenereRomanzo(newGenere);

    emit segnaleNuovoArticolo(romanzo);
    close();
}

void FinestraAggiungiArticolo::confermaAggiuntaFumetto(){
    Fumetto* fumetto = new Fumetto();
    string newTitolo = (QString(titoloLineEdit->text())).toStdString();
    string newDescrizione = (QString(descrizioneLineEdit->text())).toStdString();
    fumetto->setTitolo(newTitolo);
    fumetto->setDescrizione(newDescrizione);
    bool ok;
    int dis = (QString(disponibilitaLineEdit->text())).toInt(&ok);
    if(ok){
        fumetto->setDisponibilita(dis);
    } else {
        fumetto->setDisponibilita(-1);
    }
    string newAutore = (QString(autoreLineEdit->text())).toStdString();
    fumetto->setAutore(newAutore);
    int newNumPagine = (QString(numPagineLineEdit->text())).toInt(&ok);
    if(ok){
        fumetto->setPagine(newNumPagine);
    } else {
        fumetto->setPagine(-1);
    }
    std::string newEditore = (QString(editoreLineEdit->text())).toStdString();
    fumetto->setEditore(newEditore);
    int newNumeroFumetto =  (QString(disponibilitaLineEdit->text())).toInt(&ok);
    if(ok){
        fumetto->setNumero(newNumeroFumetto);
    } else {
        fumetto->setNumero(-1);
    }

    emit segnaleNuovoArticolo(fumetto);
    close();
}
