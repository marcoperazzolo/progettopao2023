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
    QPushButton* confermaButton;
    QPushButton* annullaButton;
public:
    FinestraModificaArticolo(WidgetArticolo* articolo, QWidget* parent = nullptr);
    ~FinestraModificaArticolo();

    void confermaModifiche();
    QString getTitolo() const;
    QString getDisponibilita() const;
    QString getDescrizione() const;
};

#endif // FINESTRAMODIFICAARTICOLO_H
