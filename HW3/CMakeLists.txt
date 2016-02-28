cmake_minimum_required(VERSION 2.8)
project(f_cpsl)

set(Boost_USE_STATIC_LIBS ON)

find_package(BISON)
find_package(FLEX)
find_package(Boost COMPONENTS program_options system filesystem REQUIRED)

bison_target(CpslParser parser.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(CpslScanner scanner.lpp ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(CpslScanner CpslParser)

#enable_testing()
include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/CodeGen
        ${CMAKE_CURRENT_SOURCE_DIR}/CodeGen/Expr
        ${Boost_INCLUDE_DIRS}
)

set(EXTRA_COMPILE_FLAGS "-g -std=c++11")
#set(LCOV_FLAGS "--coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS} ${LCOV_FLAGS}")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LCOV_FLAGS}")

set(main_srcs driver.hpp driver.cpp)
source_group("Main" FILES ${cpsl_srcs})

set(CODEGEN_SRCS
        CodeGen/CodeGenerator.hpp
        CodeGen/CodeGenerator.cpp
        CodeGen/Register.hpp
        CodeGen/Register.cpp
        CodeGen/LVal.hpp
        CodeGen/LVal.cpp
        CodeGen/Type.hpp
        ${BISON_CpslParser_OUTPUTS}
        ${FLEX_CpslScanner_OUTPUTS}
        )
source_group("CodeGen" FILES ${CODEGEN_SRCS})
set(cpsl_srcs ${CODEGEN_SRCS})

#set(AUX_SRCS
#       FlexLexer.h
#        location.hh
#        position.hh
#        stack.hh)

#source_group("Aux" FILES ${AUX_SRCS})
#list(APPEND cpsl_srcs ${AUX_SRCS})

set(EXPR_SRCS
        CodeGen/Expr/Expr.hpp
        CodeGen/Expr/Expr.cpp
        )

source_group("Expr" FILES ${EXPR_SRCS})
list(APPEND cpsl_srcs ${EXPR_SRCS})

set(CMAKE_INSTALL_RPATH ".")
add_library(cpsl_common STATIC ${cpsl_srcs})

add_executable(f_cpsl ${main_srcs})

target_link_libraries(cpsl_common ${FLEX_LIBRARIES} ${BISON_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(f_cpsl cpsl_common)
