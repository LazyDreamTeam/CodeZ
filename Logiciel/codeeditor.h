#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include <QPainter>
#include <QTextBlock>
#include "log.h"
/**
  @author documentation de Qt (http://doc-snapshot.qt-project.org/4.8/widgets-codeeditor.html)
  Widget "éditeur de code", avec numérotation des ligne et surlignage de la ligne en cours
**/

class CodeEditor : public QPlainTextEdit
 {
     Q_OBJECT

 public:
     CodeEditor(QWidget *parent = 0);

     void lineNumberAreaPaintEvent(QPaintEvent *event);
     int lineNumberAreaWidth();
     void keyReleaseEvent(QKeyEvent* e);

 protected:
     void resizeEvent(QResizeEvent *event);
signals:
     void SnippetUpdated();
 private slots:
     void updateLineNumberAreaWidth(int newBlockCount);
     void highlightCurrentLine();
     void updateLineNumberArea(const QRect &, int);



 private:
     QWidget *lineNumberArea;
 };

#endif // CODEEDITOR_H
