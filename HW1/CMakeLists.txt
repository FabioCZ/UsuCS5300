cmake_minimum_required (VERSION 2.8)

SET(CXX g++-4.8)
SET(FLEX_EXECUTABLE flex)
project (CS5300HW1)
add_executable(CS5300HW1 gottlicher_lexical.cc)

#https://cmake.org/pipermail/cmake/2002-September/003028.html
# Create custom command for flex/lex (note the outputs)
 ADD_CUSTOM_COMMAND(
   SOURCE gottlicher_lexical.l
   COMMAND ${FLEX_EXECUTABLE} 
   ARGS -o gottlicher_lexical.cc
        gottlicher_lexical.l
   TARGET all
   OUTPUTS gottlicher_lexical.cc)
   
   SET(CS5300HW1 gottlicher_lexical.cc)
   SET_SOURCE_FILES_PROPERTIES(gottlicher_lexical.cc GENERATED)