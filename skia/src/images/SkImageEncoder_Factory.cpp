
/*
 * Copyright 2009 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkImageEncoder.h"
#include "SkTRegistry.h"

typedef SkTRegistry<SkImageEncoder*, SkImageEncoder::Type> EncodeReg;

// Can't use the typedef here because of complex C++ corner cases
template EncodeReg* SkTRegistry<SkImageEncoder*, SkImageEncoder::Type>::gHead;

SkImageEncoder* SkImageEncoder::Create(Type t) {
    SkImageEncoder* codec = NULL;
    const EncodeReg* curr = EncodeReg::Head();
    while (curr) {
        if ((codec = curr->factory()(t)) != NULL) {
            return codec;
        }
        curr = curr->next();
    }
    return NULL;
}
