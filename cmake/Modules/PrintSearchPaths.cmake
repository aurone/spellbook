macro(print_search_paths)
    message("find_package module search variables")
    message("  CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
    message("  CMAKE_ROOT: ${CMAKE_ROOT}")
    message("  CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
    
    ######################################
    ## find_package prefix search order ##
    ######################################
    
    message("find_package search variables")
    
    # cmake cache variables specified through -DVAR=...
    message("  CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
    
    # cmake environment variables
    message("  ENV{Eigen3_DIR}: $ENV{Eigen3_DIR}")
    message("  ENV{CMAKE_PREFIX_PATH}: $ENV{CMAKE_PREFIX_PATH}")
    
    # HINTS
    
    # standard environment variables
    message("  ENV{PATH}: $ENV{PATH}")
    
    # project build trees
    
    # user package registry
    
    # cmake variables defined in Platform files
    message("  CMAKE_SYSTEM_PREFIX_PATH: ${CMAKE_SYSTEM_PREFIX_PATH}")
    
    # system package registry (Windows)
    
    ###################################
    ## find_path prefix search order ##
    ###################################
    
    message("find_path search variables")
    
    # cmake cache variables
    message("  CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
    message("  CMAKE_INCLUDE_PATH: ${CMAKE_INCLUDE_PATH}")
    
    # cmake environment variables
    message("  ENV{CMAKE_PREFIX_PATH}: $ENV{CMAKE_PREFIX_PATH}")
    message("  ENV{CMAKE_INCLUDE_PATH}: $ENV{CMAKE_INCLUDE_PATH}")
    
    # HINTS
    
    # standard environment variables
    message("  ENV{PATH}: $ENV{PATH}")
    message("  ENV{INCLUDE}: $ENV{INCLUDE}")
    
    # cmake variables defined in Platform files
    message("  CMAKE_SYSTEM_PREFIX_PATH: ${CMAKE_SYSTEM_PREFIX_PATH}")
    message("  CMAKE_SYSTEM_INCLUDE_PATH: ${CMAKE_SYSTEM_INCLUDE_PATH}")
    
    # PATHS
endmacro() 
