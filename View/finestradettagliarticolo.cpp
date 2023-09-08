#include "finestradettagliarticolo.h"
#include "finestramodificaarticolo.h"
#include "Model/cd.h"
#include "Model/dvd.h"


FinestraDettagliArticolo::FinestraDettagliArticolo(Articolo* art, QWidget* parent): QDialog(parent), articolo(art)
{
    //Inserimento delle label Titolo, Descrizione e Disponibilità dal widgetArticolo
    QVBoxLayout* layout = new QVBoxLayout(this);

    //WidgetArticolo: Titolo, Descrizione e Disponibilità
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
    disponibilita = new QLabel(QString("Disponibilità:"));
    disponibilitaLabel = new QLabel(QString::number(articolo->getDisponibilita()), this);


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
    riga->addWidget(immagineLabel);
    testi->addWidget(titoloLabel);
    testi->addWidget(descrizioneLabel);
    testi->addWidget(disponibilitaLabel);
    testi->addStretch();
    riga->addLayout(testi);
    //imposto layout
    riga->addStretch();
    layout->addLayout(riga);

    //DETTAGLI
    //Inserimento Label in base al Tipo Dinamico a 'layout'
    if(dynamic_cast<Disco*>(articolo)){
        durata = new QLabel(QString("Durata:"));
        durataLabel = new QLabel(QString::number(articolo->getDurata()), this);
        layout->addWidget(durata);
        layout->addWidget(durataLabel);

        if(dynamic_cast<CD*>(articolo)){
            artistaLabel = new QLabel(QString::fromStdString(articolo->getArtista()), this);
            genereMusicaleLabel = new QLabel(QString::fromStdString(articolo->getGenereCD()), this);
            numbrani = new QLabel(QString("Num. Brani:"));
            numbraniLabel = new QLabel(QString::number(articolo->getNumeroBrani()), this);
            layout->addWidget(artistaLabel);
            layout->addWidget(genereMusicaleLabel);
            layout->addWidget(numbrani);
            layout->addWidget(numbraniLabel);
            //Nascondo le altre, ma serve davvero?
            /*registaLabel->setVisible(false);
            votoLabel->setVisible(false);
            autoreLabel->setVisible(false);
            pagineLabel->setVisible(false);
            editoreLabel->setVisible(false);
            genereLabel->setVisible(false);
            argomentoLabel->setVisible(false);
            numeroLabel->setVisible(false);*/
        }
        if(dynamic_cast<DVD*>(articolo)){
            registaLabel = new QLabel(QString::fromStdString(articolo->getRegista()), this);
            voto = new QLabel(QString("Voto Critica:"));
            votoLabel = new QLabel(QString::number(articolo->getVoto()), this);
            layout->addWidget(registaLabel);
            layout->addWidget(voto);
            layout->addWidget(votoLabel);
            /*artistaLabel->setVisible(false);
            genereMusicaleLabel->setVisible(false);
            numbraniLabel->setVisible(false);
            autoreLabel->setVisible(false);
            pagineLabel->setVisible(false);
            editoreLabel->setVisible(false);
            genereLabel->setVisible(false);
            argomentoLabel->setVisible(false);
            numeroLabel->setVisible(false);*/
        }
    }
    if(dynamic_cast<Libro*>(articolo)){
        artistaLabel = new QLabel(QString::fromStdString(articolo->getArtista()), this);
        pagine = new QLabel(QString("Pagine:"));
        pagineLabel = new QLabel(QString::number(articolo->getPagine()), this);
        editoreLabel = new QLabel(QString::fromStdString(articolo->getEditore()), this);
        layout->addWidget(artistaLabel);
        layout->addWidget(pagine);
        layout->addWidget(pagineLabel);
        layout->addWidget(editoreLabel);

        if(dynamic_cast<Romanzo*>(articolo)){
            genereLabel = new QLabel(QString::fromStdString(articolo->getGenereRomanzo()), this);
            layout->addWidget(genereLabel);
            //Nascondi?
        }
        if(dynamic_cast<Manuale*>(articolo)){
            argomentoLabel = new QLabel(QString::fromStdString(articolo->getArgomento()), this);
            layout->addWidget(argomentoLabel);
            //Nascondi?
        }
        if(dynamic_cast<Fumetto*>(articolo)){
            QLabel* numero = new QLabel(QString("Numero:"));
            numeroLabel = new QLabel(QString::number(articolo->getNumero()), this);
            layout->addWidget(numero);
            layout->addWidget(numeroLabel);
            //Nascondi?
        }
    }
    //Devo nascondere le non necessarie?


    //BUTTONS
    modificaButton = new QPushButton("Modifica", this);
    layout->addWidget(modificaButton);

    //Connect
    connect(modificaButton, &QPushButton::clicked, this, &FinestraDettagliArticolo::apriFinestraModifica);
    //connect(this, SIGNAL(eliminaArticoloCommand(WidgetArticolo*, Articolo*)), this, SLOT(passaComandoEliminaArticolo(WidgetArticolo*, Articolo*)));
    //connect(this, SIGNAL(eliminaArticoloCommand), this, SLOT(passaComandoEliminaArticolo));
    //connect(this, SIGNAL(aggiornaDettagli(Articolo*)), this, SLOT(aggiornaDettagli(Articolo*)));

    //Imposta layout
    setLayout(layout);
    setWindowTitle("Dettaglio Articolo");
}


