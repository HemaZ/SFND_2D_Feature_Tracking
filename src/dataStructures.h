#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <opencv2/core.hpp>


struct DataFrame { // represents the available sensor information at the same time instance
    
    cv::Mat cameraImg; // camera image
    
    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> kptMatches; // keypoint matches between previous and current frame
};
template<typename T>
class RingBuffer{
public:
    RingBuffer(int);
    T at(int);
    void add(T);
    size_t size();
    typename std::vector<T>::iterator end();
private:
    std::vector<T> bdata;
    size_t bsize;
};
#endif /* dataStructures_h */
