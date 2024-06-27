cmake_minimum_required(VERSION 3.5)

project(Advanced-Tic-Tac-Toe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test Sql)

set(PROJECT_SOURCES
    main.cpp
    src/ui/game_screen/game_screen.cpp
    src/ui/game_screen/game_screen.h
)

set(SOURCE_FILES
    utilities/main_includes.h
    src/ui/main_screen/main_screen.h
    src/ui/main_screen/main_screen.cpp
    src/ui/main_screen/mainscreen.ui
    src/ui/game_screen/CellButton.cpp
    src/ui/game_screen/CellButton.h
    src/ui/game_screen/game_screen.h
    src/ui/game_screen/game_screen.cpp
    src/ui/game_screen/gamescreen.ui
    utilities/Buttons/Custom_Button.cpp
    utilities/Animation/animation.cpp
    utilities/Animation/animation.h
    utilities/Buttons/custom_button.h
    src/ui/main_screen/main_screen.cpp
    src/ui/main_screen/main_screen.h
    src/ui/main_screen/main_screen.cpp
    src/ui/sign_screen/sign_screen.h
    src/ui/sign_screen/sign_screen.cpp
    src/ui/sign_screen/signscreen.ui
    src/ui/sign_screen/database.h
    src/ui/sign_screen/database.cpp
    src/ui/history_screen/history_screen.h
    src/ui/history_screen/history_screen.cpp
    src/ui/history_screen/historyscreen.ui
    src/ui/game_screen/CellButton.cpp
    src/ui/game_screen/CellButton.h
    src/ui/game_screen/game_screen.cpp
    src/ui/game_screen/game_screen.h
    src/ui/game_screen/gamescreen.ui
    src/ui/history_screen/history_screen.cpp
    src/ui/history_screen/history_screen.h
    src/ui/history_screen/historyscreen.ui
    src/ui/main_screen/main_screen.cpp
    src/ui/main_screen/main_screen.h
    src/ui/main_screen/mainscreen.ui
    src/ui/sign_screen/database.cpp
    src/ui/sign_screen/database.h
    src/ui/sign_screen/sign_screen.cpp
    src/ui/sign_screen/sign_screen.h
    src/ui/sign_screen/signscreen.ui
    src/ui/replay_screen/mainwindow.ui
    src/ui/replay_screen/replayscreen.h
    src/ui/replay_screen/replayscreen.cpp
    src/ui/replay_screen/CellButtonR.cpp
    src/ui/replay_screen/CellButtonR.h
)

set(TEST_SOURCES
    Tests/test_gamelogic.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Advanced-Tic-Tac-Toe
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${SOURCE_FILES}
    )

    qt_add_executable(test_gamelogic
        MANUAL_FINALIZATION
        ${TEST_SOURCES}
        ${SOURCE_FILES}
    )
else()
    if(ANDROID)
        add_library(Advanced-Tic-Tac-Toe SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Advanced-Tic-Tac-Toe
            ${PROJECT_SOURCES}
        )

        add_executable(test_gamelogic
            ${TEST_SOURCES}
            ${SOURCE_FILES}
        )
    endif()
endif()

target_link_libraries(Advanced-Tic-Tac-Toe PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(test_gamelogic PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Test)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Advanced-Tic-Tac-Toe)
endif()
set_target_properties(Advanced-Tic-Tac-Toe PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Advanced-Tic-Tac-Toe
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Advanced-Tic-Tac-Toe)
    qt_finalize_executable(test_gamelogic)
endif()

enable_testing()
add_test(NAME test_gamelogic COMMAND test_gamelogic)
