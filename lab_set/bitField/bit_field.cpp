#include "bit_field.h"

size_t TBitField::GetMemIndex(size_t pos) const noexcept
{
    return memLen - pos / (sizeof(elem_type) * 8) - 1;
}

elem_type TBitField::GetMemMask(size_t pos) const noexcept
{
    return 1 << (pos % (sizeof(elem_type) * 8));
}

TBitField::TBitField(size_t _BitLen) // конструктор специального вида
{
    if (_BitLen <= 0) { throw std::logic_error("Out of range."); }
    else {
        bitLen = _BitLen;
        memLen = (_BitLen - 1) / (8 * sizeof(elem_type)) + 1;
        pMem = new elem_type[memLen];
        for (int i = 0; i < memLen; i++) {
            pMem[i] = 0;
        }
    }

}
TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    bitLen = bf.bitLen;
    memLen = bf.memLen;
    pMem = new elem_type[memLen];
    for (int i = 0; i < memLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}
//TBitField::TBitField(TBitField&& bf) noexcept :bitLen(0), memLen(0),
//shiftSize(0), bitsInElem(0), pMem(nullptr) // move-конструктор (перемещение содержимого bf в this)
//{
//    bitLen = bf.bitLen;
//    bitsInElem = bf.bitsInElem;
//    memLen = bf.memLen;
//    pMem = bf.pMem;
//    shiftSize = bf.shiftSize;
//    bf.pMem = nullptr;
//    bf.bitLen = 0;
//    bf.bitsInElem = 0;
//    bf.memLen = 0;
//    bf.shiftSize = 0;
//}

TBitField::~TBitField()   // деструктор
{
    delete[] pMem;
}

TBitField& TBitField::operator=(const TBitField& bf)
{
    bitLen = bf.bitLen;
    memLen = bf.memLen;
    delete[] pMem;
    pMem = new elem_type[memLen];
    for (auto i = 0; i < memLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

bool TBitField::operator==(const TBitField& bf) const noexcept
{
    if (bitLen != bf.bitLen) { return 0; }
    else {
        for (auto i = 0; i < memLen; i++) {
            if (pMem[i] == bf.pMem[i]) { return 0; }
        }
    }
    return 1;
}

bool TBitField::operator!=(const TBitField& bf) const noexcept
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf)
{
    size_t BitLen = bitLen;
    if (bf.bitLen > BitLen) { BitLen = bf.bitLen; }
    TBitField tb(bitLen);
    for (auto i = 0; i < memLen; i++) {
        tb.pMem[i] = pMem[i] | bf.pMem[i];
    }
    return tb;
}

TBitField TBitField::operator&(const TBitField& bf)
{
    size_t BitLen = bitLen;
    if (bf.bitLen > BitLen) { BitLen = bf.bitLen; }
    TBitField tb(bitLen);
    for (auto i = 0; i < memLen; i++) {
        tb.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return tb;
}

bool TBitField::test(size_t i) const
{
    if (i < 0 || i >= bitLen) { throw std::length_error("Out of range"); }
    else { return pMem[GetMemIndex(i)] & GetMemMask(i); }
}

void TBitField::set(size_t i)
{
    if (i < 0 || i >= bitLen) { throw std::length_error("Out of range"); }
    else { pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)] | GetMemMask(i); }
}

TBitField TBitField::operator~(void)
{
    TBitField bt(*this);
    for (int i = 0; i < bitLen; i++) {
        if (bt.test(i)) { bt.reset(i); }
        else { bt.set(i); }
    }
    return bt;
}

void TBitField::reset(size_t i)
{
    if (i < 0 || i >= bitLen) { throw std::length_error("Out of range"); }
    else { pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)] & (~GetMemMask(i)); }
}

void swap(TBitField& lhs, TBitField& rhs) noexcept
{
    std::swap(lhs, rhs);
}

std::ostream& operator<<(std::ostream& ostr, const TBitField& bf)
{
    for (int i = 0; i < bf.size(); ++i)
    {
        ostr << bf.test(i) << " ";
    }
    ostr << "\n";
    return ostr;
}

std::istream& operator>>(std::istream& istr, TBitField& bf) {
    for (int i = 0; i < bf.size(); ++i)
    {
        int in;
        istr >> in;
        if (in) bf.set(i);
    }
    return istr;
}

size_t TBitField::size() const noexcept
{
    return bitLen;
}

std::string TBitField::to_string()
{
    std::string tmp;
    for (int i = 0; i < bitLen; i++) {
        if (test(i) == 1) { tmp = tmp + "1"; }
        else { tmp = tmp + "0"; }
    }
    return tmp;
}