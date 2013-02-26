#ifndef SNIPPET_H
#define SNIPPET_H

#include "constant.h"
#include "functions.h"
#include <QStringList>

/**
  @author idleman 27/06/2012
  Classe de représentation d'un snippet
**/

class Snippet {
public:
    Snippet();
    static QList<Snippet> loadForCategory(QString category);
    Snippet(QString category,QString name);
    QString getName();
    QString getCategory();
    QString getCode();
    void setName(QString name);
    void setCategory(QString category);
    void setCode(QString code);
    void save();
    void remove();
    void rename(QString oldName, QString newName);
    QString extractCode();
private:
    QString name;
    QString category;
    QString code;
    QVariantMap jsonStructure;

};

#endif // SNIPPET_H
