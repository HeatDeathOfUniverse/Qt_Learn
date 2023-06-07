#include "qwdialogmanual.h"
#include "ui_qwdialogmanual.h"

QWDialogManual::QWDialogManual(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QWDialogManual)
{
    ui->setupUi(this);
}

QWDialogManual::~QWDialogManual()
{
    delete ui;
}

