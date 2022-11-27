cmake_minimum_required(VERSION 3.0.0)
project(stack_task VERSION 0.1.0)

include(CTest)
enable_testing()

 set(SOURCE_FILES 
  src/stack/stack.c
  src/balanced_task/balanced_task.c
  src/main.c
  )

 add_executable(stack_task ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
