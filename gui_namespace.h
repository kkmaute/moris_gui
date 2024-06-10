#ifndef GUI_NAMESPACE_H
#define GUI_NAMESPACE_H

#endif // GUI_NAMESPACE_H

namespace gui {

enum Parameter_List_Type {
    //! only have types here for which we have a standard parameter list (with the exception of "UNDEFINED")
    //! Make sure to include all enums defined here in the convert to string function below (with the exception of "UNDEFINED")
    OPT,
    HMR,
    STK,
    XTK,
    GEN,
    FEM,
    SOL,
    MSI,
    VIS,
    MIG,
    WRK,
    MORISGENERAL,
    END_ENUM
};
}
