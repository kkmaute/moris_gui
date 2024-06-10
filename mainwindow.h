#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QComboBox>
#include <QScrollArea>
#include <QTreeWidget>

#include "parameterlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    parameterList ParameterList;
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *sidePanel = new QVBoxLayout();
    QTreeWidget *treeWidget = new QTreeWidget();

    QList<QTreeWidgetItem*> treeWidgetItems;
    QList<QTreeWidgetItem*> tTreeWidgetItems;
    QList<QList<QTreeWidgetItem*>> treeWidgetChildren;
    QStringList ProjectNames;
};
#endif // MAINWINDOW_H
