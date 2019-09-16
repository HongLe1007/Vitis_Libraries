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

#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "xf_fintech_csv.hpp"
#include "xf_fintech_heston_test_suite.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 3) {
        unsigned int argIndex = 1;
        string csvfile = argv[argIndex++];
        double delta = std::strtod(argv[argIndex++], NULL);
        std::cout << "Test Harness Running. Input CSV file:" << csvfile << " Delta: " << delta << std::endl
                  << std::endl;

        ifstream infile(csvfile);
        CSV csv;
        csv.init(infile);

        HestonFDTestSuite testSuite;
        testSuite.Run(csv, delta);
    } else {
        std::cerr << "Usage: " << argv[0] << ": <CSV test case list> <delta>" << std::endl;
    }

    return 0;
}
