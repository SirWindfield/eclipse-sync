/*
 * main.h
 *
 *  Created on: 28.05.2017
 *      Author: Sven
 */

#ifndef MAIN_H_
#define MAIN_H_
/**
 * The amount that the earth vector should be rotated each iteration (in rad).
 */
#define DELTA_ROT 0.00000001 // works best

/**
 * The earth radius in km.
 */
#define EARTH_RADIUS_KM 6731

/**
 * The human height in meters.
 */
#define HUMAN_HEIGHT_M 1.8

/**
 * The platform on which the human stands.
 */
#define PLATFORM_HEIGHT_M 0

void calculateViewPort(double);

#endif /* MAIN_H_ */
