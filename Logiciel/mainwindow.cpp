#include "mainwindow.h"

MainWindow* MainWindow::_instance = 0;

MainWindow *MainWindow::getInstance()
{
    if(_instance == 0)
        _instance = new MainWindow();
    return _instance;
}



MainWindow::MainWindow() : QMainWindow() {

    dictionnary = Dictionnary::getInstance();
    //Paramètres de l'écran
    this->setWindowTitle(PROGRAM_TITLE);
    this->setMinimumSize(800,600);
    //definition de l'icone
    this->setWindowIcon(QIcon(":/skin/Images/icone.png"));

    // Centrage de la fenêtre
    QRect availableGeometry(QApplication::desktop()->availableGeometry());
    move((availableGeometry.width() - width()) / 2,
        (availableGeometry.height() - height()) / 2);

    //Contenu général de la fenêtre
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    status = statusBar();


    /************************/
    /**** Barre de Menu *****/
    /************************/

    QMenu *menuFile = menuBar()->addMenu("Fichier");
    QAction *actionQuit = new QAction("Quitter", this);
    menuFile->addAction(actionQuit);

    menuCategory = menuBar()->addMenu(QString::fromUtf8("Catégories"));
    actionCategoryAdd = new QAction(QString::fromUtf8("Ajouter une catégorie"), this);
    menuCategory->addAction(actionCategoryAdd);
    actionCategoryEdit = new QAction(QString::fromUtf8("Modifier catégorie"), this);
    menuCategory->addAction(actionCategoryEdit);
    actionCategoryDelete = new QAction(QString::fromUtf8("Supprimer catégorie"), this);
    menuCategory->addAction(actionCategoryDelete);


    menuLangage = menuBar()->addMenu(QString::fromUtf8("Langages"));
    actionLangageShow = new QAction(QString::fromUtf8("Gérer les langages"), this);
    menuLangage->addAction(actionLangageShow);


    menuSnippet = menuBar()->addMenu("Snippets");
    actionSnippetAdd = new QAction("Ajouter un snippet", this);
    menuSnippet->addAction(actionSnippetAdd);
    actionSnippetEdit = new QAction("Modifier snippet", this);
    menuSnippet->addAction(actionSnippetEdit);
    actionSnippetDelete = new QAction("Supprimer snippet", this);
    menuSnippet->addAction(actionSnippetDelete);
    menuSnippet->addSeparator();
    actionSnippetShare = new QAction("Partager", this);
    menuSnippet->addAction(actionSnippetShare);

    menuAbout = menuBar()->addMenu("?");
    actionAbout = new QAction(QString::fromUtf8("À propos"), this);
    menuAbout->addAction(actionAbout);


    /************************/
    /**** Menu de gauche ****/
    /************************/

    leftMenu = new QWidget;
    splitter->addWidget(leftMenu);
    layLeftMenu = new QVBoxLayout;
    leftMenu->setLayout(layLeftMenu);

    leftMenuHead = new QWidget;
    layLeftMenu->addWidget(leftMenuHead);
    layLeftMenuHead = new QHBoxLayout;
    layLeftMenuHead->setMargin(0);
    leftMenuHead->setLayout(layLeftMenuHead);
    imgLogo = new QPixmap(":/skin/Images/logo.png");
    logo = new QLabel;
    logo->setPixmap(*imgLogo);
    layLeftMenuHead->addWidget(logo, 0, Qt::AlignVCenter);
    layLeftMenuHead->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Maximum));
    btSnippetAdd = new QPushButton("+ Snippet");
    layLeftMenuHead->addWidget(btSnippetAdd, 0, Qt::AlignVCenter);

    lblCategoryList = new QLabel(QString::fromUtf8("Catégories"));
    layLeftMenu->addWidget(lblCategoryList);
    lstCategory = new SnippetListWidget;


    layLeftMenu->addWidget(lstCategory,2);
    lblSnippetList = new QLabel("Snippets");
    layLeftMenu->addWidget(lblSnippetList);
    lstSnippet = new SnippetListWidget;
    lstSnippet->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    layLeftMenu->addWidget(lstSnippet,3);


    /************************/
    /******* Editeur ********/
    /************************/

    content = new QWidget;
    splitter->addWidget(content);
    layContent = new QVBoxLayout;
    layContent->setMargin(5);
    content->setLayout(layContent);
    txtSnippet = new CodeEditor(content);
    QFont *editorFont = new QFont("Courrier",10);
    editorFont->setFixedPitch(true);
    txtSnippet->setFont(*editorFont);
    txtSnippet->setTabStopWidth(40);
    txtSnippet->setDisabled(true);
    layContent->addWidget(txtSnippet);


    /*************************/
    /******* Fenêtres ********/
    /*************************/

    aboutWindow = new AboutWindow(this);
    langageWindow = new LangageWindow(this);
    categoryWindow = new CategoryWindow(this);


    /*********************************/
    /*** Paramètrage et chargement ***/
    /*********************************/

    //IDs pour qss
    leftMenu->setObjectName("dark");
    logo->setObjectName("logo");
    content->setObjectName("content");
    btSnippetAdd->setObjectName("btSnippet");

    //Récupération et affichage des catégories
    refreshCategoryList();

    //Application des layouts principaux
    QList<int> sizes;
    sizes << 250 << 550;    //250 + 550 = 800 (largeur fenêtre)
    splitter->setSizes(sizes);
    splitter->setChildrenCollapsible(false);
    setCentralWidget(splitter);

    //Griser par défaut les actions innaccessibles au départ (quand rien n'est sélectionné)
    actionCategoryEdit->setEnabled(false);
    actionCategoryDelete->setEnabled(false);
    actionSnippetEdit->setEnabled(false);
    actionSnippetDelete->setEnabled(false);

    //TODO a virer lorsque le code sera prêt
    actionSnippetShare->setVisible(false);

    //Menus contextuels
    lstCategory->setContextMenuPolicy(Qt::CustomContextMenu);
    lstSnippet->setContextMenuPolicy(Qt::CustomContextMenu);


    /************************/
    /****** Evenements ******/
    /************************/

    // Menu
    /* Fichier > Quitter      */ QObject::connect(actionQuit,SIGNAL(triggered()), qApp, SLOT(quit()));
    /* Catégories > Ajouter   */ QObject::connect(actionCategoryAdd,SIGNAL(triggered()),this, SLOT(addCategory()));
                                QObject::connect(lstCategory,SIGNAL(insertPushed()),this, SLOT(addCategory()));
    /* Catégories > Modifier  */ QObject::connect(actionCategoryEdit,SIGNAL(triggered()),this, SLOT(editCategory()));
    /* Catégories > Supprimer */ QObject::connect(actionCategoryDelete,SIGNAL(triggered()),this, SLOT(deleteCategory()));
                                 QObject::connect(lstCategory,SIGNAL(suprPushed()),this, SLOT(deleteCategory()));

    /* Langages > gérer */ QObject::connect(actionLangageShow,SIGNAL(triggered()),this, SLOT(showLangage()));

    /* Snippets > Ajouter     */ QObject::connect(actionSnippetAdd,SIGNAL(triggered()),this, SLOT(addSnippet()));
                                 QObject::connect(btSnippetAdd,SIGNAL(clicked()),this, SLOT(addSnippet()));
                                 QObject::connect(lstSnippet,SIGNAL(insertPushed()),this, SLOT(addSnippet()));
    /* Snippets > Modifier    */ QObject::connect(actionSnippetEdit,SIGNAL(triggered()),this, SLOT(editSnippet()));
    /* Snippets > Supprimer   */ QObject::connect(actionSnippetDelete,SIGNAL(triggered()),this, SLOT(deleteSnippet()));
                                 QObject::connect(lstSnippet,SIGNAL(suprPushed()),this, SLOT(supressionPushed()));
    /* Snippets > Partage     */ QObject::connect(actionSnippetShare,SIGNAL(triggered()),this, SLOT(shareSnippet()));
    /* ? > À propos           */ QObject::connect(actionAbout,SIGNAL(triggered()),this, SLOT(about()));
    /* Snippets > Modifier le contenu */ QObject::connect(txtSnippet,SIGNAL(SnippetUpdated()),this, SLOT(updateSnippetContent()));



    // Listes panneau de gauche
    /* Catégories : menu      */ QObject::connect(lstCategory,SIGNAL(customContextMenuRequested(const QPoint &)),this, SLOT(showContextMenuCategory(const QPoint &)));
    /* Catégories : sélection */ QObject::connect(lstCategory,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this, SLOT(selectCategory(QListWidgetItem*)));
    /* Catégories : renommer  */ QObject::connect(lstCategory,SIGNAL(itemChanged(QListWidgetItem*)),this, SLOT(renameCategory(QListWidgetItem*)));
    /* Catégories : contexte  */ QObject::connect(lstCategory,SIGNAL(itemSelectionChanged()),this, SLOT(setContextCategory()));
    /* Snippets : menu        */ QObject::connect(lstSnippet,SIGNAL(customContextMenuRequested(const QPoint &)),this, SLOT(showContextMenuSnippet(const QPoint &)));
    /* Snippets : sélection   */ QObject::connect(lstSnippet,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this, SLOT(selectSnippet(QListWidgetItem*)));
    /* Snippets : renommer    */ QObject::connect(lstSnippet,SIGNAL(itemChanged(QListWidgetItem*)),this, SLOT(renameSnippet(QListWidgetItem*)));
    /* Catégories : ajoutée   */ QObject::connect(categoryWindow,SIGNAL(CategoryAdded()),this, SLOT(refreshCategoryList()));
}


