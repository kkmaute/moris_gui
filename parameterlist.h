#ifndef PARAMETERLIST_H
#define PARAMETERLIST_H


#include <QList>
#include <QStringList>
#include "gui_namespace.h"


class parameterList
{
public:
    parameterList();

    QStringList getParameterList(gui::Parameter_List_Type, int);
    QStringList getProjectNames();
    QList<QStringList> getParameterNames(gui::Parameter_List_Type);
    uint getNumberOfSubParameterListsInModule(gui::Parameter_List_Type aModule );
    QStringList getOuterSubParameterListName(gui::Parameter_List_Type aModule);
};

#endif // PARAMETERLIST_H
