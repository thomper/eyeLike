#include "opencv2/imgproc/imgproc.hpp"

#include "constants.h"
#include "findEyeCenter.h"
#include "findEyes.h"


void findEyes(cv::Mat face_gray, cv::Point &leftPupil, cv::Point &rightPupil) {
  cv::Size sz = face_gray.size();

  if (kSmoothFaceImage) {
    double sigma = kSmoothFaceFactor * sz.width;
    GaussianBlur( face_gray, face_gray, cv::Size( 0, 0 ), sigma);
  }

  //-- Guess eye regions
  int eye_region_width = sz.width * (kEyePercentWidth/100.0);
  int eye_region_height = sz.width * (kEyePercentHeight/100.0);
  int eye_region_top = sz.height * (kEyePercentTop/100.0);
  cv::Rect leftEyeRegion(sz.width*(kEyePercentSide/100.0),
                         eye_region_top, eye_region_width, eye_region_height);
  cv::Rect rightEyeRegion(sz.width - eye_region_width - sz.width*(kEyePercentSide/100.0),
                          eye_region_top, eye_region_width, eye_region_height);

  //-- Find Eye Centers
  leftPupil = findEyeCenter(face_gray, leftEyeRegion);
  rightPupil = findEyeCenter(face_gray, rightEyeRegion);

  // change eye centers to face coordinates
  rightPupil.x += rightEyeRegion.x;
  rightPupil.y += rightEyeRegion.y;
  leftPupil.x += leftEyeRegion.x;
  leftPupil.y += leftEyeRegion.y;
}