void MainWindow::supressionPushed(){
    Log::put("Supression du snippet: "+selectedSnippet,1,1);
    Category category = dictionnary->getCategory(selectedCategory);
    Snippet snippet = Snippet(category.getRealName(),selectedSnippet);
    snippet.remove();
    this->refreshSnippetList(selectedCategory);
}


/**
  * Charge a nouveau et Rafraichis la liste des catégories
  *
**/
void MainWindow::refreshCategoryList(){
    QList<Category> categories = dictionnary->getCategories();
    lstCategory->blockSignals(true);
    lstCategory->clear();
    lstCategory->blockSignals(false);
    if(categories.size()!=0){
        lstCategory->setSortingEnabled(true);
        foreach(Category category,categories){
            QListWidgetItem* row = new QListWidgetItem(category.getName());
            row->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable );
            lstCategory->addItem(row);
        }
        lstCategory->item(0)->setSelected(true);
        this->selectCategory(lstCategory->item(0));
    }else{
        QListWidgetItem* row = new QListWidgetItem(LABEL_NO_LANGUAGE);
        row->setFlags(!Qt::ItemIsSelectable | !Qt::ItemIsEnabled | !Qt::ItemIsEditable );
        lstCategory->addItem(row);
    }
}

void MainWindow::refreshSnippetList(QString cat){
    lstSnippet->blockSignals(true);
    lstSnippet->clear();
    lstSnippet->blockSignals(false);
    status->showMessage(QString::fromUtf8("Catégorie : ") + cat);

    if ( cat != LABEL_NO_LANGUAGE ) {

        Category category =  dictionnary->getCategory(cat);

        highlighter = new Highlighter(txtSnippet->document(), category.getLangage());
        QStringList snippets = category.getSnippetsList();

        if(snippets.size()!=0){
            foreach(QString snippet, snippets){
                QListWidgetItem* row = new QListWidgetItem(snippet);
                //On rend les lignes éditables pour le renommage
                row->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable );
                lstSnippet->addItem(row);
            }
        }else{
            //@TODO se débrouiller pour que ca disparaisse lors de l'ajout d'un nouveau snippet
           /* QListWidgetItem* row = new QListWidgetItem(LABEL_NO_SNIPPET);
            row->setFlags(!Qt::ItemIsSelectable | !Qt::ItemIsEnabled | !Qt::ItemIsEditable );
            lstSnippet->addItem(row);*/
        }

        txtSnippet->setDisabled(true);
        txtSnippet->setPlainText(QString::fromUtf8("Aucun snippet sélectionné."));
    }
}

