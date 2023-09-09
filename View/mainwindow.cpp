#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    //FINESTRA E WIDGET
    setWindowTitle("Progetto Biblioteca");
    setGeometry(100, 100, 1200, 820);
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
    actionSalva = new QAction("Salva", menuBiblioteca);
    actionAggiungiArticolo = new QAction("Aggiungi Articolo", menuBiblioteca);
    menuBiblioteca->addAction(actionApri);
    menuBiblioteca->addAction(actionSalva);
    menuBiblioteca->addAction(actionAggiungiArticolo);
    //aggiungo Menu alla barra
    menuBar->addMenu(menuBiblioteca);
    connect(actionApri, &QAction::triggered, this, &MainWindow::apriFile);
    connect(actionSalva, &QAction::triggered, this, &MainWindow::salvaFile);
    connect(actionAggiungiArticolo, &QAction::triggered, this, &MainWindow::apriFinestraAggiunta);

    //LAYOUT RICERCA E BOTTONI
    barraRicerca = new QTextEdit(centralWidget);
    barraRicerca->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    barraRicerca->setMaximumHeight(barraRicerca->fontMetrics().height());
    barraRicerca->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    cercaButton = new QPushButton("Cerca", centralWidget);
    aggiungiArticoloButton = new QPushButton("Aggiungi Articolo", centralWidget);
    searchLayout->addWidget(barraRicerca);
    searchLayout->addWidget(cercaButton);
    searchLayout->addWidget(aggiungiArticoloButton);

    //LISTA ARTICOLI
    listaarticoli = new ListaArticoli(centralWidget);

    Manuale* Startup = new Manuale("Apri un file!", "Premi Biblioteca e poi 'Apri' in alto a sinistra per caricare un file JSON!", 1, "Marco Perazzolo e Niccolo Carlesso", "UniPD", 100,  "PAO2 Informatica");
    Romanzo* Startup2 = new Romanzo("Oppure cliccami!", "Per aprire la finestra dei dettagli!", 1, "Marco Perazzolo e Niccolo Carlesso", "UniPD", 100,  "PAO2 Informatica");

    listaarticoli->aggiungiArticolo(Startup);
    listaarticoli->aggiungiArticolo(Startup2);



    //SETTING FINALE LAYOUT
    mainLayout->addWidget(menuBar);
    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(listaarticoli);

    connect(cercaButton, &QPushButton::clicked, this, &MainWindow::cercaButtonPremuto);
    connect(listaarticoli, &ListaArticoli::itemDoubleClicked, this, &MainWindow::mostraDettagliArticolo);
    connect(aggiungiArticoloButton, &QPushButton::clicked, this, &MainWindow::apriFinestraAggiunta);
}

MainWindow::~MainWindow() = default;

void MainWindow::mostraDettagliArticolo(QListWidgetItem* item) {
    WidgetArticolo* widgetArticolo = dynamic_cast<WidgetArticolo*>(listaarticoli->itemWidget(item));
    if (widgetArticolo) {
       finestradettarticolo = new FinestraDettagliArticolo(widgetArticolo->getArticolo(), this);
       connect(finestradettarticolo, SIGNAL(aggiornaLista()), this, SLOT(refresh()));
       connect(finestradettarticolo, SIGNAL(articoloEliminatoSignal(Articolo*)), this, SLOT(eliminaArticolo(Articolo*)));
       finestradettarticolo->exec();
    }
}

void MainWindow::eliminaArticolo(Articolo* art){
    listaarticoli->eliminaArticolo(art);
}

void MainWindow::refresh(){
    listaarticoli->refreshLista();
    update();
}

void MainWindow::apriFinestraAggiunta(){
    FinestraAggiungiArticolo finestraaggiunta(this);
    connect(&finestraaggiunta, SIGNAL(segnaleNuovoArticolo(Articolo*)), this, SLOT(aggiungiArticolo(Articolo*)));
    finestraaggiunta.exec();
}

void MainWindow::aggiungiArticolo(Articolo* art){
    listaarticoli->aggiungiArticolo(art);
}

void MainWindow::cercaButtonPremuto(){
    titolocercato = (QString(barraRicerca->toPlainText())).toStdString();

    if (titolocercato ==""){
        listaarticoli->show();
        if(listarisultati){
            listarisultati->hide();
        }
        update();
    }
    else{
        if(listaarticoli->getLista()->cercadaTitolo(titolocercato)){
            if(listarisultati){
                listarisultati->aggiungiArticolo(listaarticoli->getLista()->cercadaTitolo(titolocercato));
                listaarticoli->hide();
                listarisultati->show();
                update();
            }else{
                listarisultati = new ListaArticoli(this);
                listarisultati->aggiungiArticolo(listaarticoli->getLista()->cercadaTitolo(titolocercato));
                listaarticoli->hide();
                mainLayout->addWidget(listarisultati);
                connect(listarisultati, &ListaArticoli::itemDoubleClicked, this, &MainWindow::mostraDettagliArticolo);
                listarisultati->show();
                update();
            }
        }else{
            if(listarisultati){
                listaarticoli->hide();
                listarisultati->show();
                update();
            }else{
                listarisultati = new ListaArticoli(this);
                listaarticoli->hide();
                mainLayout->addWidget(listarisultati);
                listarisultati->show();
                update();
            }
        }
    }
}

void MainWindow::apriFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Apri File JSON", QDir::homePath(), "File JSON (*.json)");

    if (!filePath.isEmpty()) {
        listaarticoli->clear();
        refresh();

        listaarticoli->getLista()->importFromJson(filePath);
        listaarticoli->aggiornaListadaLista(listaarticoli->getLista());
        listaarticoli->refreshLista();
        refresh();
    }
}

void MainWindow::salvaFile() {
    QString filePath = QFileDialog::getSaveFileName(this, "Salva File JSON", QDir::homePath(), "File JSON (*.json)");

    if (!filePath.isEmpty()) {
        listaarticoli->getLista()->exportToJson(filePath);
    }
}
