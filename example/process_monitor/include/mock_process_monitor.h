#ifndef MOCK_PROCESS_MONITOR_H
#define MOCK_PROCESS_MONITOR_H

#include <cstddef>

namespace mock_process_monitor {
    class monitor {

       private:
        std::size_t m_last_cpu_usage;
        std::size_t m_last_memory_usage;
        std::size_t m_last_thread_count;
        std::size_t m_last_kernel_object_count;

       public:
        monitor() noexcept;

        std::size_t cpu_usage() noexcept;
        std::size_t memory_usage() noexcept;
        std::size_t thread_count() noexcept;
        std::size_t kernel_object_count() noexcept;
    };
}  // namespace mock_process_monitor

#endif