/**
 * Sélection d'un élément dans la liste des catégories (click ou flèches)
 * => on liste les snippets associés
 * => on charge le fichier .lang associé
 **/
void MainWindow::selectCategory(QListWidgetItem *item) {
    QString cat = item->text();
    selectedCategory = item->text();
    this->refreshSnippetList(cat);
}

/**
 * Ajout d'une nouvelle catégorie
 **/
void MainWindow::addCategory() {
    categoryWindow->show();
}

/**
 * Entrer en mode "renommage" sur la catégorie sélectionnée
 **/
void MainWindow::editCategory() {
    QList<QListWidgetItem*> items = lstCategory->selectedItems();
    if ( ! items.empty() ) {
        QListWidgetItem *item = items.at(0);
        lstCategory->scrollToItem(item);
        item->setSelected(true);
        lstCategory->editItem(item);
    }
}

/**
 * Appliquer le renommage de la catégorie
 **/
void MainWindow::renameCategory(QListWidgetItem *item) {
    if ( item->text().length() == 0 ) {
        lstCategory->scrollToItem(item);
        item->setText(selectedCategory);
    } else {
        Category category = dictionnary->getCategory(selectedCategory);
        category.rename(selectedCategory, item->text());
        selectedCategory = item->text();
    }
}

/**
 * Supprimer la catégorie sélectionnée
 **/
void MainWindow::deleteCategory() {
    Log::put("Supression de la catégorie: "+selectedCategory,1,1);
    Category category = dictionnary->getCategory(selectedCategory);
    category.remove();
    dictionnary->loadData();
    this->refreshCategoryList();
}

/**
 * Voir la liste des langages installés et les gérer
 **/
void MainWindow::showLangage() {
    langageWindow->show();
}

/**
 * Sélection d'un élément dans la liste des snippets (click ou flèches)
 */
