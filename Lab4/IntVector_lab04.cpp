#include <iostream>
#include <cassert>
#include <cstring>
#include "IntVector_lab04.h"

using namespace std;

//РЕЗУЛЬТАТ:  Конструктор по умолчанию.  Создает пустой IntVector.
IntVector::IntVector()
  : numElements(0) {}

//ТРЕБОВАНИЕ: IntVector не переполнен
//ИЗМЕНЕНИЯ:  IntVector
//РЕЗУЛЬТАТ:  Добавляет элемент в конец IntVector.
void IntVector::push_back(int value){
  assert(numElements<=CAPACITY);
  data[numElements]=value;
  numElements++;
}

//ТРЕБОВАНИЕ: IntVector не пустой
//ИЗМЕНЕНИЯ:  IntVector
//РЕЗУЛЬТАТ:  Удаляет последний элемент из IntVector.
void IntVector::pop_back(){
  assert(numElements>=0);
  data[numElements]=0;
  numElements--;
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
int &IntVector::at(int index) {
  assert(index>=0&&index<=numElements); 
 return data[index];
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
const int &IntVector::at(int index) const {
   assert(index>=0&&index<=numElements); 
 return data[index];
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
int &IntVector::operator[](int index) {
 assert(index>=0&&index<=numElements); 
 return data[index];
}

//ТРЕБОВАНИЕ: 0 <= index < количества элементов IntVector
//РЕЗУЛЬТАТ:  Возвращает (по ссылке) элемент с заданным индексом.
const int &IntVector::operator[](int index) const {
  assert(index>=0&&index<=numElements); 
 return data[index];
}

//РЕЗУЛЬТАТ:  Возвращает количества элементов IntVector.
int IntVector::size() const{
  return numElements;
}

//РЕЗУЛЬТАТ: Возвращает true если IntVector пустой, false в противном случае.
bool IntVector::empty() const{
  if(numElements==0)
  return true; 
  else return false; 
}

//РЕЗУЛЬТАТ: Возвращает true если IntVector заполнен, false в противном случае.
//          Добавить элемент можно только в случае когда full() возвращает false.
bool IntVector::full() const{
  if(numElements==CAPACITY)
  return true;
  else return false;
}

//РЕЗУЛЬТАТ: Выводит все элементы IntVector
//          в следующем формате:
//          [ elem0, elem1, elem2, ... ]
void IntVector::print(ostream &os) const{
  os << "[ ";
  const int *ptr = data;
  for(const int *end = data + (numElements-1); ptr < end; ++ptr){
    os << *ptr << ", ";
  }
  if (numElements != 0){
    os << *ptr << " ";
  }
  os << "]";
}

//РЕЗУЛЬТАТ: Возвращает true в случае если инвариант представления выполняется.
//           Для IntVector только один инвариант представления 0 <= numElements <= CAPACITY.
bool IntVector::check_invariant() const{
  if(numElements>=0&&numElements<=CAPACITY)
  return true;
  else return false; 
}

int IntVector::get_numElements(){
	  return numElements;
	  }
int* IntVector::get_data(){
	  return data;
	  }
 
//РЕЗУЛЬТАТ: Выводит все элементы IntVector
//          в следующем формате:
//          [ elem0, elem1, elem2, ... ]
ostream &operator<<(ostream & os,IntVector &v) {
  os << "[ ";
  int *ptr = v.get_data();
  for(const int *end = v.get_data()+ (v.get_numElements()-1); ptr < end; ++ptr){
    os << *ptr << ", ";
  }
  if (v.get_numElements() != 0){
    os << *ptr << " ";
  }
  os << "]";

  return os; 
}
