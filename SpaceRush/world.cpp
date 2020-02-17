#include "world.h"

World::World(sf::RenderWindow& window):window(window),firstPlayer(true),secondPlayer(true)
{
	textures.load(Textures::Asteriods, "Assets/asteriod.png");
	textures.load(Textures::Player1Aircraft, "Assets/player1aircraft.png");
	textures.load(Textures::Player1Fire, "Assets/player1fire.png");
	textures.load(Textures::Player1Missile, "Assets/player1missile.png");
	textures.load(Textures::FinishLine, "Assets/finishline.png");

	firstPlayerSprite.push_back(sf::Sprite((textures.get(Textures::Player1Aircraft))));
	firstPlayerSprite.push_back(sf::Sprite((textures.get(Textures::Player1Fire))));
	firstPlayerSprite.push_back(sf::Sprite((textures.get(Textures::Player1Missile))));

	firstPlayerSprite[0].setPosition({ 800,800 });
	firstPlayerSprite[0].scale({ 0.3,0.3 });

	asteriod.setTexture(textures.get(Textures::Asteriods));
	asteriod.setPosition({ 100,100 });
	asteriod.scale({ 0.3,0.3 });

	finishLine.setTexture(textures.get(Textures::FinishLine));
	finishLine.setPosition({0,-200});
}
void World::update(sf::Time dt)
{
	time = dt;
}
void World::moveAircraft(float x, float y)
{
	firstPlayerSprite[0].move(x, y);
	mWorldView.move(0.f, y *time.asSeconds()*50);
}
sf::Vector2f World::getPositionAircraft()
{
	return firstPlayerSprite[0].getPosition();
}
int World::checkGameStatus()
{
	if (firstPlayerSprite[0].getGlobalBounds().intersects(finishLine.getGlobalBounds()) || secondPlayer == false)
		return 1;
	else if (firstPlayer==false)
		return 2;
}
void World::draw()
{
	
	window.setView(mWorldView);
	window.draw(finishLine);
	window.draw(firstPlayerSprite[0]);
	window.draw(asteriod);
	window.display();
}