/// \file core.h
/// \brief This file defines the base functionality of the onyx-core SDK.
/// \copyright Copyright 2014 Diamond Fortress Technologies, Inc. All rights reserved.
/// \author Will Lucas

#ifndef CORE_H_
#define CORE_H_

#include "Finger.h"
#include "FingerprintTemplate.h"
#include "MatchResult.h"
#include "CaptureUtils.h"
#include <vector>
#include <opencv2/core/core.hpp>

/// \namespace dft Top-level Diamond Fortress Technologies namespace.
namespace dft
{

/// This function preprocesses a fingerprint image for use with generateFingerprintTemplate.
/// \param[in] src an 8-bit grayscale fingerprint image to be preprocessed.
/// \param[out] dst an 8-bit grayscale preprocessed fingerprint image.
/// \param[in] sigma1 amount of blur for the mean calculation (default = 2)
/// \param[in] sigma2 amount of blur for the standard deviation (default = 1)
/// \return an image quality measure, a value greater than or equal to 60 is good.
/// \throws DftException if an error occurs.
/// \see generateFingerprintTemplate
double preprocessFingerprint(const cv::Mat& src, cv::Mat& dst, double sigma1 = 2.0, double sigma2 = 1.0);

/// This function enhances a fingerprint image for use with generateFingerprintTemplate.
/// \param[in] src an 8-bit grayscale image that has been preprocessed first.
/// \param[out] enhanced an 8-bit grayscale image that has been enhanced.
/// \param[out] energyMask an 8-bit binary mask for quality filtering purposes.
/// \throws DftException if an error occurs.
/// \see preprocessFingerprint
void enhanceFingerprint(const cv::Mat& src, cv::Mat& enhanced, cv::Mat& energyMask);

/// This function generates a fingerprint template from a preprocessed image.
/// \param[in] src an 8-bit grayscale preprocessed fingerprint image.
/// \param[in] mask an 8-bit mask used to filter the detected feature locations.
/// \return a pointer to a FingerprintTemplate.
/// \note It is up to the client to manage the returned pointer.
/// \throws DftException if an error occurs.
/// \see FingerprintTemplate
FingerprintTemplate* generateFingerprintTemplate(const cv::Mat& src, const cv::Mat& mask = cv::Mat());

/// This function generates an ISO fingerprint template from a preprocessed image.
/// \param[in] src an 8-bit grayscale preprocessed fingerprint image.
/// \param[in] mask an 8-bit mask used to filter the detected feature locations.
/// \return a pointer to an ISO formatted FingerprintTemplate.
/// \note It is up to the client to manage the returned pointer.
/// \throws DftException if an error occurs.
/// \see FingerprintTemplate
FingerprintTemplate* generateIsoFingerprintTemplate(const cv::Mat& src, const cv::Mat& mask = cv::Mat());

/// This function performs a 1:1 match on two fingerprint templates.
/// \param[in] reference the first fingerprint template to verify with.
/// \param[in] probe the second fingerprint template to verify with.
/// \return the match score between [0, 1]. Higher is better.
/// \throws DftException if an error occurs.
/// \see FingerprintTemplate
float verify(const FingerprintTemplate& reference, const FingerprintTemplate& probe);

/// This function performs a 1:1 match on two fingerprint templates.
/// \param[in] reference the first fingerprint template to verify with.
/// \param[in] probe the image to be pyramided.
/// \param[in] scales a vector of scales to increase depth tolerance.
/// \return the match score between [0, 1]. Higher is better.
/// \throws DftException if an error occurs.
/// \see FingerprintTemplate
float pyramidVerify(const FingerprintTemplate& reference, const cv::Mat& probe, const std::vector<double>& scales = std::vector<double>());

/// This function performs a 1:N match on templates supplied in the gallery.
/// \param[in] gallery a vector of FingerprintTemplates.
/// \param[in] probe a single FingerprintTemplate to match against the gallery.
/// \return the MatchResult containing the top matching score as well as the matched index in the gallery.
/// \note All matches are performed in parallel.
/// \throws DftException if an error occurs.
/// \see FingerprintTemplate
/// \see MatchResult
MatchResult identify(const std::vector<FingerprintTemplate>& gallery, const FingerprintTemplate& probe);

/// This function performs a 1:N match on templates supplied in the gallery.
/// \param[in] gallery a vector of FingerprintTemplates.
/// \param[in] probe an image to match against the gallery.
/// \param[in] scales a vector of scales to increase depth tolerance.
/// \return the MatchResult containing the top matching score as well as the matched index in the gallery.
/// \note All matches are performed in parallel.
/// \throws DftException if an error occurs.
/// \see FingerprintTemplate
/// \see MatchResult
MatchResult pyramidIdentify(const std::vector<FingerprintTemplate>& gallery, const cv::Mat& probe, const std::vector<double>& scales = std::vector<double>());

/// This member locates a fingertip in a grayscale image.
/// \param[in] src the 8-bit grayscale image possibly containing a finger.
/// \param[in] detectMode 0 means dead finger mode, 1 means alive finger mode.
/// \return a Finger object containing the location of the finger as well as its contour.
/// \throws DftException if an error occurs.
Finger findFinger(const cv::Mat& src, int detectMode = 1);

/// This member function analyzes the fingertip focus.
/// \param[in] src the 8-bit grayscale image to analyze for focus.
/// \param[in] finger a Finger object describing the detected finger.
/// \return a focus measure from [0, 1]. 0 being the worst and 1 being the best.
/// \throws DftException if an error occurs.
/// \see findFinger
double focusMeasure(const cv::Mat& src, const Finger& finger);


/// This member function segments the finger from the background.
/// \param[in] src the color image to segment
/// \param[out] dst the color image segmented image.
/// \param[out] fingerMask the binary mask used to segment the finger.
/// \throws DftException if an error occurs.
void segmentFinger(const cv::Mat& src, cv::Mat& dst, cv::Mat& fingerMask, const cv::Size& kernelSize = cv::Size(5, 5));

/// This member function segments the finger from the background.
/// \param[in] yuvCamera2 the YUV_420_888 Camera2 image to process.
/// \param[in] imageSize the image size.
/// \param[in] yRowStride the row stride of the luminance.
/// \param[in] yPixelStride the pixel stride of the luminance.
/// \param[in] uvRowStride the row stride of the chrominance.
/// \param[in] uvPixelStride the pixel stride of the chrominance.
/// \return properly formatted byte array for OpenCV color conversion.
std::vector<unsigned char> yuvCamera2ToYuvOcv(
        const std::vector<unsigned char> &yuvCamera2,
        const cv::Size &imageSize,
        int yRowStride,
        int yPixelStride,
        int uvRowStride,
        int uvPixelStride);

/// This member function performs liveness detection on the given image
/// \param[in] src the BGR image to classify
/// \param[in] modelFile a file containing the Tensorflow neural network.
/// \return Mat containing real confidence as first element, fake confidence as second element.
void checkLiveness(const cv::Mat& src, const std::string& modelFile, cv::Mat& result);

}


#endif /* CORE_H_ */
