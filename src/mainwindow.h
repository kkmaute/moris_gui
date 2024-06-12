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
#include <QList>

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

    QList<int> getTreeIndex(QTreeWidgetItem*);

    void setFormVisible(int, int, bool);

    void addElements(int, int);


private:
    Ui::MainWindow *ui;

    //Layout objects
    QHBoxLayout *layout = new QHBoxLayout(this);
    QVBoxLayout *sidePanel = new QVBoxLayout();
    QList<QList<QFormLayout*>> formLayout;

    //Scrolling objects
    QList<QList<QWidget*>> scrollWidget;
    QList<QList<QScrollArea*>> scrollArea;

    //Parameter objects
    parameterList ParameterList;
    QStringList ProjectNames;

    //Tree Widget items for navigation
    QTreeWidget *treeWidget = new QTreeWidget();
    QList<QTreeWidgetItem*> treeWidgetItems;
    QList<QList<QTreeWidgetItem*>> treeWidgetChildren;
    QList<int> OldSelection;

    //Element related objects
    QList<QList<QList<QLineEdit*>>> lineEdit;
    QList<QList<int>> countProps;
};
#endif // MAINWINDOW_H
