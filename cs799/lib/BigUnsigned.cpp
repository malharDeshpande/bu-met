#include "BigUnsigned.h" // class implemented

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace tgl;

static const size_t N = 8 * sizeof(unsigned long);


BigUnsigned::BigUnsigned()
{
}// BigUnsigned

BigUnsigned::BigUnsigned(unsigned long n)
{
  _value.push_back(n);
}// BigUnsigned

BigUnsigned::BigUnsigned(const BigUnsigned &x)
{
  if (x.isZero()) {
    return;
  }

  _value.resize(x.length());

  for (size_t loop = 0; loop < x.length(); ++loop) {
    this->_value[loop] = x._value[loop];
  }
}// BigUnsigned

BigUnsigned::BigUnsigned(const std::string &str)
{
  size_t stop = 0;
  if (str[0] == '-') {
    stop = 1;
  }

  std::vector<unsigned long> d;

  for (size_t loop = str.size();
       loop > stop;
       --loop) {
    d.push_back(str[loop - 1] - '0');
  }


  BigUnsigned ans(0);
  BigUnsigned base(10);
  BigUnsigned temp;

  size_t len = d.size();
  for (size_t loop = 0;
       loop < d.size();
       ++loop) {
    temp.multiply(ans, base);
    ans.add(temp, BigUnsigned(d[len - 1 - loop]));
  }

  *this = ans;
}// BigUnsigned

void
BigUnsigned::zapLeadingZeros()
{
  while (_value.size() > 0 && _value.back() == 0) {
    _value.pop_back();
  }
}// zapLeadingZeros

bool
BigUnsigned::isZero() const
{
  if (_value.empty()) {
    return true;
  } else if (_value.size() == 1 && _value[0] == 0) {
    return true;
  }

  return false;
}// isZero

void
BigUnsigned::operator=(const BigUnsigned &x)
{
  if (this == &x) {
    return;
  }

  _value.resize(x.length());

  for (size_t loop = 0; loop < x.length(); ++loop) {
    this->_value[loop] = x._value[loop];
  }
}// operator=

BigUnsigned::Comparison
BigUnsigned::compareTo(const BigUnsigned &x) const
{
  if (this->length() < x.length()) {
    return less;
  } else if (this->length() > x.length()) {
    return greater;
  } else {
    size_t index = this->length();
    while (index > 0) {
      index--;
      if (this->value(index) == x.value(index)) {
	continue;
      } else if (this->value(index) > x.value(index)) {
	return greater;
      } else {
	return less;
      }
    }
    return equal;
  }
}// compareTo

bool
BigUnsigned::operator==(const BigUnsigned &x) const
{
  if (this->length() != x.length()) {
    return false;
  } else {
    for (size_t loop = 0; loop < this->length(); ++loop) {
      if (this->_value[loop] != x._value[loop]) {
	return false;
      }
    }
  }
  return true;
}// operator==

#define ALIASED(cond, op) \
  if (cond) { \
    BigUnsigned tmp; \
    tmp.op; \
    *this = tmp; \
    return; \
  }

void
BigUnsigned::add(const BigUnsigned &a, const BigUnsigned &b)
{
  ALIASED(this == &a || this == &b, add(a, b));

  if (a.length() == 0) {
    operator =(b);
    return;
  } else if (b.length() == 0) {
    operator =(a);
    return;
  }

  const BigUnsigned *a2;
  const BigUnsigned *b2;

  if (a.length() >= b.length()) {
    a2 = &a;
    b2 = &b;
  } else {
    a2 = &b;
    b2 = &a;
  }

  unsigned long temp;
  bool carry_in;
  bool carry_out;
  size_t loop;

  _value.resize(a2->length() + 1);

  for (loop = 0, carry_in = false; loop < b2->length(); ++loop) {
    temp = a2->value(loop) + b2->value(loop);
    carry_out = (temp < a2->value(loop));
    if (carry_in) {
      temp++;
      carry_out |= (temp == 0);
    }

    _value[loop] = temp;
    carry_in = carry_out;
  }

  for (; loop < a2->length() && carry_in; ++loop) {
    temp = a2->value(loop) + 1;
    carry_in = (temp == 0);
    _value[loop] = temp;
  }

  for (; loop < a2->length(); ++loop) {
    _value[loop] = a2->value(loop);
  }
  
  if (carry_in) {
    _value[loop] = 1;
  } else {
    _value.pop_back();
  }
}// add


void
BigUnsigned::subtract(const BigUnsigned &a, const BigUnsigned &b)
{
  ALIASED(this == &a || this == &b, subtract(a, b));

  if (a.length() == 0) {
    operator =(b);
    return;
  } else if (b.length() == 0) {
    operator =(a);
    return;
  }

  const BigUnsigned *a2;
  const BigUnsigned *b2;

  if (a.length() >= b.length()) {
    a2 = &a;
    b2 = &b;
  } else {
    a2 = &b;
    b2 = &a;
  }

  unsigned long temp;
  bool carry_in;
  bool carry_out;
  size_t loop;

  _value.resize(a2->length() + 1);

  for (loop = 0, carry_in = false; loop < b2->length(); ++loop) {
    temp = a2->value(loop) - b2->value(loop);
    carry_out = (temp > a2->value(loop));
    if (carry_in) {
      temp--;
      carry_out |= (temp == 0);
    }

    _value[loop] = temp;
    carry_in = carry_out;
  }

  for (; loop < a2->length() && carry_in; ++loop) {
    temp = a2->value(loop) - 1;
    carry_in = (temp == 0);
    _value[loop] = temp;
  }

  for (; loop < a2->length(); ++loop) {
    _value[loop] = a2->value(loop);
  }
  
  if (carry_in) {
    _value[loop] = 1;
  } else {
    _value.pop_back();
  }
}// subtract

