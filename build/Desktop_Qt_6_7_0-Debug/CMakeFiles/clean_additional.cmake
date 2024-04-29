# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Advanced-Tic-Tac-Toe_autogen"
  "CMakeFiles/Advanced-Tic-Tac-Toe_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Advanced-Tic-Tac-Toe_autogen.dir/ParseCache.txt"
  )
endif()
