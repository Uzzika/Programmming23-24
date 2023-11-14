#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include <iostream>
#include "../bitField/bit_field.h"

class TSet {
private:
    size_t maxPower;                       // ������������ �������� ���������
    TBitField bitField;                    // ������� ���� ��� �������� ���������
public:
    TSet(int mp) :bitField(mp), maxPower(mp) {}
    TSet(const TSet& s) :bitField(s.bitField), maxPower(s.maxPower) {}
    TSet(const TBitField& bf) :bitField(bf), maxPower(bf.size()) {}


    operator TBitField(); // �������������� ���� � �������� ����

    size_t GetMaxPower() const noexcept;

    void InsElem(size_t Elem);            // �������� ������� � ���������
    void DelElem(size_t Elem);            // ������� ������� �� ���������
    bool IsMember(size_t Elem) const;     // ��������� ������� �������� � ���������

    TSet operator+ (const int Elem);       // ����������� � ���������
    TSet operator- (const int Elem);       // �������� � ���������
    TSet operator+ (const TSet& s);        // �����������
    TSet operator* (const TSet& s);        // �����������
    TSet operator~ ();                     // ����������

    int operator== (const TSet& s) const;
    int operator!= (const TSet& s) const;
    TSet& operator=(const TSet& s);

    friend std::istream& operator>>(std::istream& in, TSet& bf);
    friend std::ostream& operator<<(std::ostream& out, const TSet& bf);
};

#endif  // INCLUDE_SET_H_

TSet::operator TBitField() { return bitField; }

size_t TSet::GetMaxPower() const noexcept { return maxPower; }

void TSet::InsElem(size_t Elem)
{
    if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
    else { return bitField.set(Elem); }
}

void TSet::DelElem(size_t Elem)
{
    if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
    else { return bitField.reset(Elem); }
}

bool TSet::IsMember(size_t Elem) const
{
    if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
    else { return bitField.test(Elem); }
}

TSet TSet:: operator+(const int Elem)
{
    if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
    else {
        TSet ts(bitField);
        ts.InsElem(Elem);
        return ts;
    }
}

TSet TSet:: operator-(const int Elem)
{
    if (Elem < 0 || Elem >= maxPower) { throw std::logic_error("Out of range."); }
    else {
        TSet ts(bitField);
        ts.DelElem(Elem);
        return ts;
    }
}

TSet TSet:: operator+(const TSet& s)
{
    int maxP;
    if (maxPower > s.maxPower) { maxP = maxPower; }
    else { maxP = s.maxPower; }
    TSet ts(maxP);
    ts.bitField = bitField | s.bitField;
    return ts;
}

TSet TSet:: operator*(const TSet& s)
{
    int maxP;
    if (maxPower > s.maxPower) { maxP = maxPower; }
    else { maxP = s.maxPower; }
    TSet ts(maxP);
    ts.bitField = bitField & s.bitField;
    return ts;
}

TSet TSet::operator~() { return TSet(~bitField); }

int TSet::operator==(const TSet& s) const { return (bitField == s.bitField); }

int TSet::operator!=(const TSet& s) const { return !(*this == s); }

TSet& TSet::operator=(const TSet& s)
{
    maxPower = s.maxPower;
    bitField = s.bitField;
    return *this;
}

std::istream& operator>>(std::istream& istr, TSet& s) {
    const int mp = s.maxPower;
    for (int i = 0; i < mp; ++i) {
        int val;
        istr >> val;
        s.InsElem(val);
    }
    return istr;
}

std::ostream& operator<<(std::ostream& ostr, const TSet& s) {
    const int mp = s.maxPower;
    for (int i = 0; i < mp; ++i) {
        ostr << s.IsMember(i) << " ";
    }
    return ostr;
}