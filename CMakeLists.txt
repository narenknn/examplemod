cmake_minimum_required(VERSION 3.0.0)
project (ctestgen)

add_definitions(-std=c++14)
set (CMAKE_CXX_STANDARD 14)

include(FetchContent)

if (NOT DEFINED EMSCRIPTEN)

  # Boost
  IF (WIN32)
    set(BOOST_ROOT C:\\boost)
  ENDIF()
  find_package( Boost REQUIRED COMPONENTS program_options regex )
  include_directories( ${Boost_INCLUDE_DIRS} )
  link_directories( ${Boost_LIBRARY_DIR} )

  if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-g)
  endif()

  include_directories(BEFORE )

  ## JSON
  FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
  FetchContent_MakeAvailable(json)

  ## StandAlone builds
  file (GLOB_RECURSE SRC_FILES src/*.cc)
  file (GLOB_RECURSE SA_FILES sa/*.cc)
  foreach( sfile ${SRC_FILES} )
    get_filename_component(sfname ${sfile} NAME_WE)
    add_definitions(-g)
    string(CONCAT sfname "sa_" ${sfname})
    add_executable(${sfname} ${sfile} ${SA_FILES})
    target_compile_definitions(${sfname} PUBLIC -DSABUILD)
    target_include_directories(${sfname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/sa ${json_SOURCE_DIR}/single_include)
  endforeach()

  ################################################################################
  ## Google test
  ################################################################################
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
    )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  ################################################################################
  ## ViewTests
  ################################################################################
  FetchContent_Declare(viewtests
    GIT_REPOSITORY https://github.com/narenknn/univtestviews.git
    )
  FetchContent_MakeAvailable(viewtests)

  enable_testing()

  include(GoogleTest)

  ## Loop through all modules
  file (GLOB_RECURSE COMMON_TEST_SOURCES ${viewtests_SOURCE_DIR}/src/*.cc ${viewtests_SOURCE_DIR}/top/*.cc)
  file (GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cc)
  foreach( tsf ${TEST_SOURCES} )
    get_filename_component( testname ${tsf} NAME_WLE )
    string(CONCAT uttestname "ut_" ${testname})
    add_executable( ${uttestname} ${tsf} ${COMMON_TEST_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/${testname}.cc)
    target_include_directories(${uttestname} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests ${CMAKE_CURRENT_SOURCE_DIR}/src ${json_SOURCE_DIR}/single_include ${viewtests_SOURCE_DIR}/src ${viewtests_SOURCE_DIR})
    target_link_libraries( ${uttestname} gtest_main )
    gtest_discover_tests( ${uttestname} )
  endforeach( tsf ${TEST_SOURCES} )

endif()
