#include "finestramodificaarticolo.h"


FinestraModificaArticolo::FinestraModificaArticolo(WidgetArticolo* articolo, QWidget* parent) : QDialog(parent), widgetArticolo(articolo) {    
    QVBoxLayout* layout = new QVBoxLayout(this);

        //CAMPI EDITABILI : lettura dal WidgetArticolo
        titoloLineEdit = new QLineEdit(QString((widgetArticolo->getTitoloLabel())->text()), this);
        descrizioneTextEdit = new QTextEdit(QString((widgetArticolo->getDescrizioneLabel())->text()), this);
        disponibilitaLineEdit = new QLineEdit(QString((widgetArticolo->getDisponibilitaLabel())->text()), this);
        layout->addWidget(titoloLineEdit);
        layout->addWidget(descrizioneTextEdit);
        layout->addWidget(disponibilitaLineEdit);

        if(dynamic_cast<Disco*>(widgetArticolo->getArticolo())){
            durataLineEdit = new QLineEdit(QString((widgetArticolo->getDurataLabel())->text()), this);
            layout->addWidget(durataLineEdit);

            if(dynamic_cast<CD*>(widgetArticolo->getArticolo())){
                artistaLineEdit = new QLineEdit(QString((widgetArticolo->getArtistaLabel())->text()), this);
                genereMusicaleLineEdit = new QLineEdit(QString((widgetArticolo->getGenereMusicaleLabel())->text()), this);
                numBraniLineEdit = new QLineEdit(QString((widgetArticolo->getNumbraniLabel())->text()), this);
                layout->addWidget(artistaLineEdit);
                layout->addWidget(genereMusicaleLineEdit);
                layout->addWidget(numBraniLineEdit);
            }
            if(dynamic_cast<DVD*>(widgetArticolo->getArticolo())){
                registaLineEdit = new QLineEdit(QString((widgetArticolo->getRegistaLabel())->text()), this);
                votoLineEdit = new QLineEdit(QString((widgetArticolo->getVotoLabel())->text()), this);
                layout->addWidget(registaLineEdit);
                layout->addWidget(votoLineEdit);
            }
        }
        if(dynamic_cast<Libro*>(widgetArticolo->getArticolo())){
            autoreLineEdit = new QLineEdit(QString((widgetArticolo->getAutoreLabel())->text()), this);
            editoreLineEdit = new QLineEdit(QString((widgetArticolo->getEditoreLabel())->text()), this);
            numPagineLineEdit = new QLineEdit(QString((widgetArticolo->getPagineLabel())->text()), this);
            layout->addWidget(autoreLineEdit);
            layout->addWidget(editoreLineEdit);
            layout->addWidget(numPagineLineEdit);

            if(dynamic_cast<Romanzo*>(widgetArticolo->getArticolo())){
                genereLineEdit = new QLineEdit(QString((widgetArticolo->getGenereLabel())->text()), this);
                layout->addWidget(genereLineEdit);
            }
            if(dynamic_cast<Manuale*>(widgetArticolo->getArticolo())){
                argomentoLineEdit = new QLineEdit(QString((widgetArticolo->getArgomentoLabel())->text()), this);
                layout->addWidget(argomentoLineEdit);
            }
            if(dynamic_cast<Fumetto*>(widgetArticolo->getArticolo())){
                numFumettoLineEdit = new QLineEdit(QString((widgetArticolo->getNumeroLabel())->text()), this);
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

        setLayout(layout);
        setWindowTitle("Modifica Articolo");
}




FinestraModificaArticolo::~FinestraModificaArticolo() = default;

//getter tipo QString
QString FinestraModificaArticolo::getTitolo() const {
    return titoloLineEdit->text();
}
QString FinestraModificaArticolo::getDisponibilita() const {
    return disponibilitaLineEdit->text();
}

QString FinestraModificaArticolo::getDescrizione() const {
    return descrizioneTextEdit->toPlainText();
}

//Aggiorna Wi
void FinestraModificaArticolo::confermaModifiche() {

    //Aggiorna Titolo, Desc Labels del Widget
    widgetArticolo->setTitolo((QString(titoloLineEdit->text())).toStdString());
    widgetArticolo->setDescrizione((QString(descrizioneTextEdit->toPlainText())).toStdString());

    //Aggiorna l'articolo
    widgetArticolo->getArticolo()->setTitolo((QString(titoloLineEdit->text())).toStdString());
    widgetArticolo->getArticolo()->setDescrizione((QString(descrizioneTextEdit->toPlainText())).toStdString());

    //controllo string->int, setta Disponibilità ad Articolo e Widget
    if(std::stoi(((QString(disponibilitaLineEdit->text())).toStdString()))){
        widgetArticolo->getArticolo()->setDisponibilita(std::stoi(((QString(disponibilitaLineEdit->text())).toStdString())));
        widgetArticolo->setDisponibilita(std::stoi(((QString(disponibilitaLineEdit->text())).toStdString())));
    } else {
        widgetArticolo->getArticolo()->setDisponibilita(-1);
        widgetArticolo->setDisponibilita(-1);
    }

    //in base al tipo setta campi (Articolo) e labels (WidgetArticolo)
    if(Disco* disco = dynamic_cast<Disco*>(widgetArticolo->getArticolo())){
        //Durata
        if(std::stoi(((QString(durataLineEdit->text())).toStdString()))){
            disco->setDurata(std::stoi(((QString(durataLineEdit->text())).toStdString())));
            widgetArticolo->setDurata(std::stoi(((QString(durataLineEdit->text())).toStdString())));
        } else {
            widgetArticolo->getArticolo()->setDisponibilita(-1);
            widgetArticolo->setDisponibilita(-1);
        }

        if(CD* cd =dynamic_cast<CD*>(widgetArticolo->getArticolo())){
            cd->setArtista((QString(artistaLineEdit->text())).toStdString());
            widgetArticolo->setArtista(QString(artistaLineEdit->text()).toStdString());
            cd->setGenere((QString(genereMusicaleLineEdit->text())).toStdString());
            widgetArticolo->setGenereMusicale(QString(genereMusicaleLineEdit->text()).toStdString());
            if(std::stoi(((QString(numBraniLineEdit->text())).toStdString()))){
                cd->setNumeroBrani(std::stoi(((QString(numBraniLineEdit->text())).toStdString())));
                widgetArticolo->setNumeroBrani(std::stoi(((QString(numBraniLineEdit->text())).toStdString())));
            } else {
                cd->setDisponibilita(0);
                widgetArticolo->setDisponibilita(0);
            }
        }
        if(DVD* dvd = dynamic_cast<DVD*>(widgetArticolo->getArticolo())){
            dvd->setRegista((QString(registaLineEdit->text())).toStdString());
            widgetArticolo->setRegista(QString(registaLineEdit->text()).toStdString());
            if(std::stod(((QString(votoLineEdit->text())).toStdString()))){
                dvd->setVoto(std::stoi(((QString(votoLineEdit->text())).toStdString())));
                widgetArticolo->setVoto(std::stoi(((QString(votoLineEdit->text())).toStdString())));
            } else {
                dvd->setVoto(0.0);
                widgetArticolo->setVoto(0.0);
            }
        }
    }
    if(Libro* libro = dynamic_cast<Libro*>(widgetArticolo->getArticolo())){
        libro->setAutore((QString(autoreLineEdit->text())).toStdString());
        widgetArticolo->setAutore(QString(autoreLineEdit->text()).toStdString());
        if(std::stoi(((QString(numPagineLineEdit->text())).toStdString()))){
            libro->setPagine(std::stoi(((QString(numPagineLineEdit->text())).toStdString())));
            widgetArticolo->setPagine(std::stoi(((QString(numPagineLineEdit->text())).toStdString())));
        } else {
            libro->setPagine(0);
            widgetArticolo->setPagine(0);
        }
        libro->setEditore((QString(editoreLineEdit->text())).toStdString());
        widgetArticolo->setEditore(QString(editoreLineEdit->text()).toStdString());

        if(Romanzo* romanzo = dynamic_cast<Romanzo*>(widgetArticolo->getArticolo())){
            romanzo->setGenere((QString(genereLineEdit->text())).toStdString());
            widgetArticolo->setGenere(QString(genereLineEdit->text()).toStdString());
        }
        if(Manuale* manuale = dynamic_cast<Manuale*>(widgetArticolo->getArticolo())){
            manuale->setArgomento((QString(argomentoLineEdit->text())).toStdString());
            widgetArticolo->setArgomento(QString(argomentoLineEdit->text()).toStdString());
        }
        if(Fumetto* fumetto = dynamic_cast<Fumetto*>(widgetArticolo->getArticolo())){
            if(std::stoi(((QString(numFumettoLineEdit->text())).toStdString()))){
                fumetto->setNumero(std::stoi(((QString(numFumettoLineEdit->text())).toStdString())));
                widgetArticolo->setNumFumetto(std::stoi(((QString(numFumettoLineEdit->text())).toStdString())));
            } else {
                fumetto->setNumero(0);
                widgetArticolo->setNumFumetto(0);
            }
        }
    }
    // Chiudi la finestra di modifica
    //refresh del widget
    //widgetArticolo->refresh();, non serve a quanto pare
    accept();
}

void FinestraModificaArticolo::eliminaArticolo() {
    widgetArticolo->getArticolo()->~Articolo();
    delete widgetArticolo;

}
