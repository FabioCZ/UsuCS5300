cmake_minimum_required (VERSION 2.8)

SET(CXX g++-4.8)
SET(FLEX_EXECUTABLE flex)
SET(BISON_EXECUTABLE bison)
project (CS5300HW2)
add_executable(CS5300HW2 gottlicher_lexical.cpp gottlicher_parser.cpp)

#https://cmake.org/pipermail/cmake/2002-September/003028.html
# Create custom command for flex/lex (note the outputs)
 ADD_CUSTOM_COMMAND(
   SOURCE gottlicher_lexical.l
   COMMAND ${FLEX_EXECUTABLE} 
   ARGS -o gottlicher_lexical.cpp
        gottlicher_lexical.l
   TARGET all
   OUTPUTS gottlicher_lexical.cpp)
   
  ADD_CUSTOM_COMMAND(
   SOURCE gottlicher_parser.y
   COMMAND ${BISON_EXECUTABLE} 
   ARGS -y gottlicher_parser.y
        -o gottlicher_parser.cpp
        --verbose
   TARGET all
   DEPENDS gottlicher_lexical.cpp
   OUTPUTS gottlicher_parser.cpp)
   
   SET(CS5300HW1 gottlicher_lexical.cpp gottlicher_parser.cpp)
   SET_SOURCE_FILES_PROPERTIES(gottlicher_lexical.cpp gottlicher_parser.cpp GENERATED)