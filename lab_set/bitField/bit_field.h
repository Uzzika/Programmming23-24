#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_

#include <iostream>

using elem_type = unsigned int;

class TBitField {
private:
    size_t bitLen;                      // длина битового поля (максимальное допустимое значение эл-та мн-ва, мощность универса)
    size_t memLen;                      // кол-во элементов, необходимое для хранения битового поля
    elem_type* pMem;                    // память для представления битового поля

    // служебные поля (не обязательны)
    size_t bitsInElem;
    size_t shiftSize;

    // служебные методы

    // индекс в pМем для бита pos
    size_t GetMemIndex(size_t pos) const noexcept;

    // битовая маска для бита pos
    elem_type GetMemMask(size_t pos) const noexcept;

public:
    // обязательный функционал
    TBitField(size_t _BitLen);                             // конструктор специального вида
    TBitField(const TBitField& bf);                        // конструктор копирования
    //TBitField(TBitField&& bf) noexcept;                    // move-конструктор (перемещение содержимого bf в this)
    ~TBitField();                                          // деструктор

    TBitField& operator=(const TBitField& bf);
    //TBitField& operator=(TBitField&& bf) noexcept;
    bool operator==(const TBitField& bf) const noexcept;
    bool operator!=(const TBitField& bf) const noexcept;

    bool test(size_t i) const;                             // получить значение бита i
    void set(size_t i);                                    // установить бит i
    void reset(size_t i);                                  // очистить бит i

    TBitField  operator|(const TBitField& bf);             // или
    TBitField  operator&(const TBitField& bf);             // и
    TBitField  operator~(void);                            // отрицание

    // получить длину (к-во битов)
    size_t size() const noexcept;

    friend void swap(TBitField& lhs, TBitField& rhs) noexcept;

    // ввод/вывод
    friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf);
    std::string to_string();
};

#endif  // INCLUDE_BITFIELD_H_