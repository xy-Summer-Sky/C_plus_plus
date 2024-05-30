# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\SIMS_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SIMS_autogen.dir\\ParseCache.txt"
  "SIMS_autogen"
  )
endif()
