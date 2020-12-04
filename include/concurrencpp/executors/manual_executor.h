#ifndef CONCURRENCPP_MANUAL_EXECUTOR_H
#define CONCURRENCPP_MANUAL_EXECUTOR_H

#include "concurrencpp/executors/derivable_executor.h"
#include "concurrencpp/executors/constants.h"

#include <deque>

namespace concurrencpp {
    class alignas(64) manual_executor final : public derivable_executor<manual_executor> {

       private:
        mutable std::mutex m_lock;
        std::deque<std::coroutine_handle<>> m_tasks;
        std::condition_variable m_condition;
        bool m_abort;
        std::atomic_bool m_atomic_abort;

        void destroy_tasks(std::unique_lock<std::mutex>& lock) noexcept;

       public:
        manual_executor();

        void enqueue(std::coroutine_handle<> task) override;
        void enqueue(std::span<std::coroutine_handle<>> tasks) override;

        int max_concurrency_level() const noexcept override;

        void shutdown() noexcept override;
        bool shutdown_requested() const noexcept override;

        std::size_t size() const noexcept;
        bool empty() const noexcept;

        bool loop_once();
        bool loop_once(std::chrono::milliseconds max_waiting_time);

        std::size_t loop(std::size_t max_count);

        std::size_t clear() noexcept;

        void wait_for_task();
        bool wait_for_task(std::chrono::milliseconds max_waiting_time);
    };
}  // namespace concurrencpp

#endif
