#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "highlighter.h"
#include "json.h"
#include "functions.h"
#include "snippet.h"
#include "codeeditor.h"
#include "aboutwindow.h"
#include "langagewindow.h"
#ifndef CATEGORYWINDOW_H
#include "categorywindow.h"
#endif
#include "log.h"
#include "dictionnary.h"
#include "snippetlistwidget.h"

/**
  @author Idleman
  Classe graphique représentant la fenêtre principale
**/


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    static MainWindow* getInstance();

public slots:

    void showContextMenuCategory(const QPoint &pos);
    void setContextCategory();
    void selectCategory(QListWidgetItem *item);
    void addCategory();
    void renameCategory(QListWidgetItem *item);
    void editCategory();
    void deleteCategory();

    void showLangage();

    void showContextMenuSnippet(const QPoint &pos);
    void setContextSnippet();
    void selectSnippet(QListWidgetItem *item);
    void addSnippet();
    void renameSnippet(QListWidgetItem *item);
    void editSnippet();
    void deleteSnippet();
    void shareSnippet();
    void refreshCategoryList();
    void refreshSnippetList(QString cat);
    void about();
    void updateSnippetContent();

    void supressionPushed();
private:
    static MainWindow* _instance;
    QMenu *menuCategory;
    QAction *actionCategoryAdd;
    QAction *actionCategoryEdit;
    QAction *actionCategoryDelete;

    QMenu *menuLangage;
    QAction *actionLangageShow;


    QMenu *menuSnippet;
    QAction *actionSnippetAdd;
    QAction *actionSnippetEdit;
    QAction *actionSnippetDelete;
    QAction *actionSnippetShare;
    QMenu *menuAbout;
    QAction *actionAbout;

    QWidget *leftMenu;
    QVBoxLayout *layLeftMenu;
    QWidget *leftMenuHead;
    QHBoxLayout *layLeftMenuHead;
    QPixmap *imgLogo;
    QLabel *logo;
    QPushButton *btSnippetAdd;
    QLabel *lblCategoryList;
    SnippetListWidget *lstCategory;
    QLabel *lblSnippetList;
    SnippetListWidget *lstSnippet;

    QVBoxLayout *layContent;
    QWidget *content;
    QLabel *lblSnippet;
    CodeEditor *txtSnippet;

    QStatusBar *status;

    QStringList languages;
    Highlighter* highlighter;
    QHash<QString, QVariantMap> highlighters;
    QHash<QString, QHash<QString, QString> > contenu;
    AboutWindow *aboutWindow;
    LangageWindow *langageWindow;
    CategoryWindow *categoryWindow;
    Dictionnary* dictionnary;
    Log log;

    QString selectedCategory;
    QString selectedSnippet;

};

#endif // MAINWINDOW_H
