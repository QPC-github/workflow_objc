/*
 * Copyright (c) 2022 Jon Palmisciano. All rights reserved.
 *
 * Use of this source code is governed by the BSD 3-Clause license; the full
 * terms of the license can be found in the LICENSE.txt file.
 */

#pragma once

#include <cstdint>

namespace ObjectiveNinja {

/**
 * Bitmask used to remove the tags from a tagged pointer.
 */
constexpr uint64_t PointerMask = 0xFFFFFFFFF;

/**
 * Common functionality related to the Objective-C ABI.
 */
class ABI {
public:
    /**
     * Automatically resolve a pointer.
     *
     * This procedure supports pointers that are
     *
     *   1. direct and untagged (x86_64);
     *   2. direct and tagged (macOS 11, arm64e); and
     *   3. direct and image-relative (macOS 12+, arm64e).
     */
    static uint64_t decodePointer(uint64_t pointer, uint64_t imageBase);
};

}
