#ifndef FINESTRAMODIFICAARTICOLO_H
#define FINESTRAMODIFICAARTICOLO_H

#include "finestradettagliarticolo.h"
#include "widgetarticolo.h"
#include <QLineEdit>
#include <QTextEdit>

class FinestraModificaArticolo : public QDialog
{
    Q_OBJECT
private:
    Articolo* articolo;

    QLineEdit* titoloLineEdit;
    QTextEdit* descrizioneTextEdit;
    QLineEdit* disponibilitaLineEdit;
    //Disco
    QLineEdit* durataLineEdit;
    //DVD
    QLineEdit* registaLineEdit;
    QLineEdit* votoLineEdit;
    //CD
    QLineEdit* artistaLineEdit;
    QLineEdit* genereMusicaleLineEdit;
    QLineEdit* numBraniLineEdit;
    //Libro
    QLineEdit* autoreLineEdit;
    QLineEdit* editoreLineEdit;
    QLineEdit* numPagineLineEdit;
    //Romanzo
    QLineEdit* genereLineEdit;
    //Manuale
    QLineEdit* argomentoLineEdit;
    //Fumetto
    QLineEdit* numFumettoLineEdit;


    QPushButton* confermaButton;
    QPushButton* eliminaButton;
    QPushButton* annullaButton;

public:
    FinestraModificaArticolo(Articolo* art, QWidget* parent = nullptr);
    ~FinestraModificaArticolo() = default;


signals:
    void signalEliminaArticolo(Articolo* art);
    void modificheConfermate();

public slots:
    void confermaModifiche();
    void eliminaArticolo(); //Emesso quando un viene premuto Elimina su wart e art, risponde la Listaarticoli
    //void modificatoArticolo(WidgetArticolo* wart, Articolo* art); //Emesso quando viene premuto Conferma, teoricamente l'articolo è già stato modificato bisogna aggiornare la vista
};

#endif // FINESTRAMODIFICAARTICOLO_H
