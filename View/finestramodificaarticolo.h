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
    WidgetArticolo* widgetArticolo;
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
    FinestraModificaArticolo(WidgetArticolo* articolo, QWidget* parent = nullptr);
    ~FinestraModificaArticolo();

    void confermaModifiche();
    void eliminaArticolo();

    QString getTitolo() const;
    QString getDisponibilita() const;
    QString getDescrizione() const;
};

#endif // FINESTRAMODIFICAARTICOLO_H
