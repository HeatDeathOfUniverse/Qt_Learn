#include "widget.h"
#include "ui_widget.h"
#include <QMetaProperty>S
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    boy = new QPerson("小帅");
    boy->setProperty("score", 95);
    boy->setProperty("age", 10);
    boy->setProperty("sex", "Male");//动态属性
    connect(boy, &QPerson::ageChanged, this, &Widget::on_ageChanged);

    girl = new QPerson("小樱");
    girl->setProperty("score", 99);
    girl->setProperty("age", 12);
    girl->setProperty("sex", "Fmale");
    connect(girl, &QPerson::ageChanged, this, &Widget::on_ageChanged);
    ui->spinBoxBoy->setProperty("isBoy", true); //动态属性
    ui->spinBoxGirl->setProperty("isBoy", false); //动态属性
    ui->spinBoxGirl->setValue(girl->property("age").toInt());
    ui->spinBoxBoy->setValue(boy->property("age").toInt());

    connect(ui->spinBoxBoy, SIGNAL(valueChanged(int)),
            this, SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoxGirl, SIGNAL(valueChanged(int)),
            this, SLOT(on_spin_valueChanged(int)));
}

Widget::~Widget()
{
    delete boy;
    delete girl;
    delete ui;
}

void Widget::on_ageChanged(int value)
{//响应QPerson的ageChanged信号
    Q_UNUSED(value);
    QPerson *aPerson = qobject_cast<QPerson *> (sender()); // 类型投射
    QString hisName = aPerson->property("name").toString(); // 姓名
    QString hisSex = aPerson->property("sex").toString(); // 动态属性
    int hisAge = aPerson->age();//通过接口获取年龄
    ui->plainTextEdit->appendPlainText(hisName+","+hisSex+
                                       QString::asprintf(",年龄=%d", hisAge));

}

void Widget::on_spin_valueChanged(int arg1)
{//响应界面上spinBox的valueChanged(int)信号
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());
    if (spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}





void Widget::on_pushButton_3_clicked()
{//“类的元对象信息”按钮响应
    const QMetaObject *meta=boy->metaObject();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("==元对象信息==\n");
    ui->plainTextEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));
    ui->plainTextEdit->appendPlainText("property");
    for (int i=meta->propertyOffset();i < meta->propertyCount();i++)
    {
//        QMetaProperty prop = meta->property(i);
        QMetaProperty prop = meta->property(i);
        const char* propName = prop.name();
        QString propValue=boy->property(propName).toString();
        ui->plainTextEdit->appendPlainText(
            QString("属性名称 =%1，属性值 =%2").arg(propName).arg(propValue));
    }
    ui->plainTextEdit->appendPlainText("");
    ui->plainTextEdit->appendPlainText("classInfo");
    for (int i=meta->classInfoOffset(); i<meta->classInfoCount(); i++)
    {
        QMetaClassInfo classInfo=meta->classInfo(i);
        ui->plainTextEdit->appendPlainText(QString("Name=%1; Value=%2")
                                               .arg(classInfo.name()).arg(classInfo.value()));
        // test git
    }
}

