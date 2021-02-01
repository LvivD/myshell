//
// Created by sotnyk on 31.01.21.
//

#include "Shell.h"

int Shell::exec_line(char *buff, size_t *len_buff, size_t max_buff_size) {
    std::vector<std::string> commands = split_line(buff, *len_buff);
    std::cout << "Command arg num: " << commands.size() << std::endl;
    std::cout << "Command read:" << std::endl;
    for (const auto &value : commands) {
        std::cout << value << "\n";
    }
    std::cout << std::endl;
    buff[strlen(buff)] = '\n';
    get_pwd(buff + strlen(buff));
    return 0;
}

std::vector<std::string> Shell::split_line(char *buff, size_t len_buff) {
    std::vector<std::string> parsed_line;
    char *pch = strtok (buff," ");
    while (pch != nullptr)
    {
        parsed_line.emplace_back(pch);
        pch = strtok (NULL, " ");
    }
    return parsed_line;
}

int Shell::get_pwd(char *buff, size_t max_buff_size) {
    strcpy(buff, (curr_path.string() + "$ \0").c_str());
    return 0;
}