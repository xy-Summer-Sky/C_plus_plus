# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NumberString_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NumberString_autogen.dir\\ParseCache.txt"
  "NumberString_autogen"
  )
endif()
