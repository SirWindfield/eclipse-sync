/*
 * @file main.h
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

/**
 * @brief Calculates the view distance based on the above parameters and a custom height of a platform.
 *
 * This function will approximate the viewing distance of a human standing on a platform that is `height` meters high.
 * The result will get printed to the console.
 *
 * @param height The height of the platform. Can be 0 too.
 */
void calculateViewPort(double height);

#endif /* MAIN_H_ */
