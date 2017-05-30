/**
 * @file ListElem.h
 *
 * content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

/**
 * @brief A ListElem is used to keep track of the added data and data order.
 */
class ListElem
{
private:
    /**
     * The data hold by this list element.
     */
    Student data;

    /**
     * A pointer to the next list element.
     */
    ListElem* next;

    /**
     * A pointer to the previous list element.
     */
    ListElem* prev;

public:

    /**
     * @brief The constructor.
     *
     * @param data The data stored within this list element.
     * @param next The next list element that should be appended to this one.
     */
    ListElem(const Student &data, ListElem* const next);

    /**
     * @brief Sets the data of this list element.
     *
     * @param data The new data that should be set.
     */
    void setData(const Student &data);

    /**
     * @brief Sets the next element.
     *
     * @param next The new next element.
     */
    void setNext(ListElem* const next);

    /**
     * @brief Returns the data hold by this list element.
     *
     * @return The current data, e.g. the student.
     */
    Student getData() const;

    /**
     * @brief Returns the next list element.
     *
     * @return The next list element.
     */
    ListElem* getNext() const;

    void setPrevious(ListElem* const prev);

    ListElem* getPrevious() const;
};

#endif
