#include "dataStructures.h"
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