#include "mock_process_monitor.h"

#include <cstdlib>
#include <ctime>

using mock_process_monitor::monitor;

namespace mock_process_monitor {
    std::size_t random_in_range(std::size_t min, std::size_t max) {
        static const int dummy = [] {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            return 0;
        }();
        (void)dummy;

        const auto range = max - min + 1;
        return std::rand() % range + min;
    }
}  // namespace mock_process_monitor

monitor::monitor() noexcept : m_last_cpu_usage(5), m_last_memory_usage(15), m_last_thread_count(4), m_last_kernel_object_count(21) {}

std::size_t monitor::cpu_usage() noexcept {
    std::size_t max_range, min_range;

    if (m_last_cpu_usage >= 95) {
        max_range = 95;
    } else {
        max_range = m_last_cpu_usage + 5;
    }

    if (m_last_cpu_usage <= 5) {
        min_range = 1;
    } else {
        min_range = m_last_cpu_usage - 5;
    }

    m_last_cpu_usage = random_in_range(min_range, max_range);
    return m_last_cpu_usage;
}

std::size_t monitor::memory_usage() noexcept {
    std::size_t max_range, min_range;

    if (m_last_memory_usage >= 95) {
        max_range = 95;
    } else {
        max_range = m_last_memory_usage + 5;
    }

    if (m_last_memory_usage <= 5) {
        min_range = 1;
    } else {
        min_range = m_last_memory_usage - 5;
    }

    m_last_memory_usage = random_in_range(min_range, max_range);
    return m_last_memory_usage;
}

std::size_t monitor::thread_count() noexcept {
    const auto max_range = m_last_thread_count + 4;
    std::size_t min_range;

    if (m_last_thread_count <= 5) {
        min_range = 5;
    } else {
        min_range = m_last_thread_count - 2;
    }

    m_last_thread_count = random_in_range(min_range, max_range);
    return m_last_thread_count;
}

std::size_t monitor::kernel_object_count() noexcept {
    const auto max_range = m_last_thread_count + 20;
    const auto min_range = m_last_thread_count + 3;

    m_last_kernel_object_count = random_in_range(min_range, max_range);
    return m_last_kernel_object_count;
}
