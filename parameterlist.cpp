#include "parameterlist.h"

parameterList::parameterList() {}


QStringList parameterList::getParameterList(gui::Parameter_List_Type aModule, int aChild)
{
    //Tried to make an example Parameter list in the format that MORIS has

    QList<QStringList> tParameterList;


    switch ( aModule )
    {
    case gui::Parameter_List_Type::OPT:
        tParameterList.resize(1);
        tParameterList[0] = {"is_optimization_problem", //T/F
                             "workflow", //Free
                             "finite_difference_epsilons"}; //Free
        break;

    case gui::Parameter_List_Type::HMR:
        tParameterList.resize(1);
        tParameterList[0] = {"number_of_elements_per_dimension", //Free
                             "domain_dimensions", //Free
                             "domain_offset", //Free
                             "domain_sidesets"}; //Free

        break;

    case gui::Parameter_List_Type::STK:
        tParameterList.resize(1);
        tParameterList[0] = {"input_file", //Free
                             "periodic_workspace", //T/F
                             "periodic_side_set_pair"}; //Free
        break;

    case gui::Parameter_List_Type::XTK:
        tParameterList.resize(1);
        tParameterList[0] = {"decompose", //T/F
                             "decomposition_type", //Dropdown (Free for now)
                             "enrich", //T/F
                             "use_SPG_based_enrichment", //T/F
                             "basis_rank", //Free
                             "enrich_mesh_indices"}; //Free
        break;

    case gui::Parameter_List_Type::GEN:
        tParameterList.resize(3);

        tParameterList[0] = {"time_offset", //Num
                             "advs_size", //Num
                             "lower_bounds_fill", //NUm
                             "upper_bounds_fill", //Num
                             "print_phase_table"}; //T/F

        tParameterList[1] = {"geometry_type", //Dropdown, Level set, Surface Mesh, Voxel need to create seperate function later
                             "isocontour_threshold", //Num
                             "isocontour_tolerance", //Num
                             "intersection_tolerance"}; //Num

        tParameterList[2] = {"design_type", //Dropdown
                             "pdv_type", //Free
                             "pdv_mesh_type"}; //Free

        break;

    case gui::Parameter_List_Type::FEM:
        tParameterList.resize(8);

        /*
         * Set of Dropdowns for tParameterList[0] (property_name in FEM)
         * //Dropdown
         * PropDensity, PropYoungs, PropPoisson,
         * PropCTE, PropRefTemp, PropConductivity,
         * PropCapacity, PropDirichlet, PropSelectX,
         * PropSelectY, PropSelectZ, PropInnerPressureLoad,
         * PropOuterPressureLoad, PropOuterTemperature
         */

        tParameterList[0] = {"property_name",
                             "function_parameters", //Num
                             "value_function"}; //T/F



        tParameterList[1] = {"constitutive_name", //Free for now
                             "constitutive_type", //Free
                             "model_type", //Free
                             "dof_dependencies"}; //Free

        tParameterList[2] = {"stabilization_name", //Free
                             "stabilization_type", //Dropdown (Look up fem::Stabilization_Type)
                             "function_parameters", //Free
                             "leader_properties"}; //Free

        tParameterList[3] = {"IWG_name", //Free
                             "IWG_type", //Dropdown (Look up fem::IWG_Type)
                             "dof_residual", //
                             "leader_dof_dependencies", //
                             "stabilization_parameters", //
                             "mesh_set_names"}; //Free

        tParameterList[4] = {"IQI_name", //Free
                             "IQI_type", //Dropdown (Look up fem::IQI_Type)
                             "dof_quantity", //
                             "leader_dof_dependencies", //
                             "vectorial_field_index", //
                             "mesh_set_names"}; //Free

        tParameterList[5] = {"print_physics_model", //Free
                             "is_analytical_forward", //T/F
                             "finite_difference_scheme_forward", //
                             "finite_difference_perturbation_size_forward", //
                             "is_analytical_sensitivity", //
                             "finite_difference_scheme", //
                             "finite_difference_perturbation_size", //
                             "finite_difference_perturbation_strategy"}; //Free

        tParameterList[6] = {"field_name", //Free
                             "field_entity_type", //T/F
                             "field_type", //
                             "field_create_from_file", //
                             "field_file_time_index", //
                             "field_file_field_index", //
                             "field_file_update", //
                             "IQI_Name", //
                             "field_output_to_file"}; //Free

        tParameterList[7] = {"material_name", //Free
                             "material_type", //Dropdown
                             "dof_dependencies", //
                             "properties", //
                             "phase_name"}; //Free



        //WHERE ARE 6 AND 7 FOR FEM?????


        break;

    case gui::Parameter_List_Type::SOL:
        tParameterList.resize(8);

        /*
         * For tParameterList[0] need to show different menus
         * based on type of solver
         * Options are: Aztec, Amesos, Belos,Petsc, Eigen_Solver
         * Search for create_linear_algorithm_parameter_list
         * Below is only for Amesos
         */

        tParameterList[0] = {"Solver_Implementation", //Amesos for now
                             "Solver_Type", //T/F
                             "PrintStatus", //T/F
                             "PrintTiming", //T/F
                             "ComputeVectorNorms", //T/F
                             "ComputeTrueResidual", //T/F
                             "Reindex", //T/F
                             "Refactorize", //T/F
                             "AddZeroToDiag", //T/F
                             "RcondThreshold", //Num
                             "OutputLevel", //Num
                             "DebugLevel", //Num
                             "ComputeConditionNumber"}; //T/F



        tParameterList[1] = {"DLA_Linear_solver_algorithms", //Free for now
                             "DLA_max_lin_solver_restarts", //Free
                             "DLA_hard_break", //Free
                             "DLA_rebuild_lin_solver_on_fail", //Free
                             "DLA_LHS_output_filename", //Free
                             "RHS_Matrix_Type", //Free
                             "DLA_operator_condition_number_with_moris",
                             "DLA_prec_operator_condition_number_with_moris"}; //Free

        tParameterList[2] = {"NLA_Solver_Implementation", //Dropdown NEWTON_SOLVER, ARC_LENGTH_SOLVER
                             "NLA_Linear_solver", //
                             "NLA_max_iter", //Free
                             "NLA_ref_iter",
                             "NLA_combined_res_jac_assembly"}; //Free

        tParameterList[3] = {"NLA_Solver_Implementation", //Free
                             "NLA_DofTypes", //
                             "NLA_Secondary_DofTypes", //
                             "NLA_Sub_Nonlinear_Solver", //
                             "NLA_Nonlinear_solver_algorithms", //
                             "NLA_max_non_lin_solver_restarts"}; //Free

        tParameterList[4] = {"TSA_Solver_Implementation", //Free
                             "TSA_Nonlinear_solver", //
                             "TSA_nonlinear_solver_for_adjoint_solve", //
                             "TSA_Num_Time_Steps", //
                             "TSA_Time_Frame"}; //Free

        tParameterList[5] = {"TSA_TPL_Type", //Free
                             "TSA_Solver_algorithms", //
                             "TSA_DofTypes", //
                             "TSA_Max_Time_Solver_Restarts", //
                             "TSA_Output_Indices", //
                             "TSA_Output_Criteria", //
                             "TSA_Pause_Function", //
                             "TSA_Initialize_Sol_Vec", //
                             "TSA_time_level_per_type"}; //Free

        tParameterList[6] = {"SOL_TPL_Type", //Free
                             "SOL_save_operator_to_matlab", //T/F
                             "SOL_load_sol_vec_from_file", //
                             "SOL_load_sol_vec_data_group", //
                             "SOL_load_sol_vec_num_vec"}; //Free

        tParameterList[7] = {"Preconditioner_Implementation", //Free
                             "ifpack_prec_type", //Dropdown
                             "ml_prec_type", //
                             "overlap-level", //
                             "relaxation: type"}; //Free



        break;

    case gui::Parameter_List_Type::MSI:
        tParameterList.resize(1);
        tParameterList[0] = {"TEMP", //                           "P", //T/F
                             "RHO", //
                             "E", //
                             "EVP", //
                             "EVT"};
        break;

    case gui::Parameter_List_Type::VIS:
        tParameterList.resize(1);
        tParameterList[0] = {"Output_Index", //
                             "Mesh_Type", //
                             "File_Name", //
                             "Temp_Name", //
                             "Save_Frequency", //
                             "Time_Offset", //
                             "Set_Names", //
                             "Field_Names", //
                             "Field_Type", //
                             "IQI_Names"}; //

        break;

    case gui::Parameter_List_Type::MIG:
        tParameterList.resize(1);
        tParameterList[0] = {"periodic_side_set_pair"};

        break;

    case gui::Parameter_List_Type::WRK:
        tParameterList.resize(1);
        tParameterList[0] = {"adv_field", //                           "P", //T/F
                             "dof_type", //
                             "reinitialization_frequency", //
                             "output_mesh_file", //
                             "time_offset"};
        break;

    case gui::Parameter_List_Type::MORISGENERAL:
        break;

    default:
        //MORIS_ERROR( false, "Library_Enums::get_number_of_sub_parameter_lists_in_module() - Parameter list type enum unknown." );
        break;
    }

    return tParameterList[aChild];


}

