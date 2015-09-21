macro(locate_eigen)
    # Attempt to find Eigen3 through a variety of methods:
    
    # officially supported cmake find module
    find_package(Eigen3 QUIET)
    if (${EIGEN3_FOUND})
        set(EIGEN_INCLUDES ${EIGEN3_INCLUDE_DIR})
    else()
        # unofficially suported cmake find module
        find_package(Eigen QUIET)
        if (${EIGEN_FOUND})
            set(EIGEN_INCLUDES ${Eigen_INCLUDE_DIRS})
        else()
            # pkg-config file
            find_package(PkgConfig REQUIRED)
            pkg_check_module(Eigen REQUIRED Eigen3)
        endif()
    endif()
endmacro()
