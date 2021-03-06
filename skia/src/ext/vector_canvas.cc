// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ext/vector_canvas.h"
#include "core/SkDevice.h"

namespace skia {

VectorCanvas::VectorCanvas(SkDevice* device) {
  setDevice(device)->unref(); // Created with refcount 1, and setDevice refs.
}

VectorCanvas::~VectorCanvas() {
}

SkBounder* VectorCanvas::setBounder(SkBounder* bounder) {
  if (!IsTopDeviceVectorial())
    return PlatformCanvas::setBounder(bounder);

  // This function isn't used in the code. Verify this assumption.
  SkASSERT(false);
  return NULL;
}

SkDrawFilter* VectorCanvas::setDrawFilter(SkDrawFilter* filter) {
  // This function isn't used in the code. Verify this assumption.
  SkASSERT(false);
  return NULL;
}

bool VectorCanvas::IsTopDeviceVectorial() const {
  SkDevice* device = GetTopDevice(*this);
  return device->getDeviceCapabilities() & SkDevice::kVector_Capability;
}

}  // namespace skia

