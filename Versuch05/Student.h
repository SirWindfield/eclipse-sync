#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student {
public:

	/**
	 * @brief Constructor
	 */
	Student();

	/**
	 * @brief Constructor.
	 * @param matNr The unique id of each student.
	 * @param name The full name of the student.
	 * @param dateOfBirth The student's date of birth.
	 * @param address The address of the student.
	 */
	Student(unsigned int matNr, std::string name, std::string dateOfBirth,
			std::string address);

	/**
	 * @brief Returns the unique id.
	 * @return The id.
	 */
	unsigned int getMatNr();

	/**
	 * @brief Returns the name.
	 * @return the name.
	 */
	std::string getName();

	/**
	 * @brief Returns the date of birth.
	 * @return the date of birth.
	 */
	std::string getDateOfBirth();

	/**
	 * @brief Returns the address.
	 * @return the address.
	 */
	std::string getAddress();

	/**
	 * @brief Prints a small description of the student to std::cout.
	 */
	void print();
private:
	unsigned int matNr;
	std::string name;
	std::string dateOfBirth;
	std::string address;
};

#endif
