# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GestionDechets_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GestionDechets_autogen.dir\\ParseCache.txt"
  "GestionDechets_autogen"
  )
endif()
