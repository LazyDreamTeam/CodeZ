#ifndef SNIPPETLISTWIDGET_H
#define SNIPPETLISTWIDGET_H

#include <QListWidget>
#include <QKeyEvent>
#include "log.h"
class SnippetListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit SnippetListWidget(QWidget *parent = 0);
    void keyReleaseEvent(QKeyEvent* e);
signals:
   void suprPushed();
   void insertPushed();
public slots:
    
};

#endif // SNIPPETLISTWIDGET_H
