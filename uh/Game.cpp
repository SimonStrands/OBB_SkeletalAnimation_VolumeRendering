#include "Game.h"

Game::Game():
	win(sf::VideoMode(800, 600), "SFML window"),
	point(sf::Color::Red, sf::Vector2f(0,0)),
	testOBB(sf::Vector2f(50,50), sf::Vector2f(100,20), 0)
{
	done = false;
	for(int i = 0; i < 30; i++){
		particles.push_back(Particle(sf::Color(random::getRandomInt(10,255),random::getRandomInt(10,255),random::getRandomInt(10,255)), sf::Vector2f(random::getRandomInt(0,400) + 200, random::getRandomInt(0,200) + 200)));
	}
	buildTestAnimation();
	buildTestSkeleton();
	this->skeleton.loadAnimation(testAnimation);
	this->skeleton.loadSkeleton(testSkeleton);
}

Game::~Game()
{

}

bool Game::Update(float dt)
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
		//point.changeOriginalPosition(sf::Vector2f(sf::Mouse::getPosition(win)));
		testOBB.setPos(sf::Vector2f(sf::Mouse::getPosition(win)));
	}
	for(int i = 0; i < particles.size(); i++){
		if(testOBB.pointInside(particles[i].getOrginalPosition())){
			std::cout << "Particle: " << i << ", is inside box" << std::endl;  
		}
	}
	testOBB.updateDebug();

	skeleton.update(dt);
	//skeleton.checkIfPointIsInSkeleton(point);

	return done;
}

void Game::Render()
{
	win.clear();

	for(int i = 0; i < particles.size(); i++){
		win.draw(particles[i]);
	}
	skeleton.draw(win);
	win.draw(testOBB);
	win.draw(point);

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
			testOBB.rotate(event.mouseWheel.delta);
		}
	}
}
