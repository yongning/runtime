#pragma once

#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <optional>

namespace Runtime {

class Thread {
public:
    virtual ~Thread() = default;

    virtual std::string name() const = 0;

    virtual void join() = 0;

    
};

using ThreadPtr = std::unique_ptr<Thread>;

struct Options {
    std::string name_;
};

// using OptionsOptConstRef = const absl::optional<Options>&;
using OptionsOptConstRef = const std::optional<Options>&;

class ThreadFactory {
public:
    virtual ~ThreadFactory() = default;

//    virtual ThreadPtr createThread(std::functon<void()> thread_routine,
//                                   OptionsOptConstRef options = absl::nullopt) = 0;
    virtual ThreadPtr createThread(std::function<void()> thread_routine,
                                   OptionsOptConstRef options = std::nullopt) = 0;

    virtual ThreadId currentThreadId = 0;
};

using ThreadFactoryPtr = std::unique_ptr<ThreadFactory>;



}
