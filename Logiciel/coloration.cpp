#include "coloration.h"

Coloration::Coloration()
{
}

QString Coloration::toString(){
    return "color : "+this->color+", underline : "+this->underline+", bold : "+this->bold+", strike : "+this->strike+", italic : "+this->italic+", nb values : "+QString::number(this->values.size());
}

void Coloration::setColor(QString color){
	this->color = color;
}
void Coloration::setUnderline(bool underline){
	this->underline = underline;
}
void Coloration::setBold(bool bold){
	this->bold = bold;
}
void Coloration::setStrike(bool strike){
	this->strike = strike;
}
void Coloration::setItalic(bool italic){
	this->italic = italic;
}
void Coloration::setValues(QStringList values){
	this->values = values;
}


QString Coloration::getColor(){
	return this->color;
}

bool Coloration::isUnderline(){
	return this->underline;
}
bool Coloration::isBold(){
	return this->bold;
}
bool Coloration::isStrike(){
	return this->strike;
}
bool Coloration::isItalic(){
	return this->italic;
}
QStringList Coloration::getValues(){
	return this->values;
}
