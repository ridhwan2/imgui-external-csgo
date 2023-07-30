#ifndef HACKS_H
#define HACKS_H

#include "Memory.h"
#include <cstdint>

namespace hacks {
    void startHacks() noexcept;
    void VisualsThread(const Memory& mem) noexcept;
    void TriggerThread(const Memory& mem) noexcept;
    void BhopThread(const Memory& mem) noexcept;
    void RcsThread(const Memory& mem) noexcept;
}

#endif // HACKS_H
