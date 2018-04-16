#ifndef BASEUNIT_H
#define BASEUNIT_H
class BaseUnit
{
protected:
	BaseUnit();
	int getLife();
	int getDamage();

private:
	int life;
	int damage;
};
#endif