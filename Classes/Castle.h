#ifndef __CASTLE_H__
#define __CASTLE_H__

#include "Object.h"
#include "Player.h"

class Castle : public custom::Object
{
public:
    virtual bool init();
    CREATE_FUNC(Castle);

    virtual void    SetDef(const std::string& filename);
    virtual void    SetDef(const DefInfo& info);
    virtual void    Damaged(int damage);
    virtual void    Death();

    inline void     PushUnit(const Player::DefInfoList& type) { m_UnitQueue.push(type); }
    void            CreateUnit();

protected:
    std::queue<Player::DefInfoList> m_UnitQueue;
};

#endif  // __CASTLE_H__
