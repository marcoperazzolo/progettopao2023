#include "finestradettagliarticolo.h"
#include "finestramodificaarticolo.h"

FinestraDettagliArticolo::FinestraDettagliArticolo(WidgetArticolo* articolo, QWidget* parent): QDialog(parent), widgetArticolo(articolo)
{
    widgetArticolo = articolo;
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(widgetArticolo);

    if(dynamic_cast<Disco*>(widgetArticolo->getArticolo())){
        layout->addWidget(widgetArticolo->getDurataLabel());
        if(dynamic_cast<CD*>(widgetArticolo->getArticolo())){
            layout->addWidget(widgetArticolo->getArtistaLabel());
            layout->addWidget(widgetArticolo->getGenereMusicaleLabel());
            layout->addWidget(widgetArticolo->getNumbraniLabel());
        }
        if(dynamic_cast<DVD*>(widgetArticolo->getArticolo())){
            layout->addWidget(widgetArticolo->getRegistaLabel());
            layout->addWidget(widgetArticolo->getVotoLabel());
        }
    }
    if(dynamic_cast<Libro*>(widgetArticolo->getArticolo())){
        layout->addWidget(widgetArticolo->getAutoreLabel());
        layout->addWidget(widgetArticolo->getPagineLabel());
        layout->addWidget(widgetArticolo->getEditoreLabel());
        if(dynamic_cast<Romanzo*>(widgetArticolo->getArticolo())){
            layout->addWidget(widgetArticolo->getGenereLabel());
        }
        if(dynamic_cast<Manuale*>(widgetArticolo->getArticolo())){
            layout->addWidget(widgetArticolo->getArgomentoLabel());
        }
        if(dynamic_cast<Fumetto*>(widgetArticolo->getArticolo())){
            layout->addWidget(widgetArticolo->getNumeroLabel());
        }
    }

    modificaButton = new QPushButton("Modifica", this);
    layout->addWidget(modificaButton);

    connect(modificaButton, &QPushButton::clicked, this, &FinestraDettagliArticolo::apriFinestraModifica);

    setLayout(layout);
    setWindowTitle("Dettaglio Articolo");
}

FinestraDettagliArticolo::~FinestraDettagliArticolo() = default;

void FinestraDettagliArticolo::apriFinestraModifica(){
    //QListWidgetItem* item = lista->currentItem(); // Ottieni l'oggetto QListWidgetItem selezionato
    FinestraModificaArticolo modificaDialog(widgetArticolo, this);
    //if (modificaDialog.exec() == QDialog::Accepted) {
        // Aggiorna i dettagli dell'articolo
        //widgetArticolo->setTitolo((modificaDialog.getTitolo()).toStdString());
        //widgetArticolo->setDescrizione((modificaDialog.getDescrizione()).toStdString());
        //widgetArticolo->setDisponibilita(modificaDialog.getDisponibilita().toInt());

        //int index = lista->row(item);
        //lista->aggiornaArticolo(index, (modificaDialog.getTitolo()).toStdString(), (modificaDialog.getDescrizione()).toStdString(), modificaDialog.getDisponibilita().toInt());
}
