#include "enemy.h"

Enemy::Enemy() : GameObject(), action(0), waitTime(0) {

}

void Enemy::init(int x, int y, int z, RECT bounds_, int type_, int midX, int midY, int endX, int endY, int life_, float speed_) {
	this->GameObject::init(x,y,z,bounds_,type_, speed_);
	mid.x = midX;
	mid.y = midY;
	mid.z = 0;
	end.x = endX;
	end.y = endY;
	end.z = 0;
	life = life_;
}

void Enemy::wait() {
	waitTime++;
}

void Enemy::waitAt(int time, int pos) {
	if (this->getPos(1) >= pos)
		if (this->getWaitTime() < time) 
			waitTime++;
}

int Enemy::getWaitTime() {
	return waitTime;
}

void Enemy::setWaitTime(int time) {
	waitTime = time;
}

int Enemy::getCooldown() {
	return cooldown;
}

void Enemy::setCooldown(int time) {
	cooldown = time;
}

int Enemy::getAction() {
	return action;
}

void Enemy::setAction(int command) {
	action = command;
}

float Enemy::getLife() {
	return life;
}

void Enemy::setLife(float value) {
	life = value;
}

D3DXVECTOR3 Enemy::getMid() {
	return mid;
}

void Enemy::setMid(D3DXVECTOR3 _mid) {
	mid = _mid;
}

D3DXVECTOR3 Enemy::getEnd() {
	return end;
}

void Enemy::setEnd(D3DXVECTOR3 _end) {
	end = _end;
}

void Enemy::aimFire(Bullet* enemyBullets, D3DXVECTOR3 targetPos, D3DXVECTOR3 startPos, int size, int owner, RECT bounds, int type_) {
	for (int i=0; i < size; i++) {
		if (!enemyBullets[i].isActive()) {
			enemyBullets[i].setActive(true);
			enemyBullets[i].setBounds(bounds);
			enemyBullets[i].setOwner(owner);
			enemyBullets[i].setType(type_);
			enemyBullets[i].setStartPos(startPos);
			enemyBullets[i].setPos(startPos.x, startPos.y, startPos.z);
			D3DXVECTOR3 target = D3DXVECTOR3(targetPos.x - this->getPos(0), targetPos.y - this->getPos(1), 0);
			//D3DXVec3Normalize(&target, &target);
			enemyBullets[i].setTarget(targetPos);
			break;
		}
	}
}
