#include "snippetlistwidget.h"

SnippetListWidget::SnippetListWidget(QWidget *parent) :
    QListWidget(parent)
{


}

void SnippetListWidget::keyReleaseEvent(QKeyEvent* e){
    switch(e->key()){
        case 16777223:
           emit suprPushed();
        break;
        case 16777222:
           emit insertPushed();
        break;
    }
}
