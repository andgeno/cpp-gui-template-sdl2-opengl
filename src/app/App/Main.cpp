/*
 * Copyright (c) 2022 Martin Helmut Fieber <info@martin-fieber.se>
 */

#define SDL_MAIN_HANDLED

#include "Core/Application.hpp"
#include "Core/Instrumentor.hpp"
#include "Core/Log.hpp"




// =================================================================================================
// == GENO TESTS: START
// =================================================================================================
#include <iostream>

#include <sqlite3.h>
void test_sqlite3() {
  sqlite3* db = nullptr;
  [[maybe_unused]] char* zErrMsg = nullptr;
  int rc = 0;

  rc = sqlite3_open("test.db", &db);
  if(rc != 0) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return;
  }

  fprintf(stdout, "Opened database successfully\n");
  sqlite3_close(db);
}

#include <nlohmann/json.hpp>
using json = nlohmann::json;
void test_json() {
  json ex1 = json::parse(R"(
    {
      "pi": 3.141,
      "happy": true
    }
  )");

  std::cout << "json: " << ex1 << std::endl;
}

#include "pugixml.hpp"
int test_pugixml() {
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file("xgconsole.xml");
  if (!result) {
    return -1;
  }

  for (pugi::xml_node tool: doc.child("Profile").child("Tools").children("Tool"))
  {
      int timeout = tool.attribute("Timeout").as_int();

      if (timeout > 0) {
        std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout
                  << "\n";
      }
  }

  return 0;
}

#include <curl/curl.h>
void test_curl() {
  #ifdef LIBCURL_VERSION
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.chucknorris.io/jokes/random");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
    struct curl_slist *headers = NULL;
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    res = curl_easy_perform(curl);
    int x = 1;
    x++;
  }
  curl_easy_cleanup(curl);
  #endif
}

//#include "include/cef_browser.h"
//#include "include/cef_app.h"
void test_cef() {
//  CefRefPtr<CefClient> ptr;
//
//  CefMainArgs args;
//  CefSettings settings;
//
//  CefInitialize(args, settings, nullptr, nullptr);
}

void tests() {
  test_sqlite3();
  test_json();
  test_pugixml();
  test_curl();
  test_cef();
}
// =================================================================================================
// == GENO TESTS: END
// =================================================================================================




int main() {
  tests();

  try {
    APP_PROFILE_BEGIN_SESSION_WITH_FILE("App", "profile.json");

    {
      APP_PROFILE_SCOPE("Test scope");
      App::Application app{"App"};
      app.run();
    }

    APP_PROFILE_END_SESSION();
  } catch (std::exception& e) {
    APP_ERROR("Main process terminated with: {}", e.what());
  }

  return 0;
}
