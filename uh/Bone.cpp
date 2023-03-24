#include "Bone.h"

void Bone::draw(sf::RenderWindow& window)
{
	thisBone.updateDebug();
	window.draw(thisBone);
	for(int i = 0; i < children.size(); i++){
		children[i].draw(window);
	}
}
