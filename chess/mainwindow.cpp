#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);


        for(int i = 0; i < 8; i ++){
            for (int j = 0; j < 8; j ++) {
                QString fieldName = "Field_" + QString::number(i) + QString::number(j);

                connect(MainWindow::findChild<QPushButton *>(fieldName),
                        SIGNAL(released()),
                        this,
                        SLOT(onFieldClick()));
            }

        }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onFieldClick() {
    QPushButton *field = (QPushButton *)sender();

    ui->Field_00->setIcon(QIcon(":/Resources/pawn.png"));

}

