# Midterm Report
## MP.1 Data Buffer Optimization:
 * I've implemented a new template class which i called "RingBuffer" in dataStructers.h file. the class simply contains a private vector which can be accessed by the member functions.
*  The function add() checks if the vector is full, it removes the first element of the vector and add the new element at the end.  

## MP.2 Keypoint Detection:
* OpenCV offers a great number of KeyPoints Detectors. In this task it is required to implement detectors HARRIS, FAST, BRISK, ORB, AKAZE, and SIFT.
* `void detKeypointsModern(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, std::string detectorType, double &totaltime, bool bVis=false);
` This function takes the detector type as a string and create an opencv detector fo the same type.

## MP.3 Keypoint Removal
* This task requirement is to filter out the keypoints which lay outside a certain region.
* I've cropped the input image to include only the region of interest. 
* This approach would save computation time and reduce the total number of keypoints.

## MP.4 Keypoint Descriptors
* In this task we should use a certain number of opencv descriptors by definig the descriptor type.
* These descriptors are BRIEF, ORB, FREAK, AKAZE and SIFT.
* Opencv offers a unified type for the descriptors which is `cv::DescriptorExtractor` 
* The function `descKeypoints` takes the descriptor type as an input argument. 
* depending on this type an descriptor object is created and used. 
## MP.5 Descriptor Matching
* After computing the descriptors of each keypoint the next step is to match the keypoints between different images.
* OpenCV offers 2 matching algorithms which are Brute Force and FLANN and it offers also a unified type which is `cv::DescriptorMatcher`
* Brute force algorithm is straightforward and uses L2 Norm or HAMMING depending on the descriptor type.
* FLANN Matcher implementation in opencv requires some attention as it complains about descriptors data types.
* So all descriptors should be converted to `CV_32F` if we are going to use FLANN Matcher.
## MP.6 Descriptor Distance Ratio
* The matchers return the nearest neighbor for every keypoint.
* We implement the KNearest neighbor and use the distance ratio test.
* This test could be very useful to reduce number of false positive detection. 
* The two best matches and the ratio between the descriptor distances is computed.
* A threshold is applied to the ratio and if the condition is satisfied the nearest match is considered. 
## MP.7 Performance Evaluation 1
 * The KeyPoints Detector function prints the number of keypoints for every image.
 * Because the image is cropped in task 3 the keypoints number correspond to the number of keypoints on the preceding vehicle.
## MP.8 Performance Evaluation 2
* By varying the combination of Detectors and descriptors we can count the number of matched keypoints.
* The matching function print the number of matched points.
## MP.9 Performance Evaluation 3
* I've declared an extra variable `double totaltime` and passed it in all the detectors, descriptors and matchers function.
* These function add their processing time to this variable.
* At the end of the main function i print this variable. 
* I've logged the total time for every combination of detectors and descriptors.
* I've also logged the total number of matched keypoints.
* These data could be found in the following PDF [link](docs/Performance_Evaluation.pdf).
* Based on the computation time and total number of matched keypoints the best 3 combinations were recommended.
* These top 3 combinations are:
    1. HARRIS & BRIEF
    2. FAST & ORB
    3. FAST & BRIEF

# SFND 2D Feature Tracking

<img src="images/keypoints.png" width="820" height="248" />

The idea of the camera course is to build a collision detection system - that's the overall goal for the Final Project. As a preparation for this, you will now build the feature tracking part and test various detector / descriptor combinations to see which ones perform best. This mid-term project consists of four parts:

* First, you will focus on loading images, setting up data structures and putting everything into a ring buffer to optimize memory load. 
* Then, you will integrate several keypoint detectors such as HARRIS, FAST, BRISK and SIFT and compare them with regard to number of keypoints and speed. 
* In the next part, you will then focus on descriptor extraction and matching using brute force and also the FLANN approach we discussed in the previous lesson. 
* In the last part, once the code framework is complete, you will test the various algorithms in different combinations and compare them with regard to some performance measures. 

See the classroom instruction and code comments for more details on each of these parts. Once you are finished with this project, the keypoint matching part will be set up and you can proceed to the next lesson, where the focus is on integrating Lidar points and on object detection using deep-learning. 

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * This must be compiled from source using the `-D OPENCV_ENABLE_NONFREE=ON` cmake flag for testing the SIFT and SURF detectors.
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./2D_feature_tracking`.