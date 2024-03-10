# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 00:23:17 by abelov            #+#    #+#              #
#    Updated: 2024/03/10 00:23:22 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.8.2)

project(42 LANGUAGES C)

set(FTLIB_name FTLIB)
set(FTLIB_filename libft.a)
set(FTLIB_dir ${CMAKE_CURRENT_SOURCE_DIR}/ftlib)
set(FTLIB_build_dir ${CMAKE_CURRENT_SOURCE_DIR}/ftlib/build)

file(GLOB FTLIB_HEADERS "${FTLIB_dir}/*.h")
file(GLOB FTLIB_SOURCES "${FTLIB_dir}/**/ft_*.c")

add_custom_target(${FTLIB_name}_target ALL
        COMMAND make -C ${FTLIB_dir}
        BYPRODUCTS ${FTLIB_build_dir}/${FTLIB_filename}
        SOURCES "${FTLIB_HEADERS};${FTLIB_SOURCES}"
        COMMENT "Building FTLIB")
add_library(${FTLIB_name} STATIC IMPORTED)
add_dependencies(${FTLIB_name} ${FTLIB_name}_target)
set_target_properties(${FTLIB_name} PROPERTIES
        IMPORTED_LOCATION "${FTLIB_build_dir}/${FTLIB_filename}" # Make sure to use absolute path here
        INTERFACE_COMPILE_DEFINITIONS "OPTIMISTIC"
        INTERFACE_SOURCES "${FTLIB_HEADERS};${FTLIB_SOURCES}"
        INTERFACE_INCLUDE_DIRECTORIES "${FTLIB_dir};${CMAKE_CURRENT_SOURCE_DIR}/include")
add_custom_target(fclean ALL)
add_custom_command(TARGET fclean POST_BUILD
        COMMAND make -C ${FTLIB_dir} fclean)

add_subdirectory(fsm)
add_subdirectory(fsm1)
add_subdirectory(fsm2)
add_subdirectory(fsm3)
