/*
 * main.h
 *
 *  Created on: 30.05.2017
 *      Author: 8284018
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <vector>
#include "Student.h"

Student create_student();
void print_data(std::vector<Student> data, bool reverse);

#endif /* MAIN_H_ */
