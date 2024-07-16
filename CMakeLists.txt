# Virtual base class for LiquidCrystal and LiquidCrystal_I2C libraries
# https://github.com/VladVanyuk/LiquidCrystal
# MIT License

cmake_minimum_required(VERSION 3.5)

idf_component_register(SRCS "MultiVariable.cpp"
                       INCLUDE_DIRS ".", "./core"
                       REQUIRES arduino)

project(Multi_Variable)