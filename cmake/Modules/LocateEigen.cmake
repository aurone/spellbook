macro(locate_eigen)
    # Attempt to find Eigen3 through a variety of methods:
    
    # check for officially supported cmake find module
    find_package(Eigen3 QUIET)
    if (${EIGEN3_FOUND})
        set(Eigen_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
    else()
        # check for unofficially suported cmake find module
        find_package(Eigen QUIET)
        if (${EIGEN_FOUND})
#            set(EIGEN_INCLUDES ${Eigen_INCLUDE_DIRS})
        else()
            # check for officially supported pkg-config file
            find_package(PkgConfig REQUIRED)
            pkg_check_module(Eigen REQUIRED Eigen3)
        endif()
    endif()
endmacro()
