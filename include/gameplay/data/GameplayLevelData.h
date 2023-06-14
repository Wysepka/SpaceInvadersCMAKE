#pragma once
#include <stdint.h>

struct GameplayLevelData {
public:
	uint16_t mLevelID;
	EnemyData[] mEnemies;
};

struct EnemyData {
public:
	enum EnemyType { Small, Medium };
	EnemyType mEnemyType;
	float mEnemyHealth;
};