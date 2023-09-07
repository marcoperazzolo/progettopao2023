#include "finestraaggiungiarticolo.h"

FinestraAggiungiArticolo::FinestraAggiungiArticolo(QWidget* parent) : QDialog(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    //CAMPI : lettura dal WidgetArticolo
    QLabel* titoloLabel = new QLabel("Titolo:", this);
    titoloLineEdit = new QLineEdit(this);
    QLabel* descrizioneLabel = new QLabel("Descrizione:", this);
    descrizioneTextEdit = new QTextEdit(this);
    QLabel* disponibilitaLabel = new QLabel("Disponibilità:", this);
    layout->addWidget(titoloLabel);
    layout->addWidget(titoloLineEdit);
    layout->addWidget(descrizioneLabel);
    layout->addWidget(descrizioneTextEdit);
    layout->addWidget(disponibilitaLabel);
    layout->addWidget(disponibilitaLineEdit);

    //BUTTONS
    confermaButton = new QPushButton("Conferma", this);
    annullaButton = new QPushButton("Annulla", this);
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(confermaButton);
    buttonLayout->addWidget(annullaButton);
    layout->addLayout(buttonLayout);

    //CONNECT
    //connect(confermaButton, &QPushButton::clicked, this, &FinestraModificaArticolo::confermaModifiche);
    //connect(annullaButton, &QPushButton::clicked, this, &FinestraModificaArticolo::reject);

    setLayout(layout);
    setWindowTitle("Modifica Articolo");
}

FinestraAggiungiArticolo::~FinestraAggiungiArticolo() = default;