inline unsigned long
get_shifted_block(const BigUnsigned &b, size_t x, unsigned int y)
{
  unsigned long part1 = (x == 0 || y == 0) ? 0 : (b.value(x -  1) >> (N - y));
  unsigned long part2 = (x == b.length()) ? 0 : (b.value(x) <<  y);

  return part1 | part2;
}// get_shifted_block

void
BigUnsigned::multiply(const BigUnsigned &a, const BigUnsigned &b)
{
  ALIASED(this == &a || this == &b, multiply(a, b));

  if (a.length() == 0 || b.length() == 0) {
    _value.clear();
    return;
  }

  unsigned long temp;
  size_t ii, jj, kk;
  unsigned int i2;
  bool carry_in;
  bool carry_out;

  _value.resize(a.length() + b.length());

  for (size_t loop = 0; loop < _value.size(); ++loop) {
    _value[loop] = 0;
  }
  
  unsigned long shift_this = 1L;

  for (ii = 0; ii < a.length(); ++ii) {
    for (i2 = 0; i2 < N; ++i2) {
      if ((a.value(ii) & ((unsigned long)(1) << i2)) == 0) {
	continue;
      }
	
      for (jj = 0, kk = ii, carry_in = false; jj <= b.length(); ++jj, ++kk) {
	temp = _value[kk] + get_shifted_block(b, jj, i2);
	carry_out = (temp < _value[kk]);

	if (carry_in) {
	  temp++;
	  carry_out |= (temp == 0);
	}
	_value[kk] = temp;
	carry_in = carry_out;
      }
       
      for (; carry_in; ++kk) {
	_value[kk]++;
	carry_in = (_value[kk] == 0);
      }
    }
  }
  
  if (_value.back() == 0) {
    _value.pop_back();
  }
}// multiply

void
BigUnsigned::modWithQuotient(const BigUnsigned& b, BigUnsigned &q)
{
  if (this == &q) {
    throw("BigUnsigned::modWithQuotient: Cannot write quotient and remainder into same variable.");
  }

  if (this == &b || &q == &b) {
    BigUnsigned tmp(b);
    modWithQuotient(tmp, q);
    return;
  }

  if (b.length() == 0) {
    q.zero();
    return;
  }

  if (_value.size() < b.length()) {
    q.zero();
    return;
  }

  size_t ii, jj, kk;
  unsigned int i2;
  unsigned long temp;
  bool borrow_in, borrow_out;

  size_t origLen = _value.size();
  _value.push_back(0);

  std::vector<unsigned long> buf(_value.size());

  q._value.resize(origLen - b.length() + 1);
  for (size_t loop = 0; loop < q.length(); ++loop) {
    q._value[loop] = 0;
  }

  ii = q.length();

  while (ii > 0) {
    ii--;

    q._value[ii] = 0;
    i2 = N;

    while (i2 > 0) {
      i2--;

      for (jj = 0, kk = ii, borrow_in = false;
           jj <= b.length();
           jj++, kk++) {
	temp = _value[kk] - get_shifted_block(b, jj, i2);
	borrow_out = (temp > _value[kk]);
	if (borrow_in) {
	  borrow_out |= (temp == 0);
	  temp--;
	}
	buf[kk] = temp;
	borrow_in = borrow_out;
      }

      for (; kk < origLen && borrow_in; kk++) {
	borrow_in = (_value[kk] == 0);
	buf[kk] = _value[kk] - 1;
      }

      if (!borrow_in) {
	q._value[ii] |= ((unsigned long)(1) << i2);
	while (kk > ii) {
	  kk--;
	  _value[kk] = buf[kk];
	}
      }
    }
  }

  if (q._value[q.length() - 1] == 0) {
    q._value.pop_back();
  }

  zapLeadingZeros();
}// modWithQuotient

void
BigUnsigned::operator++()
{
  size_t loop;
  bool carry = true;
  for (loop = 0; loop < length() && carry; ++loop) {
    _value[loop]++;
    carry = (_value[loop] == 0);
  }

  if (carry) {
    _value.push_back(1);
  }
}// operator++

void
BigUnsigned::operator++(int)
{
  operator++();
}// operator++

void
BigUnsigned::operator--()
{
  if (_value.size() == 0) {
    throw "BigUnsigned::operator--(): Cannot decrement an unsigned zero.";
  }

  size_t loop;
  bool borrow = true;
  for (loop = 0; borrow; ++loop) {
    borrow = (_value[loop] == 0);
    _value[loop]--;
  }

  if (_value.back() == 0) {
    _value.pop_back();
  }
}// operator--

void
BigUnsigned::operator--(int)
{
  operator--();
}// operator--

std::string
tgl::convert2str(const BigUnsigned &x)
{
  if (x.isZero()) {
    return std::string("0");
  }

  std::stringstream result;
  BigUnsigned ten(10);
  BigUnsigned r(x);

  while (!r.isZero()) {
    BigUnsigned last(r);
    last.modWithQuotient(ten, r);
    if (last.length() > 0) {
      result << last.value(0);
    } else {
      result << "0";
    }
  }

  std::string to_reverse(result.str());

  std::reverse(to_reverse.begin(), to_reverse.end());

  return to_reverse;
}// convert2str

