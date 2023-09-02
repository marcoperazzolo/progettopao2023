#include "finestradettagliarticolo.h"
#include "finestramodificaarticolo.h"

FinestraDettagliArticolo::FinestraDettagliArticolo(WidgetArticolo* articolo, QWidget* parent): QDialog(parent), widgetArticolo(articolo)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(widgetArticolo);

    modificaButton = new QPushButton("Modifica", this);
    layout->addWidget(modificaButton);

    connect(modificaButton, &QPushButton::clicked, this, &FinestraDettagliArticolo::apriFinestraModifica);

    setLayout(layout);
    setWindowTitle("Dettaglio Articolo");
}

FinestraDettagliArticolo::~FinestraDettagliArticolo() = default;

void FinestraDettagliArticolo::apriFinestraModifica() {
    //QListWidgetItem* item = lista->currentItem(); // Ottieni l'oggetto QListWidgetItem selezionato

    FinestraModificaArticolo modificaDialog(widgetArticolo, this);
    if (modificaDialog.exec() == QDialog::Accepted) {
        // Aggiorna i dettagli dell'articolo
        widgetArticolo->setTitolo((modificaDialog.getTitolo()).toStdString());
        widgetArticolo->setDescrizione((modificaDialog.getDescrizione()).toStdString());
        widgetArticolo->setDisponibilita(modificaDialog.getDisponibilita().toInt());

        //int index = lista->row(item);
        //lista->aggiornaArticolo(index, (modificaDialog.getTitolo()).toStdString(), (modificaDialog.getDescrizione()).toStdString(), modificaDialog.getDisponibilita().toInt());
    }
}
