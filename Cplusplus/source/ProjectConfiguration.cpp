/* Header */
#include "ProjectConfiguration.h"

#include <stddef.h>

#include <cassert>
#include <cstdlib>
#include <iostream>

/* Macro */

/* Type */

/* Prototype */

/* Variable */

STATISTICS output_statistics("DataStructure-Algorithms statistics", ".statistics");

/* Function */

DATA_OUTPUT::DATA_OUTPUT(std::string v1, std::string v2)
: data_name(v1), file_extension(v2)
{
}

DATA_OUTPUT::DATA_OUTPUT(std::string v1, std::string v2, const char* string)
: data_name(v1), file_extension(v2)
{
    output_file_initialization(string);
}

DATA_OUTPUT::DATA_OUTPUT(std::string v1, std::string v2, char** string_array, uint32_t number)
: data_name(v1), file_extension(v2)
{
    output_file_initialization(string_array, number);
}

DATA_OUTPUT::~DATA_OUTPUT()
{
    if (file_handler) // Check the validity of this file handler
    {
        fclose(file_handler);
    }

    if (file_name) // Check the validity of this file name string
    {
        std::printf("Output %s into %s\n", data_name.c_str(), file_name);
        free(file_name);
    }
}

void DATA_OUTPUT::output_file_initialization(const char* string)
{
    file_handler = fopen(string, "w");
    file_name    = (char*) malloc(strlen(string) + 1);

    if (file_name == nullptr)
    {
        std::cerr << __func__ << ": Memory Allocation Error." << std::endl;
        abort();
    }

    strcpy(file_name, string);
}

void DATA_OUTPUT::output_file_initialization(char** string_array, uint32_t number)
{
    std::string benchmark_names;
    for (uint32_t i = 0; i < number; i++)
    {
        char* string_temp = (char*) malloc(strlen(string_array[i]) + 1);

        if (string_temp == nullptr)
        {
            std::cerr << __func__ << ": Memory Allocation Error." << std::endl;
            abort();
        }

        strcpy(string_temp, string_array[i]);

        const char* delimiter = "/";
        char* token           = NULL;
        char* last_token      = NULL;

        /* Get the first token */
        token                 = strtok(string_temp, delimiter);

        /* Walk through other tokens */
        while (token != NULL)
        {
            last_token = token;
            token      = strtok(NULL, delimiter);
        }

        benchmark_names += std::string(last_token) + "_";

        free(string_temp);
    }
    benchmark_names.erase(benchmark_names.size() - 1);

    // Append file_extension to benchmark_names.
    benchmark_names += file_extension.c_str();

    file_handler = fopen(benchmark_names.c_str(), "w");
    file_name    = (char*) malloc(benchmark_names.size() + 1);

    if (file_name == nullptr)
    {
        std::cerr << __func__ << ": Memory Allocation Error." << std::endl;
        abort();
    }

    strcpy(file_name, benchmark_names.c_str());
}

STATISTICS::STATISTICS(std::string v1, std::string v2)
: DATA_OUTPUT(v1, v2)
{
    statistics_initialization();
}

STATISTICS::STATISTICS(std::string v1, std::string v2, char** string_array, uint32_t number)
: DATA_OUTPUT(v1, v2, string_array, number)
{
    statistics_initialization();
}

STATISTICS::~STATISTICS()
{
    if (file_handler) // Check the validity of this file handler
    {
        std::fprintf(file_handler, "\n\nInformation\n\n");
    }
}

void STATISTICS::statistics_initialization()
{
    std::cout << "Initialize " << data_name << std::endl;

    /* Initialize variabes */
}
