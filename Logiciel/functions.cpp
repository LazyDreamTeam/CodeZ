#include "functions.h"


Functions::Functions() {}

/**
 * Récupérer le contenu d'un fichier au format DB_SNIPPET_FORMAT|DB_LANGAGE_FORMAT.
 * @author idleman
 */
QString Functions::readFile(QString filePath) {
    QFile file(filePath);
    QString texte;

    if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QTextStream flux(&file);
        flux.setCodec("UTF-8");
        texte = flux.readAll();
        file.close();
        Log::put(" Ouverture du fichier : "+filePath+" --> OK",5);
    } else {
        Log::put(" Ouverture du fichier : "+filePath+" --> ECHEC",5);
    }
    return texte;
}

void Functions::writeFile(QString filePath,QString content){
    QFile file(filePath);
    if (file.open(QFile::WriteOnly)) {
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << content;
    }
}

void Functions::deleteFile(QString filePath){
    QFile file(filePath);
    file.remove();
}


void Functions::touch(QString filePath){
    Log::put("Creation du fichier : "+filePath,5);
    Functions::writeFile( filePath,"");
}
