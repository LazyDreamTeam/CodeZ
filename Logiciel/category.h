#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>
#include <QDirIterator>
#include <QFileInfo>
#include "constant.h"
#include "langage.h"
#include "snippet.h"


#include "functions.h"

/**
  @author idleman 27/06/2012
  Classe de représentation d'une catégorie
**/

class Category {
public:
    Category();
    Category(QString name);
    void setName(QString category);
    QString getName();
    static QStringList getAll();
    static QList<Category> loadAll();
    QStringList getSnippetsList();
    QString getLangage();
    void setLangage(QString langage);
    void loadLangage();
    void loadSnippet();
    Langage getLangageObject();
    QList<Snippet> getSnippets();
    Snippet getSnippet(QString name);
    QString getRealName();
    static void add(QString name, QString langage);
    void rename(QString oldName, QString newName);
    void remove();
private :
    QString name;
    QString langage;
    Langage langageObject;
    QList<Snippet> snippets;
};

#endif // CATEGORY_H
