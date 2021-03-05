#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QDialog>
#include<QFileDialog>
#include<QGraphicsView>
QT_BEGIN_NAMESPACE
namespace Ui { class ConfigDialog; }
QT_END_NAMESPACE

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    ConfigDialog(QWidget *parent = nullptr);
    ~ConfigDialog();
    QSize puzzleSize();
    QString imgFilePath();
public slots:
    void run();
private slots:
    void on_browseBtn_clicked();


private:
    Ui::ConfigDialog *ui;
};
#endif // CONFIGDIALOG_H
