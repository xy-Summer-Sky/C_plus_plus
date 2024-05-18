# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\FirstC__APP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FirstC__APP_autogen.dir\\ParseCache.txt"
  "FirstC__APP_autogen"
  )
endif()
