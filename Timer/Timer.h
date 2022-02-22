#pragma once
#include<chrono>
class Timer {
public:
	static double last_duration;
	static void start();
	static double stop();

private:
	static std::chrono::steady_clock::time_point _t1;
	static std::chrono::steady_clock::time_point _t2;

};//一个简易计时类

inline void Timer::start() {
	_t1 = std::chrono::steady_clock::now();
}

inline double Timer::stop() {
	_t2 = std::chrono::steady_clock::now();
	last_duration = std::chrono::duration_cast<std::chrono::duration<double>>(_t2 - _t1).count();
	return last_duration;
}
