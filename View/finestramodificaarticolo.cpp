#include "finestramodificaarticolo.h"


FinestraModificaArticolo::FinestraModificaArticolo(Articolo* art, QWidget* parent) : QDialog(parent), articolo(art) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        //CAMPI EDITABILI : lettura da Articolo
        titoloLineEdit = new QLineEdit(QString::fromStdString(articolo->getTitolo()), this);
        descrizioneTextEdit = new QTextEdit(QString::fromStdString(articolo->getDescrizione()), this);
        disponibilitaLineEdit = new QLineEdit(QString::number(articolo->getDisponibilita()), this);
        layout->addWidget(titoloLineEdit);
        layout->addWidget(descrizioneTextEdit);
        layout->addWidget(disponibilitaLineEdit);

        //CAMPI EDITABILI : lettura in base al TD di articolo
        if(dynamic_cast<Disco*>(articolo)){
            durataLineEdit = new QLineEdit(QString::number(articolo->getDurata()), this);
            layout->addWidget(durataLineEdit);

            if(dynamic_cast<CD*>(articolo)){
                artistaLineEdit = new QLineEdit(QString::fromStdString(articolo->getArtista()), this);
                genereMusicaleLineEdit = new QLineEdit(QString::fromStdString(articolo->getGenereCD()), this);
                numBraniLineEdit = new QLineEdit(QString::number(articolo->getNumeroBrani()), this);
                layout->addWidget(artistaLineEdit);
                layout->addWidget(genereMusicaleLineEdit);
                layout->addWidget(numBraniLineEdit);
            }
            if(dynamic_cast<DVD*>(articolo)){
                registaLineEdit = new QLineEdit(QString::fromStdString(articolo->getRegista()), this);
                votoLineEdit = new QLineEdit(QString::number(articolo->getVoto()), this);
                layout->addWidget(registaLineEdit);
                layout->addWidget(votoLineEdit);
            }
        }
        if(dynamic_cast<Libro*>(articolo)){
            autoreLineEdit = new QLineEdit(QString::fromStdString(articolo->getAutore()), this);
            editoreLineEdit = new QLineEdit(QString::fromStdString(articolo->getEditore()), this);
            numPagineLineEdit = new QLineEdit(QString::number(articolo->getPagine()), this);
            layout->addWidget(autoreLineEdit);
            layout->addWidget(editoreLineEdit);
            layout->addWidget(numPagineLineEdit);

            if(dynamic_cast<Romanzo*>(articolo)){
                genereLineEdit = new QLineEdit(QString::fromStdString(articolo->getGenereRomanzo()), this);
                layout->addWidget(genereLineEdit);
            }
            if(dynamic_cast<Manuale*>(articolo)){
                argomentoLineEdit = new QLineEdit(QString::fromStdString(articolo->getArgomento()), this);
                layout->addWidget(argomentoLineEdit);
            }
            if(dynamic_cast<Fumetto*>(articolo)){
                numFumettoLineEdit = new QLineEdit(QString::number(articolo->getNumero()), this);
                layout->addWidget(numFumettoLineEdit);
            }
        }

        //BUTTONS
        confermaButton = new QPushButton("Conferma", this);
        annullaButton = new QPushButton("Annulla", this);
        eliminaButton = new QPushButton("Elimina", this);

        QHBoxLayout* buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(annullaButton);
        buttonLayout->addWidget(eliminaButton);
        buttonLayout->addWidget(confermaButton);

        layout->addLayout(buttonLayout);

        //CONNECT
        connect(confermaButton, &QPushButton::clicked, this, &FinestraModificaArticolo::confermaModifiche);
        connect(annullaButton, &QPushButton::clicked, this, &FinestraModificaArticolo::reject);
        connect(eliminaButton, &QPushButton::clicked, this, &FinestraModificaArticolo::eliminaArticolo);

        //Imposta il layout
        setLayout(layout);
        setWindowTitle("Modifica Articolo");
}


void FinestraModificaArticolo::confermaModifiche() {

    //Aggiorna Titolo, Desc, Labels del Widget
    string newTitolo = (QString(titoloLineEdit->text())).toStdString();
    string newDescrizione = (QString(descrizioneTextEdit->toPlainText())).toStdString();
    articolo->setTitolo(newTitolo);
    articolo->setDescrizione(newDescrizione);
    bool ok;
    int newDisponibilita = (QString(disponibilitaLineEdit->text())).toInt(&ok);
    if(ok){
        articolo->setDisponibilita(newDisponibilita);
    } else {
        articolo->setDisponibilita(-1);
    }

    //In base al tipo setta campi (Articolo)
        //DISCO
        if(Disco* disco = dynamic_cast<Disco*>(articolo)){
            //Durata
            int newDurata = (QString(durataLineEdit->text())).toInt(&ok);
            if(ok){
                disco->setDurata(newDurata);
            } else {
                disco->setDurata(-1);
            }

            //CD
            if(CD* cd =dynamic_cast<CD*>(articolo)){
                //Artista
                string newArtista = (QString(artistaLineEdit->text())).toStdString();
                cd->setArtista(newArtista);

                //Genere
                string newGenere = (QString(genereMusicaleLineEdit->text())).toStdString();
                cd->setGenereCD(newGenere);

                int newNumBrani = (QString(numBraniLineEdit->text())).toInt(&ok);
                //Numero Brani
                if(ok){
                    cd->setNumeroBrani(newNumBrani);
                } else {
                    cd->setNumeroBrani(-1);
                }
            }

            //DVD
            if(DVD* dvd = dynamic_cast<DVD*>(articolo)){
                //Regista
                string newRegista = (QString(registaLineEdit->text())).toStdString();
                dvd->setRegista(newRegista);

                //Voto
                int newVoto = (QString(votoLineEdit->text())).toInt(&ok);
                if(ok){
                    dvd->setVoto(newVoto);
                } else {
                    dvd->setVoto(-1.0);
                }
            }
        }

        //LIBRO
        if(Libro* libro = dynamic_cast<Libro*>(articolo)){
            //Autore
            std::string newAutore = (QString(autoreLineEdit->text())).toStdString();
            libro->setAutore(newAutore);
            //Pagine
            int newNumPagine = (QString(numPagineLineEdit->text())).toInt(&ok);
            if(ok){
                libro->setPagine(newNumPagine);
            } else {
                libro->setPagine(-1);
            }

            //Editore
            std::string newEditore = (QString(editoreLineEdit->text())).toStdString();
            libro->setEditore(newEditore);

            //ROMANZO
            if(Romanzo* romanzo = dynamic_cast<Romanzo*>(libro)){

                //Genere
                std::string newGenere = (QString(genereLineEdit->text())).toStdString();
                romanzo->setGenereRomanzo(newGenere);
            }

            //MANUALE
            if(Manuale* manuale = dynamic_cast<Manuale*>(articolo)){
                //Argomento
                std::string newArgomento = (QString(argomentoLineEdit->text())).toStdString();
                manuale->setArgomento(newArgomento);
            }

            //FUMETTO
            if(Fumetto* fumetto = dynamic_cast<Fumetto*>(articolo)){

                //Numero Fumetto
                int newNumeroFumetto = (QString(numFumettoLineEdit->text())).toInt(&ok);
                if(ok){
                    fumetto->setNumero(newNumeroFumetto);
                } else {
                    fumetto->setNumero(-1);
                }
            }
        }


    //REFRESH
    emit modificheConfermate();

    //accept();
    close();
}

void FinestraModificaArticolo::eliminaArticolo() {
    emit signalEliminaArticolo(articolo);
    close();
}
