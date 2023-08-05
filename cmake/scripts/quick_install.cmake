# cmake -P quick_install.cmake

set(project "arba-wgen")

function(get_script_args script_args)
    set(sc_args)
    set(start_found False)
    foreach(argi RANGE ${CMAKE_ARGC})
        set(arg ${CMAKE_ARGV${argi}})
        if(start_found)
            list(APPEND sc_args ${arg})
        endif()
        if("${arg}" STREQUAL "--")
            set(start_found True)
        endif()
    endforeach()
    set(${script_args} ${sc_args} PARENT_SCOPE)
endfunction()

get_script_args(args)
set(options "TESTS")
set(params DIR BUILD)
set(lists "")
cmake_parse_arguments(ARG "${options}" "${params}" "${lists}" ${args})

if(WIN32)
    set(temp_dir $ENV{TEMP})
elseif(UNIX)
    set(temp_dir /tmp)
else()
    message(FATAL_ERROR "No temporary directory found!")
endif()

set(src_dir ${CMAKE_CURRENT_LIST_DIR}/../..)
set(build_dir ${temp_dir}/local/build/${project}-build)
set(error_file ${build_dir}/quick_install_error)

if(EXISTS ${error_file})
    message(STATUS "Previous call to quick_install.cmake failed. Cleaning...")
    file(REMOVE_RECURSE ${build_dir})
endif()

message(STATUS "*  CONFIGURATION")
# arg TESTS:
if(ARG_TESTS)
    list(APPEND conf_args -DBUILD_${project}_TESTS=ON)
endif()
# arg BUILD:
if(ARG_BUILD)
    list(APPEND conf_args -DCMAKE_BUILD_TYPE=${ARG_BUILD})
endif()
# arg DIR:
if(ARG_DIR)
    list(APPEND conf_args -DCMAKE_INSTALL_PREFIX=${ARG_DIR})
elseif(NOT "$ENV{MINGW_PREFIX}" STREQUAL "")
    list(APPEND conf_args -DCMAKE_INSTALL_PREFIX=$ENV{MINGW_PREFIX})
endif()
# execute CMake:
execute_process(COMMAND ${CMAKE_COMMAND} ${conf_args} -S ${src_dir} -B ${build_dir}  RESULT_VARIABLE cmd_res)
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

if(ARG_TESTS)
  message(STATUS "*  TESTS")
  execute_process(COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure WORKING_DIRECTORY ${build_dir} RESULT_VARIABLE cmd_res)
  if(NOT cmd_res EQUAL 0)
      file(TOUCH ${error_file})
      return()
  endif()
endif()

message(STATUS "*  INSTALL")
execute_process(COMMAND ${CMAKE_COMMAND} --install ${build_dir})
if(NOT cmd_res EQUAL 0)
    file(TOUCH ${error_file})
endif()
