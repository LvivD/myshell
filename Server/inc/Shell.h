//
// Created by sotnyk on 31.01.21.
//

#ifndef MYSHELL_SHELL_H
#define MYSHELL_SHELL_H

//

#include <cstddef>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

class Shell {

public:

    // read line stored in buff; its size is stored in len_buff;
    // write the result of the execution in the buff and the size of result in len_buff;
    // max size of buff is max_buff_size;
    int exec_line(char *buff, size_t *len_buff, size_t max_buff_size=1024);

private:

    std::vector<std::string> parse_line(char *buff, size_t len_buff);

};


#endif //MYSHELL_SHELL_H
