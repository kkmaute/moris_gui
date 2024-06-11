# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\moris_gui_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\moris_gui_autogen.dir\\ParseCache.txt"
  "moris_gui_autogen"
  )
endif()
