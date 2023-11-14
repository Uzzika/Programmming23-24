// Copyright 2023 Dudchenko Olesya
#ifndef _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "..\Gtests\gtest.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    system("pause");
    return 0;
}
#endif _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING