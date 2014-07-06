ADD_EXECUTABLE( eyeLike main.cpp findEyes.cpp findEyeCenter.cpp helpers.cpp)
TARGET_LINK_LIBRARIES( eyeLike ${OpenCV_LIBS} )
