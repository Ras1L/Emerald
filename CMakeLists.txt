cmake_minimum_required(VERSION 3.19)
project(Emerald LANGUAGES CXX)

find_package(Qt6 6.11 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

include_directories(include/)

qt_add_executable(Emerald
    WIN32 MACOSX_BUNDLE
    main.cpp
    src/Application/markdowneditorsession.cpp
    src/Core/markdowndocument.cpp
    src/Presentation/markdowneditor.cpp
    src/Presentation/mainwindow.cpp
    include/Application/markdowneditorsession.h
    include/Core/markdowndocument.h
    include/Presentation/markdowneditor.h
    include/Presentation/mainwindow.h
)

target_link_libraries(Emerald
    PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

install(TARGETS Emerald
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Emerald
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
