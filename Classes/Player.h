#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Unit.h"
#include "Tower.h"
#include "Structure.h"


class Player : public cocos2d::Ref
{
public:
    enum Type
    {
        PT_NONE,
        PT_HUMAN,
        PT_COMPUTER,
    };
    enum Team
    {
        TEAM_NONE,
        TEAM_A,
        TEAM_B,
    };
    enum UnitList
    {
        UNIT_NONE,
        UNIT_A,
        UNIT_B,
        UNIT_C,
        UNIT_D,
    };
    enum TowerList
    {
        TOWER_NONE,
        TOWER_A,
        TOWER_B,
        TOWER_C,
        TOWER_D,
    };
    enum StructureList
    {
        STRUCTURE_NONE,
        STRUCTURE_A,
        STRUCTURE_B,
        STRUCTURE_C,
        STRUCTURE_D,
    };
public:
    virtual bool init();
    CREATE_FUNC(Player);
    virtual ~Player();

    inline void         SetType(const Type& type){ m_Type = type; }
    inline void         SetTeam(const Team& team){ m_Team = team; }
    inline Type         GetType() const { return m_Type; }
    inline Team         GetTeam() const { return m_Team; }

    inline void         SetUnit(const UnitList& key, Unit* unit){ m_UnitList.insert(key, unit); }
    inline void         SetTower(const TowerList& key, Tower* tower){ m_TowerList.insert(key, tower); }
    inline void         SetStructure(const StructureList& key, Structure* structure){ m_StructureList.insert(key, structure); }
    inline Unit*        GetUnit(const UnitList& key) const { auto iter = m_UnitList.find(key); return iter != m_UnitList.end() ? iter->second : nullptr; }
    inline Tower*       GetTower(const TowerList& key) const { auto iter = m_TowerList.find(key); return iter != m_TowerList.end() ? iter->second : nullptr; }
    inline Structure*   GetStructure(const StructureList& key) const { auto iter = m_StructureList.find(key); return iter != m_StructureList.end() ? iter->second : nullptr; }

protected:
    Type m_Type = PT_NONE;
    Team m_Team = TEAM_NONE;
    
    cocos2d::Map<UnitList, Unit*>           m_UnitList;
    cocos2d::Map<TowerList, Tower*>         m_TowerList;
    cocos2d::Map<StructureList, Structure*> m_StructureList;
};

#endif  // __PLAYER_H__
