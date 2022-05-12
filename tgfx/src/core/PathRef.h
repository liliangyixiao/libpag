/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Tencent is pleased to support the open source community by making libpag available.
//
//  Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
//  except in compliance with the License. You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  unless required by applicable law or agreed to in writing, software distributed under the
//  license is distributed on an "as is" basis, without warranties or conditions of any kind,
//  either express or implied. see the license for the specific language governing permissions
//  and limitations under the license.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "pathkit.h"

namespace tgfx {
class Path;

// When tessellating curved paths into linear segments, this defines the maximum distance in
// screen space which a segment may deviate from the mathematically correct value. Above this
// value, the segment will be subdivided. This value was chosen to approximate the super sampling
// accuracy of the raster path (16 samples, or one quarter pixel).
static constexpr float DefaultTolerance = 0.25f;

class PathRef {
 public:
  static const pk::SkPath& ReadAccess(const Path& path);

  static pk::SkPath& WriteAccess(Path& path);

  PathRef() = default;

  explicit PathRef(const pk::SkPath& path) : path(path) {
  }

 private:
  pk::SkPath path = {};

  friend class Path;
  friend bool operator==(const Path& a, const Path& b);
  friend bool operator!=(const Path& a, const Path& b);
};
}  // namespace tgfx
