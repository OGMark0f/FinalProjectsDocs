#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLinearGradient>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QInputDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <duckx.hpp>
#include <poppler-qt5.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   /*QString filename = "/home/mark0f/ProgFinal/test.pdf";
    Poppler::Document* file = Poppler::Document::load(filename);*/
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool ok2;
    bool ok;
    QString filename = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("filePath:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok2);
     if (ok2)
     {

    //QString filename = "/home/mark0f/ProgFinal/test.pdf";

    Poppler::Document* document = Poppler::Document::load(filename);
    int PageNumber = QInputDialog::getInt(this, tr("QInputDialog::getInt()"),
                                     tr("Percentage:"), 1, 0, document->numPages(), 1, &ok);

    if (ok)
    {
        QImage image = document->page(PageNumber)->renderToImage(45, 45,0, -155, document->page(3)->pageSize().width(), document->page(3)->pageSize().height());
        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->label->show();

    }
    delete document;
     }
}

/*void MainWindow::showPage(int page)
{
    QString filename = "/home/mark0f/ProgFinal/test.pdf";

    Poppler::Document* document = Poppler::Document::load(filename);
    QImage image = document->page(3)->renderToImage(72.0, 72.0, 0, 0, document->page(3)->pageSize().width(), document->page(3)->pageSize().height());
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}*/



void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{

}

int MainWindow::on_checkBox_stateChanged(int arg)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    bool ok2;
    QString filename = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("filePath:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok2);
    QFile file (filename);
    //QFile file ("/home/mark0f/ProgFinal/test.txt");
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    ui->textBrowser->setText(in.readAll());
}

void MainWindow::on_HTML_open_clicked()
{
    bool ok2;
    QString filename = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("filePath:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok2);
    QFile file (filename);
    //QFile file ("/home/mark0f/ProgFinal/internet.html");
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    ui->textBrowser->setText(in.readAll());
    //Poppler::Document
}

void MainWindow::on_pushButton_5_clicked()
{
    duckx::Document doc("/home/mark0f/DuckX/test/my_test.docx");
    doc.open();
    for (auto p : doc.paragraphs())
        for (auto r : p.runs())
                std::cout << r.get_text() << std::endl;
}
