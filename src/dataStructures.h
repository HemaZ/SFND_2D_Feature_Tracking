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

template<typename T>
RingBuffer<T>::RingBuffer(int size){
    this->bsize = size;
}
template<typename T>
void RingBuffer<T>::add(T elm){
    if(this->bdata.size()==this->bsize){
        this->bdata.erase(this->bdata.begin());
    }
    this->bdata.push_back(elm);
}
template<typename T>
size_t RingBuffer<T>::size(){
    return this->bdata.size();
}
template<typename T>
T RingBuffer<T>::at(int idx){
    if(idx>=this->bsize){
        idx = bsize-1; 
    }
    return this->bdata.at(idx);
}
template<typename T>
typename std::vector<T>::iterator RingBuffer<T>::end(){
    return this->bdata.end();
}

#endif /* dataStructures_h */
