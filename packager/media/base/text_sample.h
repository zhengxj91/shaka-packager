// Copyright 2017 Google Inc. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef PACKAGER_MEDIA_BASE_TEXT_SAMPLE_H_
#define PACKAGER_MEDIA_BASE_TEXT_SAMPLE_H_

#include <stdint.h>

#include <string>

namespace shaka {
namespace media {

class TextSample {
 public:
  TextSample() = default;

  const std::string& id() const { return id_; }
  uint64_t start_time() const { return start_time_; }
  uint64_t duration() const { return duration_; }
  const std::string& settings() const { return settings_; }
  const std::string& payload() const { return payload_; }
  uint64_t EndTime() const;

  void set_id(const std::string& id) { id_ = id; }
  void set_settings(const std::string& settings) { settings_ = settings; }
  void SetTime(uint64_t start_time, uint64_t end_time);
  void AppendPayload(const std::string& payload);

 private:
  TextSample(const TextSample&) = delete;
  TextSample& operator=(const TextSample&) = delete;

  std::string id_;
  uint64_t start_time_ = 0;
  uint64_t duration_ = 0;
  std::string settings_;
  std::string payload_;
};

}  // namespace media
}  // namespace shaka

#endif  // MEDIA_BASE_TEXT_SAMPLE_H_
