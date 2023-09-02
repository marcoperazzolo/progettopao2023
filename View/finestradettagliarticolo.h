#ifndef FINESTRADETTAGLIARTICOLO_H
#define FINESTRADETTAGLIARTICOLO_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include "widgetarticolo.h"
#include "listaarticoli.h"

class FinestraDettagliArticolo : public QDialog
{
    Q_OBJECT
private:
    WidgetArticolo* widgetArticolo;
    QPushButton* modificaButton;
    ListaArticoli* lista;


public:
    FinestraDettagliArticolo(WidgetArticolo* articolo, QWidget* parent = nullptr);
    ~FinestraDettagliArticolo();

    void apriFinestraModifica();
};

#endif // FINESTRADETTAGLIARTICOLO_H
