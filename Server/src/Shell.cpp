//
// Created by sotnyk on 31.01.21.
//

#include "Shell.h"

int Shell::exec_line(char *buff, size_t *len_buff, size_t max_buff_size) {
    std::vector<std::string> commands = parse_line(buff, *len_buff);
}

std::vector<std::string> Shell::parse_line(char *buff, size_t len_buff) {
    std::vector<std::string> parsed_line;
    char *pch = strtok (buff," ");
    while (pch != NULL)
    {
        parsed_line.emplace_back(pch);
        std::cout << pch << " ";
        pch = strtok (NULL, " ");
    }
    std::cout << std::endl;
    return parsed_line;
}