QStringList parameterList::getProjectNames()
{
    QStringList tProjectNames;
    tProjectNames = {"OPT", "HMR", "STK",
                     "XTK", "GEN", "FEM",
                     "SQL", "MSI", "VIS",
                     "MIG", "WRK", "MORISGENERAL"};

    return tProjectNames;

}

uint parameterList::getNumberOfSubParameterListsInModule(gui::Parameter_List_Type aModule)
{
    switch ( aModule )
    {
    case gui::Parameter_List_Type::OPT:
        return 1;

    case gui::Parameter_List_Type::HMR:
        return 1;

    case gui::Parameter_List_Type::STK:
        return 1;

    case gui::Parameter_List_Type::XTK:
        return 1;

    case gui::Parameter_List_Type::GEN:
        return 3;

    case gui::Parameter_List_Type::FEM:
        return 9;

    case gui::Parameter_List_Type::SOL:
        return 8;

    case gui::Parameter_List_Type::MSI:
        return 1;

    case gui::Parameter_List_Type::VIS:
        return 1;

    case gui::Parameter_List_Type::MIG:
        return 1;

    case gui::Parameter_List_Type::WRK:
        return 1;

    case gui::Parameter_List_Type::MORISGENERAL:
        return 3;

    default:
        //MORIS_ERROR( false, "Library_Enums::get_number_of_sub_parameter_lists_in_module() - Parameter list type enum unknown." );
        return 0;
    }
}

