#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , service("lancamentos.txt")
{
    ui->setupUi(this);

    // Carrega dados existentes
    service.carregar(lancamentos);

    // Preenche lista inicial
    for (auto &l : lancamentos) {
        ui->lista->addItem(
            QString("%1 - R$ %2").arg(l.descricao).arg(l.valor)
        );
    }

    connect(ui->btnAdicionar, &QPushButton::clicked,
            this, &MainWindow::adicionarLancamento);

    connect(ui->btnSalvar, &QPushButton::clicked,
            this, &MainWindow::salvarArquivo);

    connect(ui->btnFiltrar, &QPushButton::clicked,
            this, &MainWindow::filtrarLancamentos);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::adicionarLancamento() {
    Lancamento l;
    l.id = service.proximoId(lancamentos);
    l.descricao = ui->inputDescricao->text();
    l.valor = ui->inputValor->value();
    l.custo = ui->inputCusto->value();
    l.tipo = (TipoOperacao)ui->comboTipo->currentIndex();
    l.data = ui->inputData->date().toString("yyyy-MM-dd");

    lancamentos.append(l);

    ui->lista->addItem(l.descricao + " - R$ " + QString::number(l.valor));
}

void MainWindow::salvarArquivo() {
    if (service.salvar(lancamentos))
        QMessageBox::information(this, "OK", "Arquivo salvo!");
    else
        QMessageBox::warning(this, "Erro", "Falha ao salvar!");
}

void MainWindow::filtrarLancamentos() {
    ui->lista->clear();

    QString dtIni = ui->filtroDataInicio->date().toString("yyyy-MM-dd");
    QString dtFim = ui->filtroDataFim->date().toString("yyyy-MM-dd");
    int tipo = ui->filtroTipo->currentIndex();

    for (auto &l : lancamentos) {
        if (l.data >= dtIni && l.data <= dtFim) {
            if (tipo == -1 || l.tipo == tipo) {
                ui->lista->addItem(
                    l.descricao + " - R$ " + QString::number(l.valor)
                );
            }
        }
    }
}
