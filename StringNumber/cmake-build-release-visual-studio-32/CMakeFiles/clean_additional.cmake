# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\StringNumber_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\StringNumber_autogen.dir\\ParseCache.txt"
  "StringNumber_autogen"
  )
endif()
