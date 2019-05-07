/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_HARDWARE_CONTEXTHUB_V1_0_CONTEXTHUB_H_
#define ANDROID_HARDWARE_CONTEXTHUB_V1_0_CONTEXTHUB_H_

#include <android/hardware/contexthub/1.0/IContexthub.h>

namespace android {
namespace hardware {
namespace contexthub {
namespace V1_0 {
namespace renesas {

using ::android::hardware::contexthub::V1_0::Result;
using ::android::hardware::Void;

class Contexthub : public IContexthub
{
    public:
    ~Contexthub() = default;
    Return<void> getHubs(getHubs_cb _hidl_cb) override;
    Return<Result> registerCallback(uint32_t hubId,
                                    const sp<IContexthubCallback> &cb) override;
    Return<Result> sendMessageToHub(uint32_t hubId,
                                    const ContextHubMsg &msg) override;
    Return<Result> loadNanoApp(uint32_t hubId,
                               const NanoAppBinary& appBinary,
                               uint32_t transactionId) override;
    Return<Result> unloadNanoApp(uint32_t hubId,
                                 uint64_t appId,
                                 uint32_t transactionId) override;
    Return<Result> enableNanoApp(uint32_t hubId,
                                 uint64_t appId,
                                 uint32_t transactionId) override;
    Return<Result> disableNanoApp(uint32_t hubId,
                                  uint64_t appId,
                                  uint32_t transactionId) override;
    Return<Result> queryApps(uint32_t hubId) override;
};


}  // namespace renesas
}  // namespace V1_0
}  // namespace contexthub
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_CONTEXTHUB_V1_0_CONTEXTHUB_H_
