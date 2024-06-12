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
#include <QVector>

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

private slots:
    void parameterSelected(QTreeWidgetItem*, QTreeWidgetItem*);

    QVector<int> getTreeIndex(QTreeWidgetItem*);

    void setFormVisible(int, int, bool);

    void addElements(int, int);


private:
    Ui::MainWindow *ui;

    //Layout objects
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *sidePanel = new QVBoxLayout();
    QVector<QVector<QFormLayout*>> formLayout;

    //Scrolling objects
    QVector<QVector<QWidget*>> scrollWidget;
    QVector<QVector<QScrollArea*>> scrollArea;

    //Parameter objects
    parameterList ParameterList;
    QStringList ProjectNames;

    //Tree Widget items for navigation
    QTreeWidget *treeWidget = new QTreeWidget();
    QVector<QTreeWidgetItem*> treeWidgetItems;
    QVector<QVector<QTreeWidgetItem*>> treeWidgetChildren;
    QVector<int> OldSelection;

    //Element related objects
    QVector<QVector<QVector<QLineEdit*>>> lineEdit;
    QVector<QVector<int>> countProps;
};
#endif // MAINWINDOW_H
