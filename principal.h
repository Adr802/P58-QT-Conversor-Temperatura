#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private:
    Ui::Principal *ui;

public slots:

    void cent2fha(int i);
    void cent2kel(int i);

    void fha2cent(int i);
    void fha2kel(int i);

    void kel2cent(int i);
    void kel2fha(int i);


};
#endif // PRINCIPAL_H
