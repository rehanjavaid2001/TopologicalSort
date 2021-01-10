//Rehan Javaid, rj3dxu, 11/16/2020, middleearth.h

/*!
 * @file middleearth.h
 * @brief Middle Earth header file
 */

/*! 
 * @def MIDDLEEARTH_H 
 * defining the header file middleearth.h which allows for the 
 * creation of a Middle Earth universe
 */

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
  /*! 
   *@class MiddleEarth
   * @brief This is the MiddleEarth Class
   * It contains both public methods and private fields
   */
public:
  /*!
   * @brief Middle Earth Constructor 
   *
   *@param xsize The size of Middle Earth wrt x
   *@param ysize The size of Middle Earth wrt y
   *@param num_cities The number of cities in the world
   *@param seed Necessary for random number generation
   */
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
  /*! 
   * @brief Prints out info on the created 'world'
   */
    void print();
  /*!
   * @brief Prints a tab-separated table of the distances,
   * which can be loaded into Excel or similar
   */
    void printTable();
  /*!
   * @brief Gets the distance getween two passed cities 
   *
   * @param city1 One of two cities to find distance between
   * @param city2 Second of two cities to find distance between
   * @return The distance between the two cities
   */
    float getDistance(const string& city1, const string& city2);
  /*!
   * @brief Gives the list of cities to travel to 
   *
   * @param length The length of the span for which to look for cities to trav el to
   * @return List of cities to travel to 
   *
   */
    vector<string> getItinerary(unsigned int length);

private:
  /*!
   * integer values of the number of cities, x and y coordinates
   */
    int num_city_names, xsize, ysize;
  /*!
   * map of x and y positions
   */
    unordered_map<string, float> xpos, ypos;
  /*!
   * collection to hold list of cities
   */
    vector<string> cities;
  /*! 
   * unordered_map, stores distances
   */
    unordered_map<string, unordered_map<string, float>> distances;

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif
