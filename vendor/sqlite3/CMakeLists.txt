message(STATUS "Fetching SQLite3 ...")

FetchContent_GetProperties(sqlite3)
if (NOT sqlite3_POPULATED)
  FetchContent_Populate(sqlite3)
endif ()

## TODO: Control STATIC / DYNAMIC via BUILD_SHARED_LIBS instead of hardcoding it here
add_library(sqlite3 STATIC
        ${sqlite3_SOURCE_DIR}/sqlite3.c
        ${sqlite3_SOURCE_DIR}/sqlite3.h
        ${sqlite3_SOURCE_DIR}/sqlite3ext.h)
target_include_directories(sqlite3 PUBLIC ${sqlite3_SOURCE_DIR})

add_executable(sqlite3_shell
        EXCLUDE_FROM_ALL
        ${sqlite3_SOURCE_DIR}/sqlite3.c
        ${sqlite3_SOURCE_DIR}/shell.c
        ${sqlite3_SOURCE_DIR}/sqlite3.h
        ${sqlite3_SOURCE_DIR}/sqlite3ext.h)
#set_target_properties(sqlite3_shell PROPERTIES OUTPUT_NAME sqlite3)

## TODO: use more modern add_compile_definitions() instead?
add_definitions(-DSQLITE_ENABLE_RTREE)
add_definitions(-DSQLITE_ENABLE_FTS4)
add_definitions(-DSQLITE_ENABLE_FTS5)
add_definitions(-DSQLITE_ENABLE_JSON1)
add_definitions(-DSQLITE_ENABLE_RBU)
add_definitions(-DSQLITE_ENABLE_STAT4)

FetchContent_MakeAvailable(sqlite3)
