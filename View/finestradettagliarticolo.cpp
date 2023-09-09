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
    riga->addWidget(immagineLabel);
    testi->addWidget(titoloLabel);
    testi->addWidget(descrizioneLabel);
    testi->addWidget(disponibilita);
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
            artista = new QLabel(QString("Artista:"));
            artistaLabel = new QLabel(QString::fromStdString(articolo->getArtista()), this);
            genere = new QLabel(QString("Genere:"));
            genereMusicaleLabel = new QLabel(QString::fromStdString(articolo->getGenereCD()), this);
            numbrani = new QLabel(QString("Num. Brani:"));
            numbraniLabel = new QLabel(QString::number(articolo->getNumeroBrani()), this);
            layout->addWidget(artista);
            layout->addWidget(artistaLabel);
            layout->addWidget(genere);
            layout->addWidget(genereMusicaleLabel);
            layout->addWidget(numbrani);
            layout->addWidget(numbraniLabel);
        }
        if(dynamic_cast<DVD*>(articolo)){
            regista = new QLabel(QString("Regista:"));
            registaLabel = new QLabel(QString::fromStdString(articolo->getRegista()), this);
            voto = new QLabel(QString("Voto Critica:"));
            votoLabel = new QLabel(QString::number(articolo->getVoto()), this);
            layout->addWidget(regista);
            layout->addWidget(registaLabel);
            layout->addWidget(voto);
            layout->addWidget(votoLabel);
        }
    }
    if(dynamic_cast<Libro*>(articolo)){
        autore = new QLabel(QString("Autore:"));
        autoreLabel = new QLabel(QString::fromStdString(articolo->getAutore()), this);
        pagine = new QLabel(QString("Pagine:"));
        pagineLabel = new QLabel(QString::number(articolo->getPagine()), this);
        editore = new QLabel(QString("Editore:"));
        editoreLabel = new QLabel(QString::fromStdString(articolo->getEditore()), this);
        layout->addWidget(autore);
        layout->addWidget(autoreLabel);
        layout->addWidget(pagine);
        layout->addWidget(pagineLabel);
        layout->addWidget(editore);
        layout->addWidget(editoreLabel);

        if(dynamic_cast<Romanzo*>(articolo)){
            genere = new QLabel(QString("Genere:"));
            genereLabel = new QLabel(QString::fromStdString(articolo->getGenereRomanzo()), this);
            layout->addWidget(genere);
            layout->addWidget(genereLabel);
        }
        if(dynamic_cast<Manuale*>(articolo)){
            argomento = new QLabel(QString("Argomento:"));
            argomentoLabel = new QLabel(QString::fromStdString(articolo->getArgomento()), this);
            layout->addWidget(argomento);
            layout->addWidget(argomentoLabel);
        }
        if(dynamic_cast<Fumetto*>(articolo)){
            QLabel* numero = new QLabel(QString("Numero:"));
            numeroLabel = new QLabel(QString::number(articolo->getNumero()), this);
            layout->addWidget(numero);
            layout->addWidget(numeroLabel);
        }
    }


    //BUTTONS
    modificaButton = new QPushButton("Modifica", this);
    layout->addWidget(modificaButton);

    //Connect
    connect(modificaButton, &QPushButton::clicked, this, &FinestraDettagliArticolo::apriFinestraModifica);

    //Imposta layout
    setLayout(layout);
    setWindowTitle("Dettaglio Articolo");
}

void FinestraDettagliArticolo::apriFinestraModifica(){
    FinestraModificaArticolo finestramodarticolo(articolo, this);
    connect(&finestramodarticolo, SIGNAL(modificheConfermate()), this, SLOT(refreshDettagli()));
    connect(&finestramodarticolo, SIGNAL(signalEliminaArticolo(Articolo*)), this, SLOT(slotEliminaArticolo(Articolo*)));
    finestramodarticolo.exec();
}

void FinestraDettagliArticolo::slotEliminaArticolo(Articolo* art) {
        emit articoloEliminatoSignal(art);
        accept();
}

void FinestraDettagliArticolo::refreshDettagli(){
    titoloLabel->setText(QString::fromStdString(articolo->getTitolo()));
    descrizioneLabel->setText(QString::fromStdString(articolo->getDescrizione()));
    disponibilitaLabel->setText(QString::number(articolo->getDisponibilita()));
    if(dynamic_cast<Disco*>(articolo)){
        durataLabel->setText(QString::number(articolo->getDurata()));

        if(dynamic_cast<CD*>(articolo)){
            artistaLabel->setText(QString::fromStdString(articolo->getArtista()));
            genereMusicaleLabel->setText(QString::fromStdString(articolo->getGenereCD()));
            numbraniLabel->setText(QString::number(articolo->getNumeroBrani()));
            immagine = QPixmap(":/img/cd.png");


        }
        if(dynamic_cast<DVD*>(articolo)){
            registaLabel->setText(QString::fromStdString(articolo->getRegista()));
            votoLabel->setText(QString::number(articolo->getVoto()));
            immagine = QPixmap(":/img/dvd.png");

        }
    }
    if(dynamic_cast<Libro*>(articolo)){
        autoreLabel->setText(QString::fromStdString(articolo->getAutore()));
        pagineLabel->setText(QString::number(articolo->getPagine()));
        editoreLabel->setText(QString::fromStdString(articolo->getEditore()));

        if(dynamic_cast<Romanzo*>(articolo)){
            genereLabel->setText(QString::fromStdString(articolo->getGenereRomanzo()));
            immagine = QPixmap(":/img/romanzo.png");

        }
        if(dynamic_cast<Manuale*>(articolo)){
            argomentoLabel->setText(QString::fromStdString(articolo->getArgomento()));
            immagine = QPixmap(":/img/manuale.png");

        }
        if(dynamic_cast<Fumetto*>(articolo)){
            numeroLabel->setText(QString::number(articolo->getNumero()));
            immagine = QPixmap(":/img/fumetto.png");

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
