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

    //lineEdit.resize(ProjectNames.size());
    //countProps.resize(ProjectNames.size());

    gui::Parameter_List_Type aModule = gui::Parameter_List_Type::OPT;
    QStringList tStringList;

    for (int iRoot = 0; iRoot < ProjectNames.size(); iRoot++) {

        tStringList = ParameterList.getOuterSubParameterListName(aModule);

        treeWidgetItems.append(new QTreeWidgetItem);
        treeWidgetItems[iRoot]->setText(0,ProjectNames[iRoot]);
        QList<QTreeWidgetItem*> tList;
        treeWidgetChildren.append(tList);

        QList<QFormLayout*> tFormLayout;
        formLayout.append(tFormLayout);

        QList<QWidget*> tScrollWidget;
        scrollWidget.append(tScrollWidget);

        QList<QScrollArea*> tScrollArea;
        scrollArea.append(tScrollArea);

        QList<QList<QLineEdit*>> tLineEditRoot;
        lineEdit.append(tLineEditRoot);

        QList<int> tCountPropsRoot;
        countProps.append(tCountPropsRoot);

        //lineEdit[iRoot].resize(tStringList.size());
        //countProps[iRoot].resize(tStringList.size());

        for (int iChildren = 0; iChildren < tStringList.size();iChildren++) {
            treeWidgetChildren[iRoot].append(new QTreeWidgetItem);
            treeWidgetChildren[iRoot][iChildren]->setText(0,tStringList[iChildren]);

            formLayout[iRoot].append(new QFormLayout);
            scrollWidget[iRoot].append(new QWidget);
            scrollArea[iRoot].append(new QScrollArea);

            QList<QLineEdit*> tLineEditChild;
            lineEdit[iRoot].append(tLineEditChild);

            int tCountPropsChild = 0;
            countProps[iRoot].append(tCountPropsChild);

            //formLayout[iRoot][iChildren]->addRow(tStringList[iChildren],new QLineEdit);

            scrollWidget[iRoot][iChildren]->setLayout(formLayout[iRoot][iChildren]);
            scrollArea[iRoot][iChildren]->setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
            scrollArea[iRoot][iChildren]->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);
            scrollArea[iRoot][iChildren]->setWidgetResizable (true);
            scrollArea[iRoot][iChildren]->setWidget(scrollWidget[iRoot][iChildren]);
            layout->addWidget(scrollArea[iRoot][iChildren]);

            if (iRoot == 0 && iChildren == 0) {
                setFormVisible(iRoot, iChildren, true);
                addElements(0,0);
            }
            else {
                setFormVisible(iRoot, iChildren, false);
            }

            //countProps[iRoot][iChildren] = 0;

        }

        treeWidgetItems[iRoot]->addChildren(treeWidgetChildren[iRoot]);

        aModule = static_cast<gui::Parameter_List_Type>(static_cast<int>(aModule) + 1);

    }

    treeWidget->addTopLevelItems(treeWidgetItems);
    treeWidget->setHeaderLabel("Project Names");
    sidePanel->addWidget(treeWidget);

    int tOldSelection = 0;
    OldSelection.append(tOldSelection);
    OldSelection.append(tOldSelection);

    connect(treeWidget,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),
            this, SLOT(parameterSelected(QTreeWidgetItem*,QTreeWidgetItem*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parameterSelected(QTreeWidgetItem * tNewItem, QTreeWidgetItem * tOldItem)
{

    // tNewItem is the new selection by the user
    // tOldItem is the old section by the user

    QList<int> tNewIndex = getTreeIndex(tNewItem);
    QList<int> tOldIndex = getTreeIndex(tOldItem);

    if (!tNewIndex.isEmpty() && countProps[tNewIndex[0]][tNewIndex[1]] == 0) {
        addElements(tNewIndex[0],tNewIndex[1]);
        countProps[tNewIndex[0]][tNewIndex[1]]++;
    }

    int tNewRoot, tNewChild, tOldRoot, tOldChild;

    if (!tOldIndex.isEmpty()) {
        tOldRoot = tOldIndex[0];
        tOldChild = tOldIndex[1];
    }
    else {
        tOldRoot = 0;
        tOldChild = 0;

        if (!(tOldIndex.isEmpty() && tNewIndex.isEmpty())) {
            setFormVisible(OldSelection[0],OldSelection[1],false);
        }

    }


    if (!tNewIndex.isEmpty()) {
        tNewRoot = tNewIndex[0];
        tNewChild = tNewIndex[1];
        OldSelection = tNewIndex;
    }
    else {
        return;
    }

    setFormVisible(tOldRoot,tOldChild,false);
    setFormVisible(tNewRoot,tNewChild,true);

}

QList<int> MainWindow::getTreeIndex(QTreeWidgetItem *tItem)
{
    QList<int> tIndex;

    for (int iRoot = 0; iRoot < treeWidgetChildren.size(); iRoot++) {
        for (int iChildren = 0; iChildren < treeWidgetChildren[iRoot].size();iChildren++) {
            if (tItem == treeWidgetChildren[iRoot][iChildren]) {
                tIndex.append(iRoot);
                tIndex.append(iChildren);

                return tIndex;
            }

            // if (tItem == treeWidgetItems[iRoot]) {
            //     tIndex.append(iRoot);
            // }
        }
    }

    return tIndex;
}

void MainWindow::setFormVisible(int aRoot, int aChildren, bool aCheck)
{
    //"aRoot" checks the project index (Root of tree)
    //"aChildren" checks the outer parameter selection (child)
    //"aCheck" checks whether it should turn visible or invisible

    for (int i=0;i<formLayout[aRoot][aChildren]->rowCount();i++){
        formLayout[aRoot][aChildren]->setRowVisible(i,aCheck);

    }
    scrollWidget[aRoot][aChildren]->setVisible(aCheck);
    scrollArea[aRoot][aChildren]->setVisible(aCheck);
}

void MainWindow::addElements(int aRoot, int aChild)
{
    gui::Parameter_List_Type aModule = static_cast<gui::Parameter_List_Type>(aRoot);
    QStringList tStringList = ParameterList.getParameterList(aModule, aChild);

    int tCounter = lineEdit[aRoot][aChild].size();

    for (int iElements = 0; iElements < tStringList.size(); iElements++) {
        lineEdit[aRoot][aChild].append(new QLineEdit());
        formLayout[aRoot][aChild]->
            addRow(tStringList[iElements],lineEdit[aRoot][aChild][iElements+tCounter]);
    }

}
