#include "ProjectConfiguration.h"

DATA_OUTPUT::DATA_OUTPUT(std::string v1, std::string v2)
: data_name(v1), file_extension(v2)
{
}

DATA_OUTPUT::~DATA_OUTPUT()
{
    if (file_handler) // check the validity of this file handler
    {
        fclose(file_handler);
    }

    if (file_name) // check the validity of this file name string
    {
        printf("Output %s into %s\n", data_name.c_str(), file_name);
        free(file_name);
    }
}

void DATA_OUTPUT::output_file_initialization(char** string_array, uint32_t number)
{
    std::string benchmark_names;
    for (uint32_t i = 0; i < number; i++)
    {
        char* string_temp = (char*) malloc(strlen(string_array[i]) + 1);
        strcpy(string_temp, string_array[i]);

        const char* delimiter = "/";
        char empty[]          = "";
        char* token           = empty;
        char* last_token      = empty;

        /* get the first token */
        token                 = strtok(string_temp, delimiter);

        /* walk through other tokens */
        while (token != NULL)
        {
            last_token = token;
            token      = strtok(NULL, delimiter);
        }

        benchmark_names += std::string(last_token) + "_";

        free(string_temp);
    }
    benchmark_names.erase(benchmark_names.size() - 1);

    // append file_extension to benchmark_names.
    benchmark_names += file_extension.c_str();

    file_handler = fopen(benchmark_names.c_str(), "w");
    file_name    = (char*) malloc(benchmark_names.size() + 1);
    strcpy(file_name, benchmark_names.c_str());
}