#pragma once

#include <functional>

template <typename PARAMS>
using Delegate = std::function<PARAMS>;
