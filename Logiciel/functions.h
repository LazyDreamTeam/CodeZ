#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QFile>
#include <QTextStream>

#include "json.h"
#include "log.h"

class Functions {
public:
    Functions();
    static QString readFile(QString filePath);
    static QStringList readFileLine(QString filePath);
    static void touch(QString filePath);
    static void writeFile(QString filePath,QString content);
    static void deleteFile(QString filePath);
};

#endif // FUNCTION_H
