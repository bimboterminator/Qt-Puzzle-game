#include "configdialog.h"
#include "ui_configdialog.h"
#include"puzzlefield.h"
#include<QDebug>
ConfigDialog::ConfigDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfigDialog)
{
    ui->setupUi(this);
}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

QSize ConfigDialog::puzzleSize()
{
    return ui->frame->value();
}

QString ConfigDialog::imgFilePath()
{
    return ui->browseLineEdit->text();
}


void ConfigDialog::on_browseBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Открыть изображение",QDir::currentPath(),"Image files (*.pnf *.jpg *jpeg *.bmp *.ico)");
    if (!filename.isNull()){
        ui->browseLineEdit->setText(filename);
        ui->frame->setPixmap(filename);
    }

}

void ConfigDialog::run()
{
    QPixmap newImage;
    if(!newImage.load(imgFilePath())){
        QMessageBox::warning(this, tr("Open Image"),
                                         tr("The image file could not be loaded."),
                                         QMessageBox::Cancel);
    }
    else{
    PuzzleField * field = new PuzzleField(puzzleSize(),newImage);
    QGraphicsView* view = new QGraphicsView();
    view->setScene(field);
    view->show();
    QDialog::accept();
    }
}
