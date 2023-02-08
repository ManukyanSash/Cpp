#ifndef BIT_VECTOR_H
#define BIT_VECTOR_H

#include <iostream>

class BitVector{
    public:
        BitVector();
        BitVector(int);
        BitVector(const BitVector&);
        BitVector(BitVector&&);
        ~BitVector();

        friend std::ostream& operator<<(std::ostream&, const BitVector&);
        const unsigned int& operator[](int) const;
        BitVector& operator=(const BitVector&);
        BitVector& operator=(BitVector&);

        void set(int);
        void reset(int);   

    private:    
        unsigned int* m_vector;
        static const int BIT_COUNT = sizeof(int)*8;
        int m_bits;
        int m_int_count;    
        std::string m_to_binary(unsigned int, int) const;
};

#endif //BIT_VECTOR_H