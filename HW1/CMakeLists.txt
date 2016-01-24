cmake_minimum_required (VERSION 2.8)

CXX=g++-4.8
project (CS5300HW1)
add_executable(CS5300HW1 gottlicher_lexical.cc)

# Create target for the parser
 ADD_CUSTOM_TARGET(FlexParser echo "Creating parser file")

# Create custom command for flex/lex (note the outputs)
 ADD_CUSTOM_COMMAND(
   SOURCE gottlicher_lexical.l
   COMMAND ${FLEX_EXECUTABLE} 
   ARGS -o gottlicher_lexical.cc
   TARGET FlexParser
   OUTPUTS gottlicher_lexical.cc)
   
   SET(CS5300HW1 gottlicher_lexical.cc)
   SET_SOURCE_FILES_PROPERTIES(gottlicher_lexical.cc GENERATED)