void MainWindow::selectSnippet(QListWidgetItem *item) {
    selectedSnippet = item->text();
    Log::put("Selection du snippet "+item->text()+" de la catégorie "+lstCategory->currentRow(),1,1);
    actionSnippetEdit->setDisabled(false);
    actionSnippetDelete->setDisabled(false);
    txtSnippet->setDisabled(false);

    //@TODO C'était bien mais ça cassait les couilles pour le rafraichissment aprsè modif d'un snippet, trouver une solution plus pratique
    //Snippet snippet = dictionnary->getCategory(lstCategory->selectedItems()[0]->text()).getSnippet(item->text());

    Category category =  dictionnary->getCategory(lstCategory->selectedItems()[0]->text());
    Snippet snippet = Snippet(category.getRealName(),item->text());
    if ( item ) {
        //if ( item->text() == LABEL_NEW_SNIPPET ) {
        //    txtSnippet->setPlainText(LABEL_CODE_COMMENT);
        //} else {
            txtSnippet->setPlainText(snippet.getCode());
        //}
    } else {
        txtSnippet->setPlainText(LABEL_CHOOSE_SNIP);
    }
}

/**
 * Ajout d'un nouveau snippet
 **/
void MainWindow::addSnippet() {
    QListWidgetItem* row = new QListWidgetItem(LABEL_NEW_SNIPPET);
    row->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable );
    lstSnippet->addItem(row);
    lstSnippet->editItem(row);
    lstSnippet->setCurrentItem(row);
    // Ensuite on ajoute le snippet dans le fichier snip.
    //Category::addSnippet(lstCategory->selectedItems()[0]->text());
}

/**
 * changer le contenu d'un snippet
 **/
void MainWindow::updateSnippetContent(){
    Log::put("catégorie : "+selectedCategory+", snippet : "+selectedSnippet+", texte : "+txtSnippet->toPlainText(),1,1);
    Category category = dictionnary->getCategory(selectedCategory);
    Snippet snippet = Snippet(category.getRealName(),selectedSnippet);
    snippet.setCode(txtSnippet->toPlainText());
    snippet.save();
}

/**
 * renommer un snippet
 **/
void MainWindow::renameSnippet(QListWidgetItem *item) {
    if ( item->text().length() == 0 || item->text() == LABEL_NEW_SNIPPET ) {
        lstSnippet->scrollToItem(item);
        item->setText(selectedSnippet);
    } else {
        Category category = dictionnary->getCategory(selectedCategory);
        Snippet snippet = Snippet(category.getRealName(),selectedSnippet);
        snippet.rename(selectedSnippet, item->text());
        selectedSnippet = item->text();
    }
}

/**
 * Modifier le nom du snippet sélectionné
 **/
void MainWindow::editSnippet() {
    QList<QListWidgetItem*> items = lstSnippet->selectedItems();
    if ( ! items.empty() ) {
        QListWidgetItem *item = items.at(0);
        lstSnippet->scrollToItem(item);
        item->setSelected(true);
        lstSnippet->editItem(item);
    }
}

/**
 * Supprimer le snippet sélectionné
 **/
void MainWindow::deleteSnippet() {
    Log::put("Supression du snippet: "+selectedSnippet,1,1);
    Category category = dictionnary->getCategory(selectedCategory);
    Snippet snippet = Snippet(category.getRealName(),selectedSnippet);
    snippet.remove();
    this->refreshSnippetList(selectedCategory);
}

/**
 * Partager le snippet sélectionné
 **/
void MainWindow::shareSnippet() {

}

/**
 * Affichage de la boite de dialogue "à propos"
 **/
void MainWindow::about() {
    aboutWindow->show();
}

/**
 * Affichage du menu contextuel de la liste des catégories
 **/
void MainWindow::showContextMenuCategory(const QPoint &pos) {
    QPoint globalPos = lstCategory->mapToGlobal(pos);
    menuCategory->exec( globalPos );
}

/**
 * Affichage du menu contextuel de la liste des catégories
 **/
void MainWindow::showContextMenuSnippet(const QPoint &pos) {
    QPoint globalPos = lstSnippet->mapToGlobal(pos);
    menuSnippet->exec( globalPos );
}

/**
 * Si une catégorie est sélectionnée, active les actions qui lui sont liées
 * Sinon, les désactive
 **/
void MainWindow::setContextCategory() {
    if(lstCategory->selectedItems().count() > 0) {
        actionCategoryEdit->setEnabled(true);
        actionCategoryDelete->setEnabled(true);
    } else {
        actionCategoryEdit->setEnabled(false);
        actionCategoryDelete->setEnabled(false);
    }
}

/**
 * Si un snippet est sélectionné, active les actions qui lui sont liées
 * Sinon, les désactive
 **/
void MainWindow::setContextSnippet() {
    if(lstSnippet->selectedItems().count() > 0) {
        actionSnippetEdit->setEnabled(true);
        actionSnippetDelete->setEnabled(true);
    } else {
        actionSnippetEdit->setEnabled(false);
        actionSnippetDelete->setEnabled(false);
    }
}

