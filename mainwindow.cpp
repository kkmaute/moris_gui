#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout->addLayout(sidePanel);
    treeWidget->setColumnCount(1);

    ProjectNames = ParameterList.getProjectNames();

    gui::Parameter_List_Type aModule = gui::Parameter_List_Type::OPT;
    QStringList tStringList;

    for (int iTreeWidget = 0; iTreeWidget < ProjectNames.size(); iTreeWidget++) {
        treeWidgetItems.append(new QTreeWidgetItem);
        treeWidgetItems[iTreeWidget]->setText
            (0,ProjectNames[iTreeWidget]);

        QList<QTreeWidgetItem*> tList;
        treeWidgetChildren.append(tList);

        tStringList = ParameterList.getOuterSubParameterListName(aModule);

        for (int iTreeWidgetChildren = 0; iTreeWidgetChildren < tStringList.size();iTreeWidgetChildren++) {
            treeWidgetChildren[iTreeWidget].append(new QTreeWidgetItem);
            treeWidgetChildren[iTreeWidget][iTreeWidgetChildren]->setText(0,tStringList[iTreeWidgetChildren]);
        }

        treeWidgetItems[iTreeWidget]->addChildren(treeWidgetChildren[iTreeWidget]);

        aModule = static_cast<gui::Parameter_List_Type>(static_cast<int>(aModule) + 1);

    }
    treeWidget->addTopLevelItems(treeWidgetItems);
    treeWidget->setHeaderLabel("Project Names");
    sidePanel->addWidget(treeWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
