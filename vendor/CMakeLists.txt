include(FetchContent)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY "https://github.com/onqtam/doctest.git"
  GIT_TAG b7c21ec5ceeadb4951b00396fc1e4642dd347e5f ## Tag "v2.4.9"
)
add_subdirectory(doctest)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
  GIT_TAG c4ee726532178e556d923372f29163bd206d7732 ## Tag "9.0.0"
)
add_subdirectory(fmt)

FetchContent_Declare(
  glad
  GIT_REPOSITORY "https://github.com/krieselreihe/glad.git"
  GIT_TAG 55e149fff3ebd786db1ddce2eeed111146119791 ## Tag "v1.0.0"
)
add_subdirectory(glad)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
  GIT_TAG 21fc57f2cfb61fc61527d7ed540a01c11e258939 # Branch "docking"; 2022-07-08
)
add_subdirectory(imgui)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG 53dea9830964eee8b5c2a7ee0a65d6e268dc78a1 ## Tag "release-2.0.22"
)
add_subdirectory(sdl)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG 76fb40d95455f249bd70824ecfcae7a8f0930fa3 ## Tag "v1.10.0"
)
add_subdirectory(spdlog)

FetchContent_Declare(
  sqlite3
  URL "https://sqlite.org/2022/sqlite-amalgamation-3400000.zip"
  URL_HASH SHA256=7c23eb51409315738c930a222cf7cd41518ae5823c41e60a81b93a07070ef22a
  DOWNLOAD_NO_EXTRACT false
  DOWNLOAD_EXTRACT_TIMESTAMP true
  TLS_VERIFY true
)
add_subdirectory(sqlite3)

FetchContent_Declare(
  zlib
  GIT_REPOSITORY "https://github.com/madler/zlib.git"
  GIT_TAG 04f42ceca40f73e2978b50e93806c2a18c1281fc ## Tag "v1.2.13"
)
add_subdirectory(zlib)

FetchContent_Declare(
  curl
  GIT_REPOSITORY "https://github.com/curl/curl.git"
  GIT_TAG cd95ee9f771361acf241629d2fe5507e308082a2 ## Tag "curl-7_86_0"
)
add_subdirectory(curl)

FetchContent_Declare(
  json
  GIT_REPOSITORY "https://github.com/nlohmann/json.git"
  GIT_TAG bc889afb4c5bf1c0d8ee29ef35eaaf4c8bef8a5d ## Tag "v3.11.2"
)
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(JSON_Install OFF CACHE INTERNAL "")
add_subdirectory(json)

FetchContent_Declare(
  pugixml
  GIT_REPOSITORY "https://github.com/zeux/pugixml.git"
  GIT_TAG a0e064336317c9347a91224112af9933598714e9 ## Tag "v1.13"
)
add_subdirectory(pugixml)

FetchContent_Declare(
  cef
  ## Original Repo: https://bitbucket.org/chromiumembedded/cef/wiki/BranchesAndBuilding
  GIT_REPOSITORY "https://github.com/chromiumembedded/cef.git"
  GIT_TAG cd5e37ab62a1256f0b8ab20920f044d5fcad4ddf # Branch "5414"; Chromium Version 109, Nov 2022
)
#add_subdirectory(cef)
