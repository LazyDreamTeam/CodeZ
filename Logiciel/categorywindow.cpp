#include "categorywindow.h"

CategoryWindow::CategoryWindow(QWidget *parent) :
    QDialog(parent)
{
    //Paramètres de l'écran
    this->setModal(true);
    this->setWindowTitle(PROGRAM_TITLE+QString::fromUtf8(" : Ajout d'une catégorie"));
    this->setMinimumSize(400,180);
    //definition de l'icone
    this->setWindowIcon(QIcon(":/skin/Images/icone.png"));

    /*************/
    /** CONTENU **/
    /*************/

    //Initialisation
    layout = new QHBoxLayout;
    buttonZoneLayout = new QVBoxLayout;
    buttonZone = new QWidget;
    btnAddCategory = new QPushButton("Ajouter");
    labelCategoryName = new QLabel(QString::fromUtf8("Nom de la catégorie :"));
    labelLangageName = new QLabel(QString::fromUtf8("Langage de la catégorie :"));
    comboLangageList = new QComboBox();
    textCategoryName = new QLineEdit();

    //Définition des layouts
    this->setLayout(layout);
    buttonZone->setLayout(buttonZoneLayout);

    //Remplissage des elements graphiques dans les layout
    layout->addWidget(buttonZone);


    buttonZoneLayout->addWidget(labelCategoryName);
    buttonZoneLayout->addWidget(textCategoryName);
    buttonZoneLayout->addWidget(labelLangageName);
    buttonZoneLayout->addWidget(comboLangageList);
    buttonZoneLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Maximum, QSizePolicy::Expanding));
    buttonZoneLayout->addWidget(btnAddCategory);


    this->setObjectName("dark");

    /************************/
    /****** Evenements ******/
    /************************/

    /* Ajouter categorie */ QObject::connect(btnAddCategory,SIGNAL(clicked()), this, SLOT(addCategory()));
}

void CategoryWindow::show() {
    textCategoryName->clear();
    comboLangageList->clear();
    this->dictionnary = Dictionnary::getInstance();
    foreach(Langage langage, dictionnary->getLangages()){
        comboLangageList->addItem(langage.getFileName());
    }
    QWidget::show();
}

void CategoryWindow::addCategory(){
    QStringList categoriesName;
    QString newCategoryName = textCategoryName->text().trimmed().toLower();
    bool existingName = false;

    // Si l'utilisateur a donné un nom correct
    if(newCategoryName != "" && newCategoryName != LABEL_NAME_REQUIRED){
        // S'il n'existe pas déjà une catégorie avec ce nom
        QStringList categoriesName = Category::getAll();
        foreach(QString categoryName,categoriesName){
            if(categoryName.toLower().startsWith(newCategoryName + CATEGORY_LANGAGE_SEPARATOR)) {
                existingName = true;
            }
        }
        if(existingName) {
            QMessageBox::warning(this, "Catégorie existante", "Impossible de créer la catégorie \"" + newCategoryName + "\" car elle existe déjà.", QMessageBox::Ok);
            this->textCategoryName->setFocus();
        } else {
            Category::add(textCategoryName->text(),comboLangageList->currentText());
            dictionnary->loadData();
            emit CategoryAdded();

            textCategoryName->clear();
            comboLangageList->clear();

            this->close();
        }
    }else{
        textCategoryName->setText(LABEL_NAME_REQUIRED);
        this->textCategoryName->setFocus();
        this->textCategoryName->selectAll();
    }
}
