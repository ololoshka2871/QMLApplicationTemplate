cmake_minimum_required(VERSION 3.0)

include(Functions)

function(xmlGenResSection files PREVDATA OUTVAR)
    set(res_str ${PREVDATA})
    foreach(f ${files})
        string(REGEX REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/(.*)" "\\1" r_f ${f})
        string(CONCAT res_str ${res_str} "\t\t<file>${r_f}</file>\n")
    endforeach()
    set(${OUTVAR} ${res_str} PARENT_SCOPE)
endfunction()

# Resource folders
# ******************************************************************************
set(qml_lib_dir qml/Lib)
set(Resources fonts icons qml/App ${qml_lib_dir})

set(RCC_CONTENT "<RCC>\n\t<qresource prefix=\"/\">\n")
set(All_res_files)
foreach(r ${Resources})
    set(_res)
    AddResources(${CMAKE_CURRENT_SOURCE_DIR}/${r} ${r} _res)
    list(APPEND All_res_files ${_res})
endforeach()
xmlGenResSection("${All_res_files}" ${RCC_CONTENT} RCC_CONTENT)
string(CONCAT RCC_CONTENT ${RCC_CONTENT} "\t</qresource>\n</RCC>")

add_custom_target(__fake_resources SOURCES ${All_res_files})

set(resource_file_name_in   ${CMAKE_CURRENT_SOURCE_DIR}/res.qrc.in)
set(resource_file_name      ${CMAKE_CURRENT_SOURCE_DIR}/res.qrc)
configure_file(${resource_file_name_in} ${resource_file_name} @ONLY)

# App Icon
# ******************************************************************************

set(Project_rc_in       ${CMAKE_CURRENT_SOURCE_DIR}/Project.rc.in)
set(APP_ICON_FILE       ${CMAKE_CURRENT_SOURCE_DIR}/icons/Project.ico)

IF(MINGW)
    set(Project_rc_obj  ${CMAKE_CURRENT_BINARY_DIR}/Project.obj)
    set(Project_rc      ${CMAKE_CURRENT_BINARY_DIR}/Project.rc)
    configure_file(${Project_rc_in} ${Project_rc})
    ADD_CUSTOM_COMMAND (
        OUTPUT ${App_icon_resource}
        COMMAND ${CMAKE_RC_COMPILER}
            -i ${Project_rc}
            -o ${Project_rc_obj}
    )
ENDIF()

set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${qml_lib_dir}" CACHE STRING "Qt Creator extra qml import paths")

set(RESOURCES_FILE ${resource_file_name} ${Project_rc_obj}  PARENT_SCOPE)
