#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::getInstance();



    //encodage des chaines de caractère
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //Application de la feuille de style à l'application AVANT l'affichage de la première fenêtre
    QFile file(":/skin/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString(file.readAll());
    a.setStyleSheet(styleSheet);

    w->show();
    return a.exec();
}
