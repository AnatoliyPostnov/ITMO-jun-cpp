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
private:
    int hunger_;
    int active_;


public:

    /**
     * @brief Critter
     * Вывод приветствие
     */
    void Hello(){
		cout << "Здравствуйте! Меня зовут Слон и я хочу Играть" << endl;
		} 
    Critter(){
		hunger_=0;
		active_=10;
		}
    Critter(int hunger);

    /**
     * @brief getHungerLevel функция возвращает текущий уровень
     * оголодалости животного
     * @return уровень голода
     */
    int getHungerLevel(){
		return hunger_;
		}
    /**
     * @brief passTime функция эмуляция прошедшего времени
     * При вызове увеличивает уровень голода,
     * если уровень голода превысил допустимый порог,
     * то живность умирает
     */
    void passTime(){
		hunger_++;
		if(hunger_>10){
			cout << "Вы совсем про меня забыли, поэтому я сдох!";
			}
		}

    /**
     * @brief getActiveLevel функция возвращает уровень
     * питомца к активности, при низком уровене хочется спать
     * ZZZZZZZZZZZzzzzzzzzzzzz.....
     * @return
     */
    int getActiveLevel(){
		return active_;
		}

    /**
     * @brief sleep
     * Повышает уровень активности
     */
   void Print(){
	    cout << "\nЕсли хочешь поиграть со мной нажми 1\n";
		cout << "Если хочешь отправить меня спать нажми 2\n";
		cout << "Если хочешь покормить, нажми 3\n";
	   }
    int sleep(){
		if(active_<10)
		active_++;
		passTime();
		if(hunger_>7){
			cout << "Все! Хватит стать, пора идти есть иначе сдохну!\n";
			Print();
			if(hunger_>10){
				passTime();
				return 0;
				}
			}
		cout << "ZZZZZZZZZZZzzzzzzzzzzzz.....\n";
		cout << "Моя активность стала " << active_ << "%\n";
		cout << "Уровень моей оголодалости " << hunger_ << "%";
		Print();
		}

    /**
     * @brief feed
     * Понижает уровень голода
     */
    void feed(){
		if(hunger_>0){
			hunger_--;
			cout << ("немного подкормился, круто!\n");
			cout << "Уровень моей оголодалости " << hunger_ << "%\n";
			cout << "Текущая моя активность " << active_ << "%\n";
			}
		if(hunger_== 0) {
			cout << "Я сыт полностью, спасибо!";
			cout << "Уровень моей оголодалости " << hunger_ << "%\n";
			cout << "Текущая моя активность " << active_ << "%\n";
			}
		}

    /**
     * @brief play
     * Понижает уровень активности, утомляет
     */
    int play(){
		int c;
		active_--;
		passTime();
		if(hunger_>7){
			cout << "Чувак, я вообще-то жрать хочу, покорми меня иначе сдохну!\n";
			Print();
			if(hunger_>10){
				passTime();
				return 0;
				}
			}
		if(hunger_<=7){
			cout << "Круто поиграли, теперь моя активность стала " << active_ << "%\n";
			cout << "Уровень моей оголодалости " << hunger_ << "%";		
			Print();
			}
			else return 1;
			
		}
	};



int main(void){
	Critter Slon;
	Slon.Hello();
	int c,i=1;
	while(1){
		cout << "Мой текщий уровень оголодалости:" <<  Slon.getHungerLevel() << endl;
		cout << "Мой текщий уровень бодрствования:" <<  Slon.getActiveLevel() << endl;
		Slon.Print();		
		while(i){
			cin >> c;	
			switch(c){
				case 1: i=Slon.play(); break;
				case 2: i=Slon.sleep(); break;
				case 3: Slon.feed(); break;
				default:cout << "\nВы не хотите со мной ничего делать, поэтому до встречи! Пока!\n";
						return 0;
				}			
			}
		break;	
	}
	return 0;
}

#endif
