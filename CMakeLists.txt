# 指定需要cmake的最低版本
cmake_minimum_required(VERSION 3.20.0)

# 通过cmake package加入Zephyr构建系统
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# 指定应用工程名称为zpro，必须在find_package后
project(zpro)

# 将应用的代码加入构建，必须在find_package后
target_sources(app PRIVATE src/main.c)
