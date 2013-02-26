#include "highlighter.h"


Highlighter::Highlighter(QTextDocument *parent, Langage langage): QSyntaxHighlighter(parent){
    HighlightingRule rule;
    QStringList regexes;

    QList<Coloration> colorations = langage.getColorations();


    foreach ( Coloration coloration, colorations ) {
        QStringList rgb = coloration.getColor().split(',');
        keywordFormat.setForeground(QColor(rgb.at(0).toInt(), rgb.at(1).toInt(), rgb.at(2).toInt(), 255));

        if(coloration.isBold()){
                   keywordFormat.setFontWeight(QFont::Bold);

               }else{
                   keywordFormat.setFontWeight(QFont::Normal);
               }
               if(coloration.isItalic()){
                   keywordFormat.setFontItalic(true);
               }else{
                   keywordFormat.setFontItalic(false);
               }
               if(coloration.isUnderline()){
                   keywordFormat.setFontUnderline(true);
               }else{
                   keywordFormat.setFontUnderline(false);
               }
               if(coloration.isStrike()){
                   keywordFormat.setFontStrikeOut(true);
               }else{
                   keywordFormat.setFontStrikeOut(false);
               }

        regexes = coloration.getValues();

        foreach ( QString k, regexes ) {
            rule.pattern = QRegExp(k);
            rule.format = keywordFormat;

            highlightingRules.append(rule);
        }
        regexes.clear();
    }
    multiLineCommentFormat.setForeground(Qt::darkYellow);
    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}

//! [7]
void Highlighter::highlightBlock(const QString &text) {
    foreach ( const HighlightingRule &rule, highlightingRules ) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while ( index >= 0 ) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
//! [7] //! [8]
    setCurrentBlockState(0);
//! [8]

//! [9]
    int startIndex = 0;
    if ( previousBlockState() != 1 )
        startIndex = commentStartExpression.indexIn(text);

//! [9] //! [10]
    while ( startIndex >= 0 ) {
//! [10] //! [11]
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if ( endIndex == -1 ) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
//! [11]
