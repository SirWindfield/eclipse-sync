/** @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 5: Dynamische Datenstrukturen
 *
 * *Die erklaerenden Texte wurden zum Teil von* wikipedia.org *uebernommen*@n
 * *Siehe hierzu die entsprechende* [Webseite][wikipedia].
 *
 * [wikipedia]: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

/**
 * @file main.cpp
 *
 * content: main routine
 */

#include <iostream>
#include <string>
#include "main.h"
#include "Student.h"
#include <vector>
#include <algorithm>

// used for finding a student based on his id
struct find_student {

	unsigned id;

	find_student(unsigned id) {
		this->id = id;
	}

	bool operator ()(Student& student) const {
		return student.getMatNr() == id;
	}
};

int main()
{
    std::vector<Student> data;
    Student student = Student();

    char abfrage;
    std::cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;

    if (abfrage != 'j')
    {
        student = Student(12345, "Siggi Baumeister", "23.04.1983",
                "Ahornst.55");
        data.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963",
                "W�llnerstr.9");
        data.push_back(student);
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        data.push_back(student);
    }

    do
    {
        // *INDENT-OFF*
        std::cout << "\nMenue:" << std::endl << "-----------------------------"
                << std::endl << "(1): Datenelement hinzufuegen" << std::endl
                << "(2): Datenelement abhaengen" << std::endl
                << "(3): Datenbank ausgeben" << std::endl
                << "(4): Datenbank rueckwaerts ausgeben" << std::endl
                << "(5): Datenelement loeschen" << std::endl
                << "(6): Datenelement hinten anhaengen" << std::endl
                << "(7): Beenden" << std::endl;
        // *INDENT-ON*
        std::cin >> abfrage;

        switch (abfrage)
        {
        case '1':
        {
            data.push_back(create_student());
        }
            break;
        case '2':
        {
            Student delElem = Student();
            data.pop_back();
            std::cout << "Das letzte Datenelemt wird entfernt\n";
        }
            break;

        case '3':
        {
            std::cout << "Inhalt der Liste:\n";
            for(std::vector<Student>::iterator it = data.begin(); it != data.end(); it++) {
            	it->print();
            }
            break;
        }

        case '4':
        {
            std::cout << "Inhalt der Liste (rueckwaerts):" << std::endl;
            for(std::vector<Student>::reverse_iterator it = data.rbegin(); it != data.rend(); it++) {
            	it->print();
            }
            break;
        }

        case '5':
        {
            unsigned int matrikel;
            std::cout << "Geben Sie die Matrikelnummer ein: " << std::endl;
            std::cin >> matrikel;


            std::vector<Student>::iterator it = std::find_if(data.begin(), data.end(), find_student(matrikel));
            if (it != data.end()) // wurde gefunden
            {
            	data.erase(it);
                std::cout << "Student wurde erfolreich geloescht" << std::endl;
            } else
            {
                std::cout
                        << "Es wurde kein Student mit der Matrikelnummer gefunden worden"
                        << std::endl;
            }
            break;
        }

        case '6':
        {
            data.push_back(create_student());
            break;
        }

        case '7':
        {
            std::cout << "Das Programm wird nun beendet";
            break;
        }

        default:
        {
            std::cout << "Falsche Eingabe, bitte nochmal";
            break;
        }
        }
    } while (abfrage != '7');

    return 0;
}

Student create_student()
{
    unsigned int matNr = 0;
    std::string name = "";
    std::string dateOfBirth = "";
    std::string address = "";

    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
    std::cin.ignore(10, '\n'); // ignore character '\n', which still is in the buffer
    getline(std::cin, name);    // get entire line, including whitespace
    std::cout << "Geburtsdatum: ";
    getline(std::cin, dateOfBirth);
    std::cout << "Adresse: ";
    getline(std::cin, address);
    std::cout << "Matrikelnummer: ";
    std::cin >> matNr;

    return Student(matNr, name, dateOfBirth, address);
}