void FinestraDettagliArticolo::apriFinestraModifica(){
    FinestraModificaArticolo finestramodarticolo(articolo, this);
    //connect(FinestraEliminaArticolo, SIGNAL(articoloEliminato(Articolo*)), this, SLOT(gestisciArticoloEliminato(Articolo*)));
    connect(&finestramodarticolo, SIGNAL(modificheConfermate()), this, SLOT(refreshDettagli()));
    finestramodarticolo.exec();
}

/*void FinestraDettagliArticolo::passaComandoEliminaArticolo(Articolo* art) {
        // Emetti il segnale per passare il comando all'InterfacciaUtente
        emit articoloEliminatoCommand(art);
}*/

void FinestraDettagliArticolo::refreshDettagli(){
    titoloLabel->setText(QString::fromStdString(articolo->getTitolo()));
    descrizioneLabel->setText(QString::fromStdString(articolo->getDescrizione()));
    disponibilitaLabel->setText(QString::number(articolo->getDisponibilita()));
    if(dynamic_cast<Disco*>(articolo)){
        durataLabel->setText(QString::number(articolo->getDurata()));
        immagine = QPixmap(":img/dvd.png");

        if(dynamic_cast<CD*>(articolo)){
            artistaLabel->setText(QString::fromStdString(articolo->getArtista()));
            genereMusicaleLabel->setText(QString::fromStdString(articolo->getGenereCD()));
            numbraniLabel->setText(QString::number(articolo->getNumeroBrani()));

        }
        if(dynamic_cast<DVD*>(articolo)){
            registaLabel->setText(QString::fromStdString(articolo->getRegista()));
            votoLabel->setText(QString::number(articolo->getVoto()));
        }
    }
    if(dynamic_cast<Libro*>(articolo)){
        artistaLabel->setText(QString::fromStdString(articolo->getArtista()));
        pagineLabel->setText(QString::number(articolo->getPagine()));
        editoreLabel->setText(QString::fromStdString(articolo->getEditore()));
        immagine = QPixmap(":img/dvd.png");

        if(dynamic_cast<Romanzo*>(articolo)){
            genereLabel->setText(QString::fromStdString(articolo->getGenereRomanzo()));
        }
        if(dynamic_cast<Manuale*>(articolo)){
            argomentoLabel->setText(QString::fromStdString(articolo->getArgomento()));
        }
        if(dynamic_cast<Fumetto*>(articolo)){
            numeroLabel->setText(QString::number(articolo->getNumero()));
        }
    }
    immagine = immagine.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    immagineLabel->setPixmap(immagine);
    update();

    emit aggiornaLista();
}

void FinestraDettagliArticolo::refreshDettagli(Articolo* art) {
    articolo = art;
    refreshDettagli();
}
