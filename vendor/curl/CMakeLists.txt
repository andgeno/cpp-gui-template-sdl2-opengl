message(STATUS "Fetching curl ...")

## NOTE: Explicitly tell libcurl where to find zlib
#set(ZLIB_INCLUDE_DIR ${zlib_SOURCE_DIR} ${zlib_BINARY_DIR})
#set(ZLIB_LIBRARY zlib)
#remove_definitions(-DHAVE_UNISTD_H)
#target_include_directories(zlib PUBLIC ${zlib_SOURCE_DIR})

#add_definitions(-DZLIB_WINAPI)
#add_definitions(-DCURL_STATICLIB)

FetchContent_MakeAvailable(curl)
