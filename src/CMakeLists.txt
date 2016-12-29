cmake_minimum_required(VERSION 3.0)

# Qt
# ******************************************************************************
set(TEMPLATE_QT_MODULES Core Gui Widgets Quick Qml Concurrent Network DBus PrintSupport)
find_package(Qt5 ${TEMPLATE_QT_VERSION} CONFIG REQUIRED ${TEMPLATE_QT_MODULES})
# Automatically run moc, uic and/or rcc, if required
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)

set(QT_MODULES)
foreach(module ${TEMPLATE_QT_MODULES})
    list(APPEND QT_MODULES Qt5::${module})
endforeach()

# configure files
# ******************************************************************************
set(metafile_in     ${CMAKE_CURRENT_SOURCE_DIR}/meta.hpp.in)
set(metafile        ${CMAKE_CURRENT_BINARY_DIR}/meta.hpp)
configure_file(${metafile_in} ${metafile} @ONLY)

# definitions
# ******************************************************************************
add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# subfolders
# *****************************************************************************
add_subdirectory(res)
add_subdirectory(Application)

include_directories(${Application_INCLUDE_DIR})

# target
# ******************************************************************************
add_executable(${PROJECT_NAME}
    ${RESOURCES_FILE}
    main.cpp
    )

# c++11
# ******************************************************************************
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

# link
# ******************************************************************************
target_link_libraries(${PROJECT_NAME}
    ${QT_MODULES}
    Application
    )
