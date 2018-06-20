#ifndef CRITTER_H_
#define CRITTER_H_
#include <iostream>
using namespace std;

/**
 * Задания:
 * 1. Реализовать меню для взаимодействия с тамагочи (выбор действия в main)
 * 2. Реализовать описанные функции
 * 3. Добавить статическую переменную для хранения количества созданных сущностей
 * 4. Добавить функцию выводящую информацию о текущем уровне голода и активности
 * 5. Добавить в функцию passTime предупреждения если уровень голода или активности критичные
 * 6. Создать перегруженные функции feed и play, которые будут принимать один аргумент типа int,
 * т.е.  void feed(int amount) и изменять уровень голода/активности ровно на значение аргумента
 */
class Critter
{
public:
	int hanger;
    /**
     * @brief Critter
     * Вывод приветствие
     */
    void Hello(){
		cout << "Здравствуйте! Меня зовут Слон и я хочу есть! Покорми меня!" << endl;
		} 
    Critter(){
		hanger=0;
		}
    Critter(int hunger);
    //~Critter();

    /**
     * @brief getHungerLevel функция возвращает текущий уровень
     * оголодалости животного
     * @return уровень голода
     */
    int getHungerLevel(){
		return 0;
		}
    /**
     * @brief passTime функция эмуляция прошедшего времени
     * При вызове увеличивает уровень голода,
     * если уровень голода превысил допустимый порог,
     * то живность умирает
     */
    void passTime();

    /**
     * @brief getActiveLevel функция возвращает уровень
     * питомца к активности, при низком уровене хочется спать
     * ZZZZZZZZZZZzzzzzzzzzzzz.....
     * @return
     */
    int getActiveLevel();

    /**
     * @brief sleep
     * Повышает уровень активности
     */
    void sleep();

    /**
     * @brief feed
     * Понижает уровень голода
     */
    void feed();

    /**
     * @brief play
     * Понижает уровень активности, утомляет
     */
    void play();

private:
    int hunger_;
    int active_;
};

int main(void){
	Critter Slon;
	Slon.Hello();
	
	return 0;
	}

#endif
