#ifndef _STOPWATCH_HPP_
#define _STOPWATCH_HPP_

#include <ctime>
#include <iostream>

class Stopwatch
{
public:
	Stopwatch();

	int getElapsedHours() const;
	int getElapsedMinutes() const;
	int getElapsedSeconds() const;

	bool isPaused() const; // На паузе?
	void resume(); // Вывести из режима паузы!
	void reset(); // Остановить и обнулить!
	void pause(); // Поставить на паузу

	clock_t getElapsed() const; // Текущее количество времени

	void display(std::ostream &) const;

	Stopwatch operator+(clock_t s) const;
	Stopwatch& operator+=(clock_t s);
	Stopwatch operator-(clock_t s) const;
	Stopwatch& operator-=(clock_t s);

private:

	bool paused;
	clock_t startTime; // время последнего запуска
	clock_t elapsedTime; // Накопленное время
};

inline int Stopwatch::getElapsedHours() const
{
	return (getElapsed() / CLOCKS_PER_SEC) / 3600;
}

inline int Stopwatch::getElapsedMinutes() const
{
	return (getElapsed() / CLOCKS_PER_SEC - getElapsedHours() * 3600) / 60;
}

inline int Stopwatch::getElapsedSeconds() const
{
	return (getElapsed() / CLOCKS_PER_SEC) % 60;
}


#endif //  _STOPWATCH_HPP_
