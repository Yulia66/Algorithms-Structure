#include <iostream>   
#include <vector>
#include <windows.h>
#include <cmath>
#include <list>
#include "../lib_List/List.h"
#include <algorithm>

bool is_number(char symbol) {
  return symbol >= '0' && symbol <= '9';
}
class Monom {
public:
  std::string _name;
  float _coef;
  int d_x, d_y, d_z;

  int get_coef() {
    return _coef;
  }
  int get_d_x() {
    return d_x;
  }
  int get_d_y() {
    return d_y;
  }
  int get_d_z() {
    return d_z;
  }

  //size_t index;
  Monom() {
    _coef = 0;
    d_x = 0;
    d_y = 0;
    d_z = 0;
  }
  Monom(const Monom& monom) {
    _coef = monom._coef;
    d_x = monom.d_x;
    d_y = monom.d_y;
    d_z = monom.d_z;
  }
  Monom(std::string exp) {
    _coef = 0;
    d_x = 0;
    d_y = 0;
    d_z = 0;
    int curr_pos = 0;
    int result_coef = 0;
    int result_dx = 0;
    int result_dy = 0;
    int result_dz = 0;
    
    while (is_number(exp[curr_pos])) {
      result_coef = result_coef * 10 + (exp[curr_pos] - '0');
      curr_pos++;
      _coef = result_coef;
    }
    if (exp[curr_pos] == 'x') {
      curr_pos= curr_pos +2;
      while (is_number(exp[curr_pos])) {
        result_dx = result_dx * 10 + (exp[curr_pos] - '0');
        curr_pos++;
      }
      d_x = result_dx;
    }
    if (exp[curr_pos] == 'y') {
      curr_pos = curr_pos +2;
      while (is_number(exp[curr_pos])) {
        result_dy = result_dy * 10 + (exp[curr_pos] - '0');
        curr_pos++;
      }
      d_y = result_dy;
    }
    if (exp[curr_pos] == 'z') {
      curr_pos = curr_pos +2;
      while (is_number(exp[curr_pos])) {
        result_dz = result_dz * 10 + (exp[curr_pos] - '0');
        curr_pos++;
      }
      d_z = result_dz;
    }
  }
  Monom(float coef, int x, int y, int z) {
    _coef = coef;
    d_x = x;
    d_y = y;
    d_z = z;
  }
  void print() {
    if (_coef != 0) {
      std::cout << _coef << " ";
    }
    if (d_x != 0) {
      std::cout << "* x^" << d_x << " ";
    }
    if (d_y != 0) {
      std::cout << "* y^" << d_y << " ";
    }
    if (d_z != 0) {
      std::cout << "* z^" << d_z << " ";
    }
  }
  bool operator==(const Monom& monom) {
    return(
      d_x == monom.d_x &&
      d_y == monom.d_y &&
      d_z == monom.d_z
      );
  }
  bool operator!=(Monom& monom) {
    return!(*this == monom);
  }
  Monom& operator=(const Monom& monom) {
    _coef = monom._coef;
    d_x = monom.d_x;
    d_y = monom.d_y;
    d_z = monom.d_z;
    return *this;
  }
  Monom operator+(Monom& monom) {
    if (*this == monom) {
      return Monom(_coef + monom._coef, d_x, d_y, d_z);
    }
    throw "Не подобны! ";
  }

  Monom operator-() {
    _coef = (-1) * _coef;
  
      return *this;
  
  }
  Monom& operator+=(const Monom& monom) {
    if (*this == monom) {
      _coef = _coef + monom._coef;
     
       return *this;
    }
    throw "Не подобны! ";
  }
  Monom operator-(Monom& monom) {
    if (*this == monom) {
      return Monom(_coef - monom._coef, d_x, d_y, d_z);
    }
    throw "Не подобны! ";
  }
  Monom operator*(Monom& monom) {
    return Monom(_coef * monom._coef, d_x + monom.d_x, d_y + monom.d_y, d_z + monom.d_z);
  }
  Monom operator/(const Monom& monom) {
    Monom res;
    if (d_x == 0) {
      res.d_x = monom.d_x;
    }
    else {
      res.d_x = d_x - monom.d_x;
    }
    if (d_y == 0) {
      res.d_y = monom.d_y;
    }
    else {
      res.d_y = d_y - monom.d_y;
    }
    if (d_z == 0) {
      res.d_z = monom.d_z;
    }
    else {
      res.d_z = d_z - monom.d_z;
    }
    return Monom(_coef / monom._coef, res.d_x, res.d_y, res.d_z);
  }
  friend std::ostream& operator<<(std::ostream& out, const Monom& monom);
};
std::ostream& operator<<(std::ostream& out, const Monom& monom) {
  if (monom._coef != 0) {
    out << monom._coef;
  }
  if (monom.d_x != 0) {
    out << "*x^" << monom.d_x;
  }
  if (monom.d_y != 0) {
    out << "*y^" << monom.d_y;
  }
  if (monom.d_z != 0) {
    out << "*z^" << monom.d_z;
  }
  return out;
}

class Polynom {
  std::list<Monom> _polynom;
 
public:
  Polynom(std::string exp) {
    parse(exp);
  }
  void parse(std::string exp) {

    int curr_pos = 0;
    while (curr_pos < exp.length()) {
      int start_pos = curr_pos;

      while ((exp[curr_pos] != '+') && (curr_pos < exp.length())) {
        curr_pos++;
      }
      
      Monom new_monom(exp.substr(start_pos, curr_pos - start_pos));
      
      _polynom.push_back(new_monom);
      curr_pos++;
    }
  }
    void print() {
      for (auto it = _polynom.begin(); it != _polynom.end(); ++it) {
       it->print();
        if (std::next(it) != _polynom.end()) {
          std::cout << " + ";
        }
      }
      std::cout << std::endl; 
    }  

    static bool compareMonom(const Monom& a, const Monom& b) {
        if (a.d_x != b.d_x) return a.d_x > b.d_x;
        if (a.d_y != b.d_y) return a.d_y > b.d_y;
        if (a.d_z != b.d_z) return a.d_z > b.d_z;
        if (a._coef != b._coef) return a._coef > b._coef;
       
    }

public:
    void sort() {
        std::vector<Monom> polynom(_polynom.begin(), _polynom.end());
        _polynom.clear();

        std::sort(polynom.begin(), polynom.end(), compareMonom);

        for (const auto& monom : polynom) {
            _polynom.push_back(monom);
        }
    }
    


    void add_monom(Monom& monom) {
      _polynom.push_back(monom);
    }
};
