# cmake -P cmake_quick_install.cmake

set(project "wgen")

if(WIN32)
    set(temp_dir $ENV{TEMP})
elseif(UNIX)
    set(temp_dir /tmp)
else()
    message(FATAL_ERROR "No temporary directory found!")
endif()

file(TO_NATIVE_PATH "/" path_sep)
set(src_dir ${CMAKE_CURRENT_LIST_DIR})
set(build_dir ${temp_dir}${path_sep}${project}-build)
set(error_file ${build_dir}${path_sep}quick_install_error)

if(EXISTS ${error_file})
    message(STATUS "Previous call to quick_install.cmake failed. Cleaning...")
    file(REMOVE_RECURSE ${build_dir})
endif()

message(STATUS "*  CONFIGURATION")
execute_process(COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -S ${src_dir} -B ${build_dir}  RESULT_VARIABLE cmd_res)
if(NOT cmd_res EQUAL 0)
    file(TOUCH ${error_file})
    return()
endif()

message(STATUS "*  BUILD")
execute_process(COMMAND ${CMAKE_COMMAND} --build ${build_dir}  RESULT_VARIABLE cmd_res)
if(NOT cmd_res EQUAL 0)
    file(TOUCH ${error_file})
    return()
endif()

message(STATUS "*  INSTALL")
execute_process(COMMAND ${CMAKE_COMMAND} --install ${build_dir})
if(NOT cmd_res EQUAL 0)
    file(TOUCH ${error_file})
endif()
