#ifndef QWDIALOGMANUAL_H
#define QWDIALOGMANUAL_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QWDialogManual; }
QT_END_NAMESPACE

class QWDialogManual : public QDialog
{
    Q_OBJECT

public:
    QWDialogManual(QWidget *parent = nullptr);
    ~QWDialogManual();

private:
    Ui::QWDialogManual *ui;
};
#endif // QWDIALOGMANUAL_H
