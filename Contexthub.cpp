/*
 * Copyright (C) 2018 The Android Open Source Project
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

#include "Contexthub.h"

namespace android {
namespace hardware {
namespace contexthub {
namespace V1_0 {
namespace renesas {

using ::android::hardware::contexthub::V1_0::ContextHub;


Return<void> Contexthub::getHubs(getHubs_cb _hidl_cb)
{
    hidl_vec<ContextHub> hubs{};
    _hidl_cb(hubs);

    return Void();
}


Return<Result> Contexthub::sendMessageToHub(uint32_t /*hubId*/,
                                            const ContextHubMsg& /*msg*/)
{
    return Result::BAD_PARAMS;
}


Return<Result> Contexthub::registerCallback(uint32_t /*hubId*/,
                                            const sp<IContexthubCallback> & /*cb*/)
{
    return Result::BAD_PARAMS;
}


Return<Result> Contexthub::unloadNanoApp(uint32_t /*hubId*/,
                                         uint64_t /*appId*/,
                                         uint32_t /*transactionId*/)
{
    return Result::BAD_PARAMS;
}

Return<Result> Contexthub::loadNanoApp(uint32_t /*hubId*/,
                                       const NanoAppBinary& /*appBinary*/,
                                       uint32_t /*transactionId*/)
{
    return Result::BAD_PARAMS;
}

Return<Result> Contexthub::enableNanoApp(uint32_t /*hubId*/,
                                         uint64_t /*appId*/,
                                         uint32_t /*transactionId*/)
{
    return Result::BAD_PARAMS;
}

Return<Result> Contexthub::disableNanoApp(uint32_t /*hubId*/,
                                          uint64_t /*appId*/,
                                          uint32_t /*transactionId*/)
{
    return Result::BAD_PARAMS;
}

Return<Result> Contexthub::queryApps(uint32_t /*hubId*/)
{
    return Result::BAD_PARAMS;
}

}  // namespace renesas
}  // namespace V1_0
}  // namespace contexthub
}  // namespace hardware
}  // namespace android
