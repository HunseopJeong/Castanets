// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/offline_pages/prefetch/prefetch_background_task_scheduler.h"

#include <memory>

#include "base/android/jni_string.h"
#include "jni/PrefetchBackgroundTaskScheduler_jni.h"

namespace offline_pages {

// static
void PrefetchBackgroundTaskScheduler::Schedule(int additional_delay_seconds,
                                               const std::string& gcm_token) {
  JNIEnv* env = base::android::AttachCurrentThread();
  prefetch::Java_PrefetchBackgroundTaskScheduler_scheduleTask(
      env, additional_delay_seconds,
      base::android::ConvertUTF8ToJavaString(env, gcm_token));
}

// static
void PrefetchBackgroundTaskScheduler::ScheduleLimitless(
    int additional_delay_seconds,
    const std::string& gcm_token) {
  JNIEnv* env = base::android::AttachCurrentThread();
  prefetch::Java_PrefetchBackgroundTaskScheduler_scheduleTaskLimitless(
      env, additional_delay_seconds,
      base::android::ConvertUTF8ToJavaString(env, gcm_token));
}

// static
void PrefetchBackgroundTaskScheduler::Cancel() {
  JNIEnv* env = base::android::AttachCurrentThread();
  prefetch::Java_PrefetchBackgroundTaskScheduler_cancelTask(env);
}

}  // namespace offline_pages
