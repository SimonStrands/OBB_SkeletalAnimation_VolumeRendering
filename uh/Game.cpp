#include "Game.h"

Game::Game():
	win(sf::VideoMode(800, 600), "SFML window"),
	point(sf::Color::Red, sf::Vector2f(0,0)),
	testOBB(sf::Vector2f(50,50), sf::Vector2f(100,20), 0)
{
	done = false;
	for(int i = 0; i < 1000; i++){
		particles.push_back(Particle(sf::Color(random::getRandomInt(10,255),random::getRandomInt(10,255),random::getRandomInt(10,255)), sf::Vector2f(random::getRandomFloat(0,250) + 200, random::getRandomFloat(0,100) + 250)));
	}
	buildTestAnimation();
	buildTestSkeleton();
	this->skeleton.loadAnimation(testAnimation);
	this->skeleton.loadSkeleton(testSkeleton);
	deltaTimeSpeed = 0;
	renderSkeleton = false;
}

Game::~Game()
{

}

bool Game::Update(float dt)
{ 

	for(int i = 0; i < particles.size(); i++){
		if(testOBB.pointInside(particles[i].getOrginalPosition())){
			std::cout << "Particle: " << i << ", is inside box" << std::endl;  
		}
	}
	testOBB.updateDebug();

	skeleton.update(dt * deltaTimeSpeed);
	skeleton.moveParticles(particles);

	return done;
}

void Game::Render()
{
	win.clear();
	if(renderSkeleton){
		skeleton.draw(win);
	}
	
	//win.draw(testOBB);
	//win.draw(point);
	for(int i = 0; i < particles.size(); i++){
		win.draw(particles[i]);
	}

	win.display();
}

void Game::HandleEvents()
{
	sf::Event event;
	while (win.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			win.close();
			done = true;
		}
		if(event.type == sf::Event::MouseWheelMoved){
			testOBB.rotate((float)event.mouseWheel.delta * 0.1f);
			deltaTimeSpeed += ((float)event.mouseWheel.delta * 0.1f);
			if(deltaTimeSpeed < 0){
				deltaTimeSpeed = 0;
			}
		}
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N){
			renderSkeleton = !renderSkeleton;
		}
		//if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
		//	particles.push_back(Particle(sf::Color(random::getRandomInt(10,255),random::getRandomInt(10,255),random::getRandomInt(10,255)),sf::Vector2f(sf::Mouse::getPosition(win))));
		//	std::cout << "x: " << sf::Mouse::getPosition(win).x << std::endl;
		//	std::cout << "y: " << sf::Mouse::getPosition(win).y << std::endl;
		//}
	}
}
