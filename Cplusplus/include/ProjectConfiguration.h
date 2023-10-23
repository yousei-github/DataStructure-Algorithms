#ifndef _PROJECTCONFIGURATION_H
#define _PROJECTCONFIGURATION_H

/* Header */
#ifdef LOGICAL_VERIFICATION
#include <HippoMocks/hippomocks.h> // The main header of HippoMocks. Reference: https://github.com/dascandy/hippomocks

#include "gtest/gtest.h" // The main header of GoogleTest. Reference: https://github.com/google/googletest
#endif                   // LOGICAL_VERIFICATION

// Standard libraries
#include <string.h>

#include <cstdio>
#include <string>

/* Macro */
#ifdef __cplusplus

#else
#define true (1u)
#define false (0u)
#endif /* __cplusplus */

#define ENABLE                     (true)
#define DISABLE                    (false)

/** Functionality options */
#define USE_OPENMP                 (ENABLE) // Whether use OpenMP to speedup this project
#define PRINT_STATISTICS_INTO_FILE (ENABLE) // Whether print the statistics into files

/* Type */
// Data output class
class DATA_OUTPUT
{
public:
    const std::string data_name;
    FILE* file_handler = nullptr;
    char* file_name    = nullptr;
    const std::string file_extension;

    DATA_OUTPUT(std::string v1, std::string v2);
    ~DATA_OUTPUT();

    void output_file_initialization(char** string_array, uint32_t number);
};

/* Prototype */

/* Variable */

/* Function */

#endif /* _PROJECTCONFIGURATION_H */
