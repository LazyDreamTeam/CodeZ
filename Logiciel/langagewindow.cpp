#include "langagewindow.h"

LangageWindow::LangageWindow(QWidget *parent) :
    QDialog(parent)
{

    this->dictionnary = Dictionnary::getInstance();

    //Paramètres de l'écran
    this->setModal(true);
    this->setWindowTitle(PROGRAM_TITLE+" : Gestion des langages");
    this->setMinimumSize(400,400);
    //definition de l'icone
    this->setWindowIcon(QIcon(":/skin/Images/icone.png"));

    /*************/
    /** CONTENU **/
    /*************/

    //Initialisation
    layout = new QHBoxLayout;
    buttonZoneLayout = new QVBoxLayout;
    buttonZone = new QWidget;
    btnAddLangage = new QPushButton("Ajouter");
    btnUpdateLangage = new QPushButton("Modifier");
    btnDeleteLangage = new QPushButton("Supprimer");
    lblLangagesList = new QLabel;

    //Définition des layouts
    this->setLayout(layout);
    buttonZone->setLayout(buttonZoneLayout);

    //Remplissage des elements graphiques dans les layout
    layout->addWidget(buttonZone);
    buttonZoneLayout->addWidget(lblLangagesList);
    buttonZoneLayout->addWidget(btnAddLangage);
    buttonZoneLayout->addWidget(btnUpdateLangage);
    buttonZoneLayout->addWidget(btnDeleteLangage);

    //Liste graphique des langages



    listLangagesList = new QListWidget;
    QList<Langage> langages = dictionnary->getLangages();
    lblLangagesList->setTextFormat(Qt::RichText);
    lblLangagesList->setText("Liste des "+QString::number(langages.size())+" langages disponibles");
    foreach(Langage langage,langages){
        listLangagesList->addItem(langage.getName());
    }

    layout->addWidget(listLangagesList);
    this->setObjectName("dark");

    //TODO a virer lorsque le code sera prêt
    btnAddLangage->setVisible(false);
    btnUpdateLangage->setVisible(false);
    btnDeleteLangage->setVisible(false);

    /************************/
    /****** Evenements ******/
    /************************/

    /* Ajouter langage */ QObject::connect(btnAddLangage,SIGNAL(clicked()), this, SLOT(addLanguage()));
    /* Modifier langage */ QObject::connect(btnUpdateLangage,SIGNAL(clicked()), this, SLOT(updateLanguage()));
    /* Supprimer langage */ QObject::connect(btnDeleteLangage,SIGNAL(clicked()), this, SLOT(deleteLanguage()));
    /* Catégories : sélection */ QObject::connect(listLangagesList,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this, SLOT(selectLangage(QListWidgetItem*)));


}

/**
 * Ajout d'un nouveau langage
 **/
void LangageWindow::addLanguage() {

}

/**
 * Modification d'un langage
 **/
void LangageWindow::updateLanguage() {

}

/**
 * Suppression d'un langage
 **/
void LangageWindow::deleteLanguage() {

}

/**
 * selection d'un langage
 **/
void LangageWindow::selectLangage(QListWidgetItem *item){
    Log::put("Selection du langage "+item->text());
    Langage langage = this->dictionnary->getLangage(item->text());
    QDateTime pubDate;
    pubDate.setTime_t(langage.getPubdate().toInt());
    QString langageInfos = "<ul><li><strong>Langage sélectionné:</strong> "+langage.getName()+"</li>";
    langageInfos += "<li><strong>Par: </strong>"+langage.getAuthor()+"</li>";
    langageInfos += "<li><strong>Le: </strong>"+pubDate.toString("dd/MM/yyyy à hh:mm")+"</li>";
    langageInfos += "<li><strong>Version :</strong>"+langage.getVersion()+"</li>";
    langageInfos += "<li>"+langage.getComment()+"</li></ul>";
    lblLangagesList->setText(langageInfos);
}
