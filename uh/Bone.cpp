#include "Bone.h"

void Bone::draw(sf::RenderWindow& window)
{
	window.draw(parent);
	for(int i = 0; i < children.size(); i++){
		children[i].draw(window);
	}
}
