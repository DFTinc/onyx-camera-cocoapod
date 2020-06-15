#ifndef FINGER_DETECT_H_
#define FINGER_DETECT_H_

#include <vector>
#include <opencv2/core/core.hpp>

#include "dft/Finger.h"

namespace dft
{

std::vector<Finger> findFingersImpl(const cv::Mat &mask, cv::Mat &finger_mask);

}

#endif
