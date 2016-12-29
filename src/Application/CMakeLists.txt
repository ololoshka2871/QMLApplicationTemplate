cmake_minimum_required(VERSION 3.0)

get_filename_component(libname ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Difenitions
# ******************************************************************************
#

AddSources(. "App" App_sources_list)

add_library(${libname} STATIC ${App_sources_list})

target_link_libraries(${libname} ${QT_MODULES})

# c++11
# ******************************************************************************
set_property(TARGET ${libname} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${libname} PROPERTY CXX_STANDARD_REQUIRED ON)


set(${libname}_INCLUDE_DIR      ${CMAKE_CURRENT_SOURCE_DIR}     PARENT_SCOPE)
