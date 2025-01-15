# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NumberConvert_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NumberConvert_autogen.dir\\ParseCache.txt"
  "NumberConvert_autogen"
  )
endif()
