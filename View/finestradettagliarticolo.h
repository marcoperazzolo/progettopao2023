#ifndef FINESTRADETTAGLIARTICOLO_H
#define FINESTRADETTAGLIARTICOLO_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "widgetarticolo.h"
#include "listaarticoli.h"
#include "finestramodificaarticolo.h"

class FinestraDettagliArticolo : public QDialog
{
    Q_OBJECT
private:
    WidgetArticolo* widgetArticolo;
    Articolo* articolo;

    //Layout
    QHBoxLayout* riga;
    QVBoxLayout* testi;

    //LABELS
    //Labels
        QLabel* titoloLabel;
        QLabel* descrizioneLabel;
        QLabel* disponibilita;
        QLabel* disponibilitaLabel;
        QFont fontTitolo;

    //Immagine
        QLabel* immagineLabel;
        QPixmap immagine;

    //Disco
        QLabel* durata;
        QLabel* durataLabel;
    //CD
        QLabel* artista;
        QLabel* artistaLabel;
        QLabel* genere;
        QLabel* genereMusicaleLabel;
        QLabel* numbrani;
        QLabel* numbraniLabel;
    //DVD
        QLabel* regista;
        QLabel* registaLabel;
        QLabel* voto;
        QLabel* votoLabel;

    //Libro
        QLabel* autore;
        QLabel* autoreLabel;
        QLabel* pagine;
        QLabel* pagineLabel;
        QLabel* editore;
        QLabel* editoreLabel;
    //Romanzo
        QLabel* genereLabel;
    //Manuale
        QLabel* argomento;
        QLabel* argomentoLabel;
    //Fumetto
        QLabel* numero;
        QLabel* numeroLabel;

    QPushButton* modificaButton;

public:
    FinestraDettagliArticolo(Articolo* art, QWidget* parent = nullptr);
    ~FinestraDettagliArticolo() = default;

public slots:
    void apriFinestraModifica();
    void refreshDettagli();
    void refreshDettagli(Articolo* art);
    void slotEliminaArticolo(Articolo* art);

signals:
    void articoloEliminatoSignal(Articolo* art);
    void aggiornaLista();
};

#endif // FINESTRADETTAGLIARTICOLO_H
