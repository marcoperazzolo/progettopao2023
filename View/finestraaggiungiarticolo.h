#ifndef FINESTRAAGGIUNGIARTICOLO_H
#define FINESTRAAGGIUNGIARTICOLO_H

#include <QDialog>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include "widgetarticolo.h"

class FinestraAggiungiArticolo : public QDialog
{
    Q_OBJECT
private:
    //QLINEEDIT
    QLineEdit* titoloLineEdit;
    QLineEdit* descrizioneLineEdit;
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

    //LABELS
    QLabel* titoloLabel;
    QLabel* descrizioneLabel;
    QLabel* disponibilitaLabel;
    QLabel* durataLabel;
    QLabel* registaLabel;
    QLabel* votoLabel;
    QLabel* artistaLabel;
    QLabel* genereMusicaleLabel;
    QLabel* numBraniLabel;
    QLabel* autoreLabel;
    QLabel* editoreLabel;
    QLabel* numPagineLabel;
    QLabel* genereLabel;
    QLabel* argomentoLabel;
    QLabel* numFumettoLabel;

    QString tipoArticolo;
    QComboBox* tipoArticoloComboBox;
    //BUTTONS
    QPushButton* confermaCDButton;
    QPushButton* confermaDVDButton;
    QPushButton* confermaManualeButton;
    QPushButton* confermaRomanzoButton;
    QPushButton* confermaFumettoButton;


    QPushButton* annullaButton;

public:
    FinestraAggiungiArticolo(QWidget* parent = nullptr);
     ~FinestraAggiungiArticolo() = default;
public slots:
    void tipoArticoloCambiato();

    void confermaAggiuntaCD();
    void confermaAggiuntaDVD();
    void confermaAggiuntaManuale();
    void confermaAggiuntaRomanzo();
    void confermaAggiuntaFumetto();
signals:
    void segnaleNuovoArticolo(Articolo* art);
};

#endif // FINESTRAAGGIUNGIARTICOLO_H
