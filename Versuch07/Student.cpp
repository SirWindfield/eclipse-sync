#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth, std::string address) :
matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{ }

Student::Student() : matNr(0), name(""), dateOfBirth(""), address("")
{ }

unsigned int Student::getMatNr() const
{
	return this->matNr;
}

std::string Student::getName() const
{
	return this->name;
}

std::string Student::getDateOfBirth() const
{
	return this->dateOfBirth;
}

std::string Student::getAddress() const
{
	return this->address;
}

bool Student::operator ==(const Student& student) const {
	return this->matNr == student.matNr;
}

bool Student::operator <(const Student& student) const {
	return this->matNr < student.matNr;
}

bool Student::operator >(const Student& student) const {
	return this->matNr > student.matNr;
}

std::ostream& Student::print(std::ostream& out) const {
	out << this->getName() << ", MatNr. " << this->getMatNr() << " geb. am "
            << this->getDateOfBirth() << " wohnhaft in " << this->getAddress()
            << std::endl;
	return out;
}
