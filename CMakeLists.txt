cmake_minimum_required(VERSION 3.15)
project(DungeonEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dungeon_editor
    src/main.cpp
    src/npc/npc.cpp
    src/npc/bear.cpp
    src/npc/werewolf.cpp
    src/npc/bandit.cpp
    src/factory/npc_factory.cpp
    src/visitor/battle_visitor.cpp
    src/observer/console_observer.cpp
    src/observer/file_observer.cpp
    src/manager/npc_manager.cpp
)

enable_testing()
find_package(GTest REQUIRED)

add_executable(tests
    tests/test_main.cpp
    tests/test_npc.cpp
    tests/test_factory.cpp
    tests/test_battle.cpp
    src/npc/npc.cpp
    src/npc/bear.cpp
    src/npc/werewolf.cpp
    src/npc/bandit.cpp
    src/factory/npc_factory.cpp
    src/visitor/battle_visitor.cpp
    src/observer/console_observer.cpp
    src/observer/file_observer.cpp
    src/manager/npc_manager.cpp
)

target_link_libraries(tests GTest::gtest GTest::gtest_main)
add_test(NAME AllTests COMMAND tests)