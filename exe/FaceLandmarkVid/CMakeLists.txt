# Local libraries
include_directories(${LandmarkDetector_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)

add_executable(FaceLandmarkVid FaceLandmarkVid.cpp)
target_link_libraries(FaceLandmarkVid LandmarkDetector)
target_link_libraries(FaceLandmarkVid FaceAnalyser)
target_link_libraries(FaceLandmarkVid GazeAnalyser)
target_link_libraries(FaceLandmarkVid Utilities)
target_link_libraries(FaceLandmarkVid ${OpenCV_LIBS})
target_link_libraries(FaceLandmarkVid commClient)

install (TARGETS FaceLandmarkVid DESTINATION bin)