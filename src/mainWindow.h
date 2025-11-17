#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "FinanceService.h"
#include "Lancamento.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void adicionarLancamento();
    void filtrarLancamentos();
    void salvarArquivo();

private:
    Ui::MainWindow *ui;
    FinanceService service;

    QList<Lancamento> lancamentos;
};

#endif
