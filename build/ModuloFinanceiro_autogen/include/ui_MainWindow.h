/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QGroupBox *groupCadastro;
    QGridLayout *formLayout;
    QLabel *labelDescricao;
    QLineEdit *inputDescricao;
    QLabel *labelValor;
    QDoubleSpinBox *inputValor;
    QLabel *labelCusto;
    QDoubleSpinBox *inputCusto;
    QLabel *labelTipo;
    QComboBox *comboTipo;
    QLabel *labelData;
    QDateEdit *inputData;
    QPushButton *btnAdicionar;
    QListWidget *lista;
    QGroupBox *groupFiltro;
    QGridLayout *filterLayout;
    QLabel *labelFiltroInicio;
    QDateEdit *filtroDataInicio;
    QLabel *labelFiltroFim;
    QDateEdit *filtroDataFim;
    QLabel *labelFiltroTipo;
    QComboBox *filtroTipo;
    QPushButton *btnFiltrar;
    QPushButton *btnSalvar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(650, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        groupCadastro = new QGroupBox(centralwidget);
        groupCadastro->setObjectName("groupCadastro");
        formLayout = new QGridLayout(groupCadastro);
        formLayout->setObjectName("formLayout");
        labelDescricao = new QLabel(groupCadastro);
        labelDescricao->setObjectName("labelDescricao");

        formLayout->addWidget(labelDescricao, 0, 0, 1, 1);

        inputDescricao = new QLineEdit(groupCadastro);
        inputDescricao->setObjectName("inputDescricao");

        formLayout->addWidget(inputDescricao, 0, 1, 1, 1);

        labelValor = new QLabel(groupCadastro);
        labelValor->setObjectName("labelValor");

        formLayout->addWidget(labelValor, 1, 0, 1, 1);

        inputValor = new QDoubleSpinBox(groupCadastro);
        inputValor->setObjectName("inputValor");
        inputValor->setMaximum(9999999.990000000223517);
        inputValor->setDecimals(2);

        formLayout->addWidget(inputValor, 1, 1, 1, 1);

        labelCusto = new QLabel(groupCadastro);
        labelCusto->setObjectName("labelCusto");

        formLayout->addWidget(labelCusto, 2, 0, 1, 1);

        inputCusto = new QDoubleSpinBox(groupCadastro);
        inputCusto->setObjectName("inputCusto");
        inputCusto->setMaximum(9999999.990000000223517);
        inputCusto->setDecimals(2);

        formLayout->addWidget(inputCusto, 2, 1, 1, 1);

        labelTipo = new QLabel(groupCadastro);
        labelTipo->setObjectName("labelTipo");

        formLayout->addWidget(labelTipo, 3, 0, 1, 1);

        comboTipo = new QComboBox(groupCadastro);
        comboTipo->addItem(QString());
        comboTipo->addItem(QString());
        comboTipo->setObjectName("comboTipo");

        formLayout->addWidget(comboTipo, 3, 1, 1, 1);

        labelData = new QLabel(groupCadastro);
        labelData->setObjectName("labelData");

        formLayout->addWidget(labelData, 4, 0, 1, 1);

        inputData = new QDateEdit(groupCadastro);
        inputData->setObjectName("inputData");
        inputData->setCalendarPopup(true);

        formLayout->addWidget(inputData, 4, 1, 1, 1);

        btnAdicionar = new QPushButton(groupCadastro);
        btnAdicionar->setObjectName("btnAdicionar");

        formLayout->addWidget(btnAdicionar, 5, 1, 1, 1);


        mainLayout->addWidget(groupCadastro);

        lista = new QListWidget(centralwidget);
        lista->setObjectName("lista");

        mainLayout->addWidget(lista);

        groupFiltro = new QGroupBox(centralwidget);
        groupFiltro->setObjectName("groupFiltro");
        filterLayout = new QGridLayout(groupFiltro);
        filterLayout->setObjectName("filterLayout");
        labelFiltroInicio = new QLabel(groupFiltro);
        labelFiltroInicio->setObjectName("labelFiltroInicio");

        filterLayout->addWidget(labelFiltroInicio, 0, 0, 1, 1);

        filtroDataInicio = new QDateEdit(groupFiltro);
        filtroDataInicio->setObjectName("filtroDataInicio");
        filtroDataInicio->setCalendarPopup(true);

        filterLayout->addWidget(filtroDataInicio, 0, 1, 1, 1);

        labelFiltroFim = new QLabel(groupFiltro);
        labelFiltroFim->setObjectName("labelFiltroFim");

        filterLayout->addWidget(labelFiltroFim, 1, 0, 1, 1);

        filtroDataFim = new QDateEdit(groupFiltro);
        filtroDataFim->setObjectName("filtroDataFim");
        filtroDataFim->setCalendarPopup(true);

        filterLayout->addWidget(filtroDataFim, 1, 1, 1, 1);

        labelFiltroTipo = new QLabel(groupFiltro);
        labelFiltroTipo->setObjectName("labelFiltroTipo");

        filterLayout->addWidget(labelFiltroTipo, 2, 0, 1, 1);

        filtroTipo = new QComboBox(groupFiltro);
        filtroTipo->addItem(QString());
        filtroTipo->addItem(QString());
        filtroTipo->addItem(QString());
        filtroTipo->setObjectName("filtroTipo");

        filterLayout->addWidget(filtroTipo, 2, 1, 1, 1);

        btnFiltrar = new QPushButton(groupFiltro);
        btnFiltrar->setObjectName("btnFiltrar");

        filterLayout->addWidget(btnFiltrar, 3, 1, 1, 1);


        mainLayout->addWidget(groupFiltro);

        btnSalvar = new QPushButton(centralwidget);
        btnSalvar->setObjectName("btnSalvar");

        mainLayout->addWidget(btnSalvar);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        groupCadastro->setTitle(QCoreApplication::translate("MainWindow", "Novo Lan\303\247amento", nullptr));
        labelDescricao->setText(QCoreApplication::translate("MainWindow", "Descri\303\247\303\243o:", nullptr));
        labelValor->setText(QCoreApplication::translate("MainWindow", "Valor:", nullptr));
        labelCusto->setText(QCoreApplication::translate("MainWindow", "Custo:", nullptr));
        labelTipo->setText(QCoreApplication::translate("MainWindow", "Tipo:", nullptr));
        comboTipo->setItemText(0, QCoreApplication::translate("MainWindow", "Entrada", nullptr));
        comboTipo->setItemText(1, QCoreApplication::translate("MainWindow", "Sa\303\255da", nullptr));

        labelData->setText(QCoreApplication::translate("MainWindow", "Data:", nullptr));
        btnAdicionar->setText(QCoreApplication::translate("MainWindow", "Adicionar", nullptr));
        groupFiltro->setTitle(QCoreApplication::translate("MainWindow", "Filtrar", nullptr));
        labelFiltroInicio->setText(QCoreApplication::translate("MainWindow", "Data in\303\255cio:", nullptr));
        labelFiltroFim->setText(QCoreApplication::translate("MainWindow", "Data fim:", nullptr));
        labelFiltroTipo->setText(QCoreApplication::translate("MainWindow", "Tipo:", nullptr));
        filtroTipo->setItemText(0, QCoreApplication::translate("MainWindow", "Todos", nullptr));
        filtroTipo->setItemText(1, QCoreApplication::translate("MainWindow", "Entrada", nullptr));
        filtroTipo->setItemText(2, QCoreApplication::translate("MainWindow", "Sa\303\255da", nullptr));

        btnFiltrar->setText(QCoreApplication::translate("MainWindow", "Filtrar", nullptr));
        btnSalvar->setText(QCoreApplication::translate("MainWindow", "Salvar Arquivo", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
