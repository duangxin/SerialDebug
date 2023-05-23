cmake_minimum_required(VERSION 3.25)

project(SerialDebug VERSION 0.1 LANGUAGES CXX)

#添加串口模块find_package(Qt6 REQUIRED COMPONENTS Core Gui  )Qt6::Core Qt6::Gui
find_package(Qt6 REQUIRED COMPONENTS Widgets SerialPort)




qt_standard_project_setup()

qt_add_executable(SerialDebug)

target_sources(SerialDebug
    PRIVATE
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        
    PUBLIC
        
)

target_compile_features(SerialDebug PRIVATE cxx_std_20)

target_link_libraries(SerialDebug 
    PRIVATE 
        Qt6::Widgets
        Qt6::SerialPort #链接该模块
)












































# set_target_properties(SerialDebug PROPERTIES
#     MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# install(TARGETS SerialDebug
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(SerialDebug)
# endif()





#qt_add_executable(SerialDebug)  //Creates and finalizes an application target of a platform-specific type.
#This command performs the following tasks:

#    1. Create a CMake target of the appropriate type for the target platform.
#    2. Link the target to the Qt::Core library.
#    3. Handle finalization of the CMake target.



# qt_standard_project_setup()     #set(CMAKE_AUTOUIC ON)  set(CMAKE_AUTOMOC ON)  set(CMAKE_AUTORCC ON)

