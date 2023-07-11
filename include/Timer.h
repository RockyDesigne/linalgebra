//
// Created by HORIA on 15.03.2023.
//

#ifndef LINALGEBRA_TIMER_H
#define LINALGEBRA_TIMER_H

#include <chrono>

class Timer {
private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg {Clock::now()};

public:
    void reset();
    [[nodiscard]] double elapsed() const;
};


#endif //LINALGEBRA_TIMER_H
