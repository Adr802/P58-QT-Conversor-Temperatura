#include "principal.h"
#include "ui_principal.h"


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //Conectar el dial de centigrados con el slot de ESTA clase
    connect(ui->cmdCen,SIGNAL(valueChanged(int)), this, SLOT(cent2fha(int)));
    //Conect cmdCenti(dial) Signal to funtion convert(cent to kelvin)
    connect(ui->cmdCen,SIGNAL(valueChanged(int)), this, SLOT(cent2kel(int)));

    //Conectar dial de fahrenheith con el slot de ESTA clase
    connect(ui->cmdFha, SIGNAL(valueChanged(int)), this, SLOT(fha2cent(int)));
    //Connect dial Fharenheit Signal -- to -- funtion convert(fah to kelvin)
    connect(ui->cmdFha, SIGNAL(valueChanged(int)), this, SLOT(fha2kel(int)));

    //Connect dial kelvin signal -- to -- function convert(kel to cent)
    connect(ui->cmdKel,SIGNAL(valueChanged(int)),this,SLOT(kel2cent(int)));
    //Connect dial kelvin signal -- to -- function convert(kel to farh)
    connect(ui->cmdKel,SIGNAL(valueChanged(int)),this,SLOT(kel2fha(int)));

}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fha(int cent)
{
    if(ui->cmdCen->hasFocus()){
        int f = (cent * 9.0/5) + 32;
        ui->cmdFha->setValue(f);
    }
}

void Principal::cent2kel(int i)
{
    //hasFocus - comprueba si el usuario esta sobre este widget
    if(ui->cmdCen->hasFocus()){
        int k = i + 273;
        ui->cmdKel->setValue(k); //Actualiza el valor al dial de kelvin
    }
}


void Principal::fha2cent(int i)
{
    if(ui->cmdFha->hasFocus()){
        int c = (i-32) * 5.0/9;
        ui->cmdCen->setValue(c);
    }
}

void Principal::fha2kel(int i)
{
    if(ui->cmdFha->hasFocus()){
        int k = (i+459) * (5.0/9);
        ui->cmdKel->setValue(k);
    }
}

void Principal::kel2cent(int i)
{
    if(ui->cmdKel->hasFocus()){
        int c = i-273;
        ui->cmdCen->setValue(c);
    }
}

void Principal::kel2fha(int i)
{
    if(ui->cmdKel->hasFocus()){
        int f = (i - 273) * 1.8 +32;
        ui->cmdFha->setValue(f);
    }
}

