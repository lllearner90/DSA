cmake_minimum_required(VERSION 3.10)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_PROJECT}/.)

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS ${MY_CURRENT_DIR} .)

FOREACH(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
ENDFOREACH()

set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})

