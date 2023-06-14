#ifndef WIDGET_H
#define WIDGET_H

#include <QPerson.h>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPerson *boy;
    QPerson *girl;


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
private slots:
    //自定义槽函数
    void on_ageChanged(int value);
    void on_spin_valueChanged(int arg1);
    // 界面生成的槽函数

    void on_pushButton_3_clicked();
};
#endif // WIDGET_H
