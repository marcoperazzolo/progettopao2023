#include "mainwindow.h"
#include "finestradettagliarticolo.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    //FINESTRA E WIDGET
    setWindowTitle("Progetto Biblioteca");
    setGeometry(100, 100, 1200, 400);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    //LAYOUT
    mainLayout = new QVBoxLayout(centralWidget);
    searchLayout = new QHBoxLayout(centralWidget);

    //BARRA DEL MENU
    menuBar = new QMenuBar();
    menuBiblioteca = new QMenu("Biblioteca...", menuBar);
    //Actions: le aggiungo al menu
    actionApri = new QAction("Apri", menuBiblioteca);
    actionSalva = new QAction("Salva", menuBiblioteca);     //actionAggiungiArticolo = new QAction("Aggiungi Articolo, menuBiblioteca);
    menuBiblioteca->addAction(actionApri);
    menuBiblioteca->addAction(actionSalva);                //menuBiblioteca->addAction(actionAggiungiArticolo);
    //aggiungo Menu alla barra
    menuBar->addMenu(menuBiblioteca);

    //LAYOUT RICERCA E BOTTONI
    barraRicerca = new QTextEdit(centralWidget);
    barraRicerca->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Imposta la politica di ridimensionamento
    barraRicerca->setMaximumHeight(barraRicerca->fontMetrics().height()); // Imposta l'altezza massima
    //barraRicerca->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Rimuovi la barra di scorrimento orizzontale
    barraRicerca->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Rimuovi la barra di scorrimento verticale
    //barraRicerca->setStyleSheet("QTextEdit { padding: 1px 0; }"); // Imposta il padding per evitare i movimenti leggeri durante la scrittura

    cercaButton = new QPushButton("Cerca", centralWidget);
    aggiungiArticoloButton = new QPushButton("Aggiungi Articolo", centralWidget);
    searchLayout->addWidget(barraRicerca);
    searchLayout->addWidget(cercaButton);
    searchLayout->addWidget(aggiungiArticoloButton);

    //LISTA ARTICOLI
    listaarticoli = new ListaArticoli(centralWidget);

    DVD* Oppenheimer = new DVD("Oppenheimer", "Storia bomba atomica", 9, 180, "Nolan", 5);
    CD* Utopia = new CD("Utopia", "Album dell'anno", 5, 120, "Travis Scott", "Rap", 12);
    Romanzo* PiccoloPrincipe = new Romanzo("Piccolo Principe", "Principe bambino", 0, "Santoine Exupery", "Bohnomelli", 150,  "Bambini");

    listaarticoli->aggiungiArticolo(Oppenheimer);
    listaarticoli->aggiungiArticolo(Utopia);
    listaarticoli->aggiungiArticolo(PiccoloPrincipe);


    //SETTING FINALE LAYOUT
    mainLayout->addWidget(menuBar);
    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(listaarticoli);
    //listaOggetti->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    connect(listaarticoli, &ListaArticoli::itemDoubleClicked, this, &MainWindow::mostraDettagliArticolo);


}

MainWindow::~MainWindow() = default;

void MainWindow::mostraDettagliArticolo(QListWidgetItem* item) {
    WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(listaarticoli->itemWidget(item));
    if (widgetArticolo) {
        finestradettarticolo = new FinestraDettagliArticolo(widgetArticolo->getArticolo(), this);
       //dialog->apriFinestraModifica(); // Passa l'istanza di ListaArticoli
       //connect(this, SIGNAL(articoloEliminatoCommand(WidgetArticolo* wart, Articolo* art)), this, SLOT(eliminaArticolo(WidgetArticolo* wart, Articolo* art)));
       //connect(dialog, SIGNAL(articoloEliminatoCommand), this, SLOT(eliminaArticolo));
       connect(finestradettarticolo, SIGNAL(aggiornaLista()), this, SLOT(refresh()));
       //connect(finestradettaglichiusa->refreshlistaarticoli)
       finestradettarticolo->exec();
    }
}

void MainWindow::eliminaArticolo(Articolo* art){
    listaarticoli->eliminaArticolo(art);
}

void MainWindow::refresh(){
    listaarticoli->refreshLista();
}
