#ifndef FINESTRAAGGIUNGIARTICOLO_H
#define FINESTRAAGGIUNGIARTICOLO_H

#include <QDialog>
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
    QLineEdit* titoloLineEdit;
    QTextEdit* descrizioneTextEdit;
    QLineEdit* disponibilitaLineEdit;
    QPushButton* confermaButton;
    QPushButton* annullaButton;

public:
    FinestraAggiungiArticolo(QWidget* parent = nullptr);
     ~FinestraAggiungiArticolo()
};

#endif // FINESTRAAGGIUNGIARTICOLO_H
