﻿#include "Player.h"

USING_NS_CC;

bool Player::init()
{
    return true;
}

Player::~Player()
{
    m_UnitList.clear();
    m_TowerList.clear();
    m_StructureList.clear();
}
