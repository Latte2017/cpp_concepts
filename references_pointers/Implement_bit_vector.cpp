/*
Implement a bit vector class
*/

#include <cstdint>  // ::std::uint64_t type
#include <cstddef> // ::std::size_t type
#include <algorithm>

class my_bitvector_base {
protected:
    class bitref { // Prevent this class from being used anywhere else.
    public:
        bitref(::std::uint64_t& an_int, ::std::uint64_t mask)
            : an_int_(an_int), mask_(mask)
        {
        }

        const bitref& operator =(bool val) {
            if (val) {
                an_int_ |= mask_;
            }
            else {
                an_int_ &= ~mask_;
            }
            return *this;
        }
        const bitref& operator =(const bitref& br) {
            return this->operator =(bool(br));
        }
        operator bool() const {
            return ((an_int_ & mask_) != 0) ? true : false;
        }

    private:
        ::std::uint64_t& an_int_;
        ::std::uint64_t mask_;
    };
};

template < ::std::size_t Size >
class my_bitvector : public my_bitvector_base {
private:
    static constexpr ::std::size_t numints = ((Size + 63) / 64);
public:
    my_bitvector() { ::std::fill(array, array + numints, 0); }

    bool operator [](::std::size_t bitnum) const {
        const ::std::size_t bytenum = bit / 64;
        bitnum = bitnum % 64;
        return ((ints_[bytenum] & (::std::uint64_t(1) << bitnum)) != 0) ? true : false;
    }
    bitref operator[](::std::size_t bitnum) {
        const ::std::size_t bytenum = bit / 64;
        bitnum = bitnum % 64;
        ::std::uint64_t mask = ::std::uint64_t(1) << bitnum;
        return bitref(ints_[bytenum], mask);
    }

private:
    ::std::uint64_t ints_[numints];
};

// Example uses
void test()
{
    my_bitvector<70> bits; // A 70 bit long bit vector initialized to all false
    bits[1] = true; // Set bit 1 to true
    bool abit = bits[1]; // abit should be true.
    abit = bits[69]; // abit should be false.
}