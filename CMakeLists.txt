cmake_minimum_required(VERSION 3.8)
project(ds_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files
	"msg/Heartbeat.msg"
	"msg/ChangeState.msg"
	"msg/Connect.msg"
)

set(srv_files
	"srv/ChangeControlState.srv"
	"srv/NewConnection.srv"
)

set(type_files
	"types/StateType.msg"
)

rosidl_generate_interfaces(
    ${PROJECT_NAME}
    ${msg_files}
    ${srv_files}
    ${type_files}
)

# Export custom C++ headers for downstream packages.
install(
	FILES src/Constants.hpp
	DESTINATION include/${PROJECT_NAME}
)

ament_export_include_directories(include)


if(BUILD_TESTING)
	find_package(ament_lint_auto REQUIRED)
	# the following line skips the linter which checks for copyrights
	# comment the line when a copyright and license is added to all source files
	set(ament_cmake_copyright_FOUND TRUE)
	# the following line skips cpplint (only works in a git repo)
	# comment the line when this package is in a git repo and when
	# a copyright and license is added to all source files
	set(ament_cmake_cpplint_FOUND TRUE)
	ament_lint_auto_find_test_dependencies()
endif()

ament_package()
