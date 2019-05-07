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

#define LOG_TAG "ContexthubHAL"

#include <android-base/logging.h>
#include <binder/ProcessState.h>
#include <hidl/HidlTransportSupport.h>
#include <android/hardware/contexthub/1.0/IContexthub.h>

#include "Contexthub.h"


using ::android::sp;
using ::android::hardware::joinRpcThreadpool;
using ::android::hardware::configureRpcThreadpool;

using namespace android::hardware::contexthub::V1_0;

int main(int, char **)
{

    android::ProcessState::initWithDriver ("/dev/vndbinder");
    configureRpcThreadpool(1, true);

    sp<IContexthub> contexthub_hal = new renesas::Contexthub;

    const auto status = contexthub_hal->registerAsService();
    CHECK_EQ(status, android::OK) << "Contexthub HAL failed to register";

    joinRpcThreadpool();
}
