#ifndef _PROJECT_CONFIGURATION_H
#define _PROJECT_CONFIGURATION_H

/* Header */
#ifdef LOGICAL_VERIFICATION
#include <HippoMocks/hippomocks.h> // The main header of HippoMocks. Reference: https://github.com/dascandy/hippomocks

#include "gtest/gtest.h" // The main header of GoogleTest. Reference: https://github.com/google/googletest

#endif /* LOGICAL_VERIFICATION */

// Standard libraries
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <cstdio>
#include <string>

/* Macro */

#define ENABLE                     (true)
#define DISABLE                    (false)

/** Functionality options */

#define USE_OPENMP                 (ENABLE) // Whether use OpenMP to speedup this project
#define PRINT_STATISTICS_INTO_FILE (ENABLE) // Whether print the statistics into files
#define USE_EXCEPTION              (ENABLE) // Whether use exception to handle errors

/* Type */

/** 
 * The primitive class for data output.
 */
class DATA_OUTPUT
{
public:
    const std::string data_name;      // The name of data to output
    const std::string file_extension; // The name of file extension
    FILE* file_handler = nullptr;
    char* file_name    = nullptr;

    /**
     *  Constructor
     * 
     * @param[in] v1 The name of data to output.
     * @param[in] v2 The name of file extension.
     */
    DATA_OUTPUT(std::string v1, std::string v2);

    /**
     *  Constructor
     * 
     * @param[in] v1 The name of data to output.
     * @param[in] v2 The name of file extension.
     * @param[in] string The name string.
     */
    DATA_OUTPUT(std::string v1, std::string v2, const char* string);

    /**
     *  Constructor
     * 
     * @param[in] v1 The name of data to output.
     * @param[in] v2 The name of file extension.
     * @param[in] string_array The string array containing a string.
     * @param[in] number The number of strings in the string_array.
     */
    DATA_OUTPUT(std::string v1, std::string v2, char** string_array, uint32_t number);
    ~DATA_OUTPUT();

    /**
     *  Initialize the output file's name based on the name of input @p string.
     * 
     * @param[in] string The name string.
     */
    void output_file_initialization(const char* string);

    /**
     *  Initialize the output file's name based on the name of input @p string_array[number].
     *  It extracts the last name of each string from @p string_array using the delimiter "/" and concatenates them to form a single string as the result.
     * 
     * @param[in] string_array The string array containing a string.
     * @param[in] number The number of strings in the string_array.
     */
    void output_file_initialization(char** string_array, uint32_t number);
};

// Statistics output class
class STATISTICS : public DATA_OUTPUT
{
public:
    STATISTICS(std::string v1, std::string v2);
    STATISTICS(std::string v1, std::string v2, char** string_array, uint32_t number);
    ~STATISTICS();

private:
    void statistics_initialization();
};

/* Prototype */

extern STATISTICS output_statistics;

/* Variable */

/* Function */

#endif /* _PROJECT_CONFIGURATION_H */
