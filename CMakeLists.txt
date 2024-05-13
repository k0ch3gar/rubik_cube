cmake_minimum_required(VERSION 3.27)
project(rubik_cube)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_executable(${PROJECT_NAME} main.cpp
        window/Window.cpp
        window/Window.h
        window/EventHandler.cpp
        window/EventHandler.h
        graphics/Shader.cpp
        graphics/Shader.h
        camera/Camera.cpp
        camera/Camera.h
        rubik/cube/Cube.cpp
        rubik/cube/Cube.h
        rubik/Rubik.cpp
        rubik/Rubik.h
        algorithm/basicAlgorithm/BasicAlgorithm.cpp
        algorithm/basicAlgorithm/BasicAlgorithm.h
        algorithm/Rotation.cpp
        algorithm/Rotation.h
        algorithm/firstLayer/FirstLayer.cpp
        algorithm/firstLayer/FirstLayer.h
        algorithm/secondLayer/BuildSecondLayer.cpp
        algorithm/secondLayer/BuildSecondLayer.h
        test/Test.cpp
        test/Test.h
        algorithm/scramble/Scramble.cpp
        algorithm/scramble/Scramble.h
        algorithm/thirdLayer/ThirdLayer.cpp
        algorithm/thirdLayer/ThirdLayer.h
        algorithm/RubikAlgorithm.cpp
        algorithm/RubikAlgorithm.h
        logger/Logger.cpp
        logger/Logger.h
        algorithm/FileReader.cpp
        algorithm/FileReader.h
)

target_link_libraries(${PROJECT_NAME}
        glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES}
        libglew_static
        glm::glm
)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLEW_INCLUDES})