QStringList parameterList::getOuterSubParameterListName(gui::Parameter_List_Type aModule)
{
    // initialize the names with the standard
    QStringList tNames = { "General" };

    // get the names of the sub-parameter lists for each of the modules
    switch ( aModule )
    {
    case gui::Parameter_List_Type::OPT:
        tNames = { "OptimizationProblems", "Interface", "Algorithms" };
        break;

    case gui::Parameter_List_Type::HMR:
        break;    // standard name

    case gui::Parameter_List_Type::STK:
        break;    // standard name

    case gui::Parameter_List_Type::XTK:
        break;    // standard name

    case gui::Parameter_List_Type::GEN:
        tNames = { "General", "Geometries", "Properties" };
        break;

    case gui::Parameter_List_Type::FEM:
        tNames = {
            "Properties",                 // 0
            "ConstitutiveModels",         // 1
            "StabilizationParameters",    // 2
            "WeakForms",                  // 3
            "QuantitiesOfInterest",       // 4
            "ComputationParameters",      // 5
            "Fields",                     // 6
            //"Materials",                  // 7
            "MaterialModels"              // 8
        };
        break;

    case gui::Parameter_List_Type::SOL:
        tNames = {
            "LinearAlgorithms",        // 0
            "LinearSolvers",           // 1
            "NonLinearAlgorithms",     // 2
            "NonLinearSolvers",        // 3
            "TimeSolverAlgorithms",    // 4
            "TimeSolvers",             // 5
            "SolverWarehouse",         // 6
            "Preconditioners"          // 7
        };
        break;

    case gui::Parameter_List_Type::MSI:
        break;    // standard name

    case gui::Parameter_List_Type::VIS:
        tNames = { "OutputMeshes" };
        break;

    case gui::Parameter_List_Type::MIG:
        break;    // standard name

    case gui::Parameter_List_Type::WRK:
        break;    // standard name

    case gui::Parameter_List_Type::MORISGENERAL:
        tNames = { "Remeshing", "Refinement", "Mapping" };
        break;

    default:
        //MORIS_ERROR( false, "Library_Enums::convert_enum_to_string() - Parameter list type enum unknown." );
        break;
    }

    // check validity of the input
    uint tNumSubParamLists = tNames.size();

    // retrieve the name for the specific sub-parameter list requested
    return tNames;
}

