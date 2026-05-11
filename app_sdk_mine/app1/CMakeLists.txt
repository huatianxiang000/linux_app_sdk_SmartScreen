cmake_minimum_required(VERSION 3.15)

project(demo1)

# 添加显式定义，定义宏 SIMULATOR_LINUX,这样才能在代码中识别到该宏
if(SIMULATOR_LINUX)
    add_compile_definitions(SIMULATOR_LINUX)  
endif()
# 拷贝res文件夹到build中，方便后续打包
file(COPY res DESTINATION ${PROJECT_BINARY_DIR})

add_executable(demo1 main.c page.c)
target_include_directories(demo1 PRIVATE
                                ./
                                res/
                                res/font/
                                ${CMAKE_SOURCE_DIR}/component/font
                                ${CMAKE_SOURCE_DIR}/lvgl
                                )

target_link_libraries(demo1 PRIVATE 
                           lvgl
                           font
                           )