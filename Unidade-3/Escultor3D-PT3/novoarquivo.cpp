#include "novoarquivo.h"
#include "ui_novoarquivo.h"

Novoarquivo::Novoarquivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Novoarquivo)
{
    ui->setupUi(this);
}

Novoarquivo::~Novoarquivo()
{
    delete ui;
}

int Novoarquivo::pegadimx(){
    return ui->spinBox->value();
}

int Novoarquivo::pegadimy(){
    return ui->spinBox_2->value();
}
int Novoarquivo::pegadimz(){
    return ui->spinBox_3->value();
}
