/** --------------------------------------------------------
* @file    uiTools.h
* @author  Luke Wagner
* @version 1.0
*
* For use with SFML
*   Contains additional useful functions for manipulating SFML UI elements
*	To-Do's: Add overloads for different object/param types
*
* ------------------------------------------------------------ */
#pragma once

#include <SFML/Graphics.hpp>

enum cornerType { TOP_RIGHT, TOP_LEFT, BOTTOM_LEFT, BOTTOM_RIGHT }; //for setting UI properties relative to local bounds

namespace myUiTools {
	/**
	* Returns the coordinates of a specific corner in realtion to a given (rectangle) bounds.
	* Add overloads for other types including sf::FloatRect?
	*
	*   @param corner - the desired corner of the rectangle
	*	@param bounds - the width and height of the rectangle
	*	@return sf::Vector2f - the coordinates of the desired corner
	*/
	sf::Vector2f cornerTypeToVector(cornerType corner, sf::Vector2f bounds);

	// ======================================================
	// Text object functions
	/**
	* Sets object origin relative to its local bounds. Note: for text objects, origin not set relative
	* to (0,0) but to (obj.getLocalBounds().left, obj.getLocalBounds().top), because text has some padding
	* built in
	*
	*   @param obj - the object to modify
	*	@param originPoint - which corner the origin should be set at (ie BOTTOM_RIGHT, TOP_LEFT, etc)
	*/
	void setObjectOrigin(sf::Text& obj, const cornerType originPoint);

	/**
	* Draws an outline around the UI object to the window
	*
	*   @param win - the window object
	*   @param obj - the object to outline
	*/
	void drawOutline(sf::RenderWindow& win, const sf::Text& objToDraw, sf::Color color);
}