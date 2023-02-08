#include <iostream>
#include "bit_vector.h"

int main(){
    BitVector vec = BitVector(67);
    
    //std::cout << vec2 << std::endl;
    //std::cout << "----------" << std::endl;
    vec.set(66);
    //vec.set(61);
    //vec.set(62);
    vec.set(32);
    //std::cout << vec[0] << std::endl;
    //vec.set(2);
    //vec.set(49);
    //std::cout << vec2 << std::endl;
    // vec.set(15);
    //vec.reset(3);
    //vec.reset(2);
    std::cout << vec << std::endl;
    // std::cout << "----------" << std::endl;
    // std::cout << vec << std::endl;
    
    return 0;
}