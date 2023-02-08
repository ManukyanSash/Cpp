#include <iostream> 
#include <math.h>
#include <stdexcept>
#include "bit_vector.h"


BitVector::BitVector(){
    m_int_count = 1 / BIT_COUNT + (1 % BIT_COUNT != 0);
    m_vector = new unsigned int(0);
    m_bits = 1;
}

BitVector::BitVector(int bits){
    if(bits <= 0){
        throw std::invalid_argument("The number of bits can't be zero or negative");
    }
    m_int_count = bits / BIT_COUNT + (bits%BIT_COUNT != 0);
    m_vector = new unsigned int[m_int_count];
    m_bits = bits;
};

BitVector::~BitVector(){
    delete [] m_vector;
    m_vector = nullptr;
};

const unsigned int& BitVector::operator[](int index) const{
    if(index >= m_int_count || index < 0){
        throw std::invalid_argument("Out of range");
    }   
    return m_vector[index];
}

std::ostream& operator<<(std::ostream& os, const BitVector& dt){
    std::string binary_out = "";
    for(int i = dt.m_int_count-1; i >= 0; --i){
        binary_out += dt.m_to_binary(dt[i], dt.BIT_COUNT);
    }
    binary_out = binary_out.substr(binary_out.length() - dt.m_bits);
    os << binary_out;
    return os;
}


BitVector& BitVector::operator=(BitVector& other){
    if(this != &other)
    {
        m_bits = other.m_bits;
        m_int_count = other.m_int_count;
        delete[] m_vector;
        m_vector = other.m_vector;
        other.m_vector = nullptr;
    }

    return *this;    
}

BitVector& BitVector::operator=(const BitVector& bv){
    if(this != &bv)
    {
        m_bits = bv.m_bits;
        m_int_count = bv.m_int_count;
        delete[] m_vector;
        m_vector = new unsigned int[m_int_count];

        for(int i = 0; i < m_int_count; ++i)
        {
            m_vector[i] = bv.m_vector[i];
        }
    }

    return *this;    
}

BitVector::BitVector(const BitVector& other)
{
    m_bits = other.m_bits;
    m_int_count = other.m_int_count;
    m_vector = new unsigned int[m_int_count];
    for(int i = 0; i < m_int_count; ++i){
        m_vector[i] = other.m_vector[i];
    }        
}

BitVector::BitVector(BitVector&& other){
    m_bits = other.m_bits;
    m_int_count = other.m_int_count;
    m_vector = other.m_vector;
    other.m_vector = nullptr;
}

void BitVector::set(int bit){
    if(bit >= m_bits){
        throw std::invalid_argument("Out of range");
    }
    int bit_index = bit / BIT_COUNT;
    m_vector[bit_index] |= (1u << bit-(bit_index*BIT_COUNT));
}

void BitVector::reset(int bit){
    if(bit >= m_bits){
        throw std::invalid_argument("Out of range");
    }
    int bit_index = bit / BIT_COUNT;
    m_vector[bit_index] &= ~(1u<< bit-(bit_index*BIT_COUNT)); 
}

std::string BitVector::m_to_binary(unsigned int num, int count) const {
    std::string binary_num;
    for (int i = 0; i < count; ++i) {
        binary_num.insert(0, std::to_string(num % 2));
        num /= 2;
    }
    return binary_num;
}