set(NAME "Core")

include(${PROJECT_SOURCE_DIR}/cmake/StaticAnalyzers.cmake)

add_library(${NAME} STATIC
  Core/Log.cpp Core/Log.hpp Core/Instrumentor.hpp
  Core/Application.cpp Core/Application.hpp
  Core/Window.cpp Core/Window.hpp)

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${NAME} PRIVATE cxx_std_20)
target_link_libraries(${NAME}
    PRIVATE
        project_warnings
    PUBLIC
        spdlog
        SDL2::SDL2-static
        glad
        imgui

        sqlite3
        nlohmann_json::nlohmann_json
        pugixml

        ## NOTE:
        ## - libcurl ist ein C Project und wird mit autoconf und nmake gebaut
        ## - Es gibt einen C++ wrapper curlpp
        ##   - https://github.com/jpbarrette/curlpp
        ##   - NOTE: curlpp baut so
        ##     - https://github.com/jpbarrette/curlpp/blob/master/CMakeLists.txt
        ##
        ## Needs:
        ## - libpsl: https://github.com/rockdaboot/libpsl.git
        ##   - kein CMake :(
        ## - openssl: https://github.com/openssl/openssl.git
        ##   - kein CMake :(
        ##   - HTTPS support ist ein Muss!
        ##   - include curl-ca-bundle.crt?
        ## - libssh2: https://github.com/libssh2/libssh2.git
        ##   - cmake :)
        ## NOTE:
        ## - Hier kann man pre-compiled Binaries laden fuer jede Platform
        ##   - https://curl.se/windows/
        zlib
        libcurl

        ## TODO: CEF oder WebView(2) einbinden
#        libcef
#        cef
)
