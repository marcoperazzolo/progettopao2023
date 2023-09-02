#include "finestramodificaarticolo.h"


FinestraModificaArticolo::FinestraModificaArticolo(WidgetArticolo* articolo, QWidget* parent) : QDialog(parent), widgetArticolo(articolo) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        //CAMPI : lettura dal WidgetArticolo
        titoloLineEdit = new QLineEdit(QString::fromStdString(widgetArticolo->getTitolo()), this);
        descrizioneTextEdit = new QTextEdit(QString::fromStdString(widgetArticolo->getDescrizione()), this);
        disponibilitaLineEdit = new QLineEdit(QString::number(widgetArticolo->getDisponibilita()), this);   
        layout->addWidget(titoloLineEdit);
        layout->addWidget(descrizioneTextEdit);
        layout->addWidget(disponibilitaLineEdit);

        //BUTTONS
        confermaButton = new QPushButton("Conferma", this);
        annullaButton = new QPushButton("Annulla", this);
        QHBoxLayout* buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(confermaButton);
        buttonLayout->addWidget(annullaButton);
        layout->addLayout(buttonLayout);

        //CONNECT
        connect(confermaButton, &QPushButton::clicked, this, &FinestraModificaArticolo::confermaModifiche);
        connect(annullaButton, &QPushButton::clicked, this, &FinestraModificaArticolo::reject);

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
    // Ottieni i nuovi valori dai campi di input
    QString nuovoTitolo = getTitolo();
    QString nuovaDescrizione = getDescrizione();
    QString nuovaDisponibilita = getDisponibilita();

    // Aggiorna l'oggetto WidgetArticolo con i nuovi valori
    widgetArticolo->setTitolo(nuovoTitolo.toStdString());
    widgetArticolo->setDescrizione(nuovaDescrizione.toStdString());
    widgetArticolo->setDisponibilita(nuovaDisponibilita.toInt());

    // Chiudi la finestra di modifica
    accept();
}

