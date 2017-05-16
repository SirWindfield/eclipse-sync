#include <string>

#ifndef MAIN_H_
#define MAIN_H_

int encode(const char c, int offset);
int decode(const char c, int offset);

void caeser(std::string msg, int offset);

#endif /* MAIN_H_ */
