# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.13)

project ("SpaceInvadersCMakeSDL")

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")


#set(SDL2_DIR "C:/dev/vcpkg/installed/x64-windows/share/sdl2")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Add SDL2 library

#add_subdirectory(Subdir)
file(GLOB SOURCE_FILES
		#Data
		"${PROJECT_SOURCE_DIR}/include/data/*.h"
		"${PROJECT_SOURCE_DIR}/src/data/*.cpp"

        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
		"${PROJECT_SOURCE_DIR}/include/engine/core/*.h"
		"${PROJECT_SOURCE_DIR}/src/engine/core/*.cpp"
		"${PROJECT_SOURCE_DIR}/include/engine/rendering/*.h"
		"${PROJECT_SOURCE_DIR}/src/engine/rendering/*.cpp"
		"${PROJECT_SOURCE_DIR}/include/engine/IO/*.h"
		"${PROJECT_SOURCE_DIR}/src/engine/IO/*.cpp"
		"${PROJECT_SOURCE_DIR}/include/engine/events/*.h"
		"${PROJECT_SOURCE_DIR}/src/engine/events/*.cpp"

		"${PROJECT_SOURCE_DIR}/include/engine/utility/*.h"
		"${PROJECT_SOURCE_DIR}/src/engine/utility/*.cpp"

		"${PROJECT_SOURCE_DIR}/include/engine/rendering/components/*.h"
		"${PROJECT_SOURCE_DIR}/src/engine/rendering/components/*.cpp"

		"${PROJECT_SOURCE_DIR}/include/gameplay/*.h"
		"${PROJECT_SOURCE_DIR}/src/gameplay/*.cpp"
		"${PROJECT_SOURCE_DIR}/include/gameplay/initializers/*.h"
		"${PROJECT_SOURCE_DIR}/src/gameplay/initializers/*.cpp"

        )

#file()
		
include_directories(PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#set(SDL2_IMAGE_PATH D:/Libraries/SDL2_image-2.6.3)
#set(SDL2_IMAGE_INCLUDE_DIR D:/Libraries/SDL2_image-2.6.3/include)
#set(SDL2_IMAGE_LIBRARY D:/Libraries/SDL2_image-2.6.3/lib/x64)
set(SDL2_IMAGE_DIR D:/Libraries/SDL2_image-2.6.3/cmake)
set(SDL2_DIR D:/Libraries/SDL2-2.26.4/cmake)
set(eventpp_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/eventpp")

set(BOOST_ROOT "D:/Libraries/boost_1_81_0") # Replace with the path to your Boost library
set(BOOST_INCLUDEDIR "D:/Libraries/boost_1_81_0")

list(APPEND CMAKE_MODULE_PATH "${SDL2_IMAGE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${SDL2_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${SDL2_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${SDL2_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${eventcpp_DIR}/cmake")

list(APPEND CMAKE_PREFIX_PATH "${SDL2_IMAGE_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${SDL2_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${eventpp_DIR}/cmake")


file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/Data)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/Resources/PNGS/MainMenu)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Debug/Resources/Fonts)
#execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${Data})

 if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SDL2_DIR "D:/Libraries/SDL2-2.26.4")
set(SDL2_INCLUDE_DIRS "D:/Libraries/SDL2-2.26.4/include")
set(SDL2_LIBRARY "D:/Libraries/SDL2-2.26.4/lib/x64/SDL2.lib")
set(SDL2_LIBRARY_MAIN "D:/Libraries/SDL2-2.26.4/lib/x64/SDL2main.lib")

set(SDL2_IMAGE_DIR "D:/Libraries/SDL2_image-2.6.3")
set(SDL2_IMAGE_INCLUDE_DIRS "D:/Libraries/SDL2_image-2.6.3/include")
set(SDL2_IMAGE_LIBRARY "D:/Libraries/SDL2_image-2.6.3/lib/x64/SDL2_image.lib")

set(BOOST_ROOT "D:/Libraries/boost_1_81_0") # Replace with the path to your Boost library
set(BOOST_INCLUDEDIR "D:/Libraries/boost_1_81_0")
set(Boost_USE_STATIC_LIBS ON)

set(eventpp_INCLUDE_DIRS "${eventpp_DIR}/include")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${SDL2_DIR}/lib/x64/SDL2.dll"
		"${SDL2_IMAGE_DIR}/lib/x64/SDL2_image.dll"
		"${SDL2_IMAGE_DIR}/lib/x64/SDL2_image.lib"# <--this is in-file
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)                 # <--this is out-file path

#find_package(Boost REQUIRED COMPONENTS signals2)
include_directories(${Boost_INCLUDE_DIRS})

#set(BOOST_DIR "D:/Libraries/boost_1_81_0/boost")
#set(BOOST_INCLUDE_DIRS "D:/Libraries/boost_1_81_0/boost")

#set(BOOST_S_DIR "D:/Libraries/boost_1_81_0/boost/signals2")
#set(BOOST_S_INCLUDE_DIRS "D:/Libraries/boost_1_81_0/boost/signals2")

#find_package(SDL2_IMAGE CONFIG REQUIRED)
#find_package(SDL2 CONFIG REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
#include_directories(SDL2)
#include_directories(${SDL_INCLUDE_DIR})
#
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
#include_directories(SDL2_IMAGE)
#include_directories(${SDL2_image_LIBRARY})
#include_directories(${SDL_IMAGE_INCLUDE_DIR})

include_directories("${BOOST_INCLUDEDIR}/boost")

include_directories(${eventpp_INCLUDE_DIRS})

#include_directories(${BOOST_S_INCLUDE_DIRS})
#include_directories(${Boost_INCLUDE_DIR})

# Set SDL libraries
#set(SDL_LIBRARIES SDL2 SDL2_IMAGE)

# Add SDL libraries to all targets in subdirectories
add_compile_options(-Wl,-rpath,${SDL_LIBRARY_DIRS})
link_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_IMAGE_INCLUDE_DIRS})
link_directories(${eventpp_INCLUDE_DIRS})
#link_directories(${BOOST_S_INCLUDE_DIRS})
#link_directories(${BOOST_INCLUDE_DIRS})
link_libraries(${SDL2_LIBRARY})
link_libraries(${SDL2_IMAGE_LIBRARY})

#link_libraries(${SDL_LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
#target_include_directories(${PROJECT_NAME} PUBLIC ${BOOST_S_INCLUDE_DIRS})
#target_include_directories(${PROJECT_NAME} PUBLIC ${BOOST_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${eventpp_INCLUDE_DIRS})

#target_link_libraries(${PROJECT_NAME} SDL2::Main)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_LIBRARY_MAIN})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

add_subdirectory ("Subdir")

# Include sub-projects.
