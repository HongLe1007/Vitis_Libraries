/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file svm_train.hpp
 * @brief interface of Data Analytics svm train kernel.
 */

#ifndef _XF_DATA_ANALYTICS_CLASSIFICATION_SVM3_TRAIN_HPP_
#define _XF_DATA_ANALYTICS_CLASSIFICATION_SVM3_TRAIN_HPP_
#include <ap_int.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "hls_math.h"
#include "hls_stream.h"
#include "xf_DataAnalytics/common/table_sample.hpp"

#define BURST_LEN 64
#define MAX_NUM_FEATURE 64 // 32
#define DATA_WIDTH 64
#define STREAM_NUM 8
#define SAMPLE_DEP 8 // 4
typedef double DATA_TYPE;

DATA_TYPE funcA3(DATA_TYPE op1, DATA_TYPE op2) {
    return (op1 * op2);
}

void funcB3(DATA_TYPE& reg, DATA_TYPE op) {
#pragma HLS inline off
    reg += op;
}

DATA_TYPE funcC3(DATA_TYPE op) {
    return op;
}

/**
 * @brief svm Train Kernel
 * \rst
 * For detailed document, see :ref:`svm_train_design`.
 * \endrst
 *
 * @param data input samples buffer
 * @param tree output weight buffer
 *
 */
extern "C" void SVM_C(ap_uint<512>* ddr, ap_uint<512>* weight);
#endif
