# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ConvertNumber_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ConvertNumber_autogen.dir\\ParseCache.txt"
  "ConvertNumber_autogen"
  )
endif()
