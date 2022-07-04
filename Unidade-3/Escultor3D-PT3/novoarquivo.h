#ifndef NOVOARQUIVO_H
#define NOVOARQUIVO_H

#include <QDialog>

namespace Ui {
class Novoarquivo;
}

class Novoarquivo : public QDialog
{
    Q_OBJECT

public:
    explicit Novoarquivo(QWidget *parent = nullptr);
    ~Novoarquivo();

    int pegadimx();
    int pegadimy();
    int pegadimz();

signals:

    void enviaDimX(int);
    void enviaDimY(int);

private:
    Ui::Novoarquivo *ui;
};

#endif // NOVOARQUIVO_H
