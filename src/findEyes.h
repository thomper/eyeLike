#ifndef FIND_EYES_H
#define FIND_EYES_H

#include <opencv2/core/core.hpp>


void findEyes(cv::Mat face_gray, cv::Point &leftPupil, cv::Point &rightPupil);

#endif  // FIND_EYES_H
