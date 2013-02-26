#include "aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent)
{
    //Paramètres de l'écran
    this->setModal(true);
    this->setWindowTitle(PROGRAM_TITLE+QString::fromUtf8(" : À propos"));
    this->setMinimumSize(200,300);

    //definition de l'icone
    this->setWindowIcon(QIcon(":/skin/Images/icone.png"));

    /*************/
    /** CONTENU **/
    /*************/

    //Conteneurs
    layout = new QHBoxLayout;
    this->setLayout(layout);

    //Libellés
    lblHowAboutUs = new QLabel;
    lblHowAboutUs->setTextFormat(Qt::RichText);
    lblHowAboutUs->setText(LABEL_HOW_ABOUT_US);
    lblHowAboutUs->setOpenExternalLinks(true);
    layout->addWidget(lblHowAboutUs);
    this->setObjectName("dark");

}
