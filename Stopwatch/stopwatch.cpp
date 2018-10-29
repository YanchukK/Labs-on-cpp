#include "stopwatch.hpp"
#include <stdexcept>


Stopwatch::Stopwatch() // Конструктор
{
	startTime = 0;
	elapsedTime = 0;
	paused = true;
}

bool Stopwatch::isPaused() const // На паузе?
{
	return paused;
}

void Stopwatch::resume()  // Вывести из режима паузы!
{
	if (!paused)
		throw std::logic_error("Stopwatch is not paused");
	paused = false;
	startTime = clock();
}

void Stopwatch::pause() // Поставить на паузу
{
	if (paused)
		throw std::logic_error("Stopwatch is paused already");
	paused = true;
	elapsedTime += clock() - startTime;
	startTime = 0;
}

void Stopwatch::reset() // Остановить и обнулить!
{
	paused = true;
	elapsedTime = 0;
}

clock_t Stopwatch::getElapsed() const // Текущее количество времени
{
	if (!paused)
		return elapsedTime + (clock() - startTime);
	else
		return elapsedTime;
}

Stopwatch& Stopwatch::operator+=(clock_t s)
{
	elapsedTime += s;
	return *this;
}

Stopwatch Stopwatch::operator+(clock_t s) const
{
	return Stopwatch(*this) += s;
}

Stopwatch& Stopwatch::operator-=(clock_t s)
{
	elapsedTime -= s;
	return *this;
}

Stopwatch Stopwatch::operator-(clock_t s) const
{
	return Stopwatch(*this) -= s;
}

void Stopwatch::display(std::ostream & cout) const
{
	cout << getElapsedHours() << ':' << getElapsedMinutes() << ':' << getElapsedSeconds();
}
