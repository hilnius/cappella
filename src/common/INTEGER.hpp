/*
The MIT License (MIT)

Copyright (c) 2015 Robin Nicollet

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <sstream>

template<int N>
class INTEGER
{
  public:
    INTEGER(int value = 0) { p_value = value; }
    virtual ~INTEGER() { }

    bool operator==(const INTEGER& other) { return other.p_value == p_value; }

    int toInt() const { return p_value; }

  private:
    int p_value;
};

template<int N>
int& operator+=(int& container, const INTEGER<N>& value)
{
    container += value.toInt();
    return container;
}
template<int N>
std::ostream& operator<<(std::ostream& os, const INTEGER<N>& value)
{
    os << value.toInt();
    return os;
}

#endif // INTEGER_H_INCLUDED
