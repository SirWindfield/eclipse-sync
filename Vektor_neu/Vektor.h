//
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

#ifndef Vektor_H
#define Vektor_H

class Vektor
{
public:
    /**
     * @brief The constructor.
     *
     * @param x The x-component
     * @param y The y-component
     * @param z The z-component
     */
    Vektor(double x, double y, double z);

    /**
     * @brief The destructor
     */
    ~Vektor();

    /**
     * @brief Returns the x component of this vector.
     *
     * @return The x component.
     */
    double getX() const;

    /**
     * @brief Returns the y component of this vector.
     *
     * @return The y component.
     */
    double getY() const;

    /**
     * @brief Returns the z component of this vector.
     *
     * @return The z component.
     */
    double getZ() const;

    /**
     * @brief Subtracts two vectors from each other.
     *
     * @param input The other vector reference that will be used for subtraction.
     * @return The resulting vector instance.
     */
    Vektor sub(const Vektor& input) const;

    /**
     * @brief Adds two vectors with each other.
     *
     * @param input The other vector that will be used for addition.
     * @return The resulting vector.
     */
    Vektor add(const Vektor& input) const;

    /**
     * @brief Returns the length of the vector.
     *
     * @return The length.
     */
    double length() const;

    /**
     * @brief Checks if two vectors are orthogonal to each other.
     *
     * Two vectors are orthogonal to each other if there scalar product equals 0.
     * The comparison will be done by using a threshold, by default 0.1.
     * Is the scalar product less than that, the two vectors are regarded as orthogonal.
     *
     * @param input The other vector that will be used for the calculation.
     * @return <b>True</b> if the vectors are orthogonal to each other, <b>false</b> otherwise.
     */
    bool ortho(const Vektor& input) const;

    /**
     * @brief Returns the scalar product of two vectors.
     *
     * @param input The other vector.
     * @return The scalar product of the two vectors.
     */
    double scalarProd(const Vektor& input) const;

    /**
     * @brief Returns the angle in degree between two vectors.
     *
     * @param input The other vector.
     * @return The angle (in degree) between the two vectors.
     */
    double angle(const Vektor& input) const;

    /**
     * @brief Rotates this vector around the z-component.
     *
     * @param rad The radian this vector should be rotated by.
     */
    void rotateAroundZ(const double rad);

    /**
     * @brief Prints the vector components to the console. Used for debugging.
     */
    void ausgabe() const;

private:
    double x;
    double y;
    double z;

};

#endif
