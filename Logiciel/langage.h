#ifndef LANGAGE_H
#define LANGAGE_H

#include <QHash>
#ifndef CONSTANT_H
#include "constant.h"
#endif
#include "coloration.h"
#ifndef FUNCTIONS_H
#include "functions.h"
#endif
#include <QDirIterator>

/**
  @author idleman 27/06/2012
  Classe de représentation d'un langage
  L'attribut coloration est lié a un ensemble de regex
  définissant la coloration syntaxique des snippets
  contenu dans les catégories liées a ce langage.
**/

class Langage {
public:
    Langage();
    Langage(QString name);
    static QStringList getAll();
    void extractJsonData();

    QString getName();
    QString getFileName();
    QString getAuthor();
    QString getPubdate();
    QString getLinkSheet();
    QString getComment();
    QString getVersion();
    QList<Coloration> getColorations();
    static QList<Langage> loadAll();


    void setName(QString name);
    void setAuthor(QString author);
    void setPubdate(QString pubdate);
    void setLinkSheet(QString linkSheet);
    void setComment(QString comment);
    void setVersion(QString version);
    void setColorations(QList<Coloration> colorations);

private:
    QList<Coloration> colorations;
    QString name;
    QString fileName;
    QString author;
    QString pubdate;
    QString linkSheet;
    QString comment;
    QString path;
    QString version;
};

#endif // LANGAGE_H
