# project
# ******************************************************************************
cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake;")

set(TEMPLATE_APPLICATION_NAME "App" CACHE STRING "Application name")
set(PROJECT_NAME ${TEMPLATE_APPLICATION_NAME})

project(${PROJECT_NAME})

# meta
# ******************************************************************************
set(TEMPLATE_VERSION_MAJOR 1 CACHE INT "Version Major")
set(TEMPLATE_VERSION_MINOR 0 CACHE INT "Version Minor")
set(TEMPLATE_VERSION_PATCH 0 CACHE INT "Version Patch")
set(TEMPLATE_ORGANIZATION "organization" CACHE STRING "Organization")
set(TEMPLATE_DOMAIN "domain" CACHE STRING "Domain")

# Qt
# ******************************************************************************
set(TEMPLATE_QT_VERSION "5.7" CACHE STRING "Qt Version")

# sources
# ******************************************************************************
add_subdirectory(src)
