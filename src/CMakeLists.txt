cmake_minimum_required(VERSION 3.2)

project(MusicAppl)

add_library(MusicAppl_src
		App/MusicApp.cpp
		Artist/Artist_class.cpp
		Artist/Song_class.cpp
		User/User.cpp
		Podcast/Podcast_class.cpp
)

add_executable(MusicAppl main.cpp)

target_link_libraries(MusicAppl
	PRIVATE
		MusicAppl_src
)

target_include_directories(MusicAppl
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(MusicAppl_src
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
	)