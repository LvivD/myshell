//
// Created by sotnyk on 31.01.21.
//

#ifndef MYSHELL_SHELL_H
#define MYSHELL_SHELL_H

#include <cstddef>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

class Shell {

public:

    // read line stored in buff; its size is stored in len_buff;
    // write the result of the execution in the buff and the size of result in len_buff;
    // max size of buff is max_buff_size;
    int exec_line(char *buff, size_t *len_buff, size_t max_buff_size=1024);

    // puts current directory of the shell in buffer
    int get_pwd(char *buff, size_t max_buff_size=1024);

private:

    std::filesystem::path curr_path = "~";

    // split line by spaces and store result in vector
    std::vector<std::string> split_line(char *buff, size_t len_buff);

};

#endif //MYSHELL_SHELL_H
