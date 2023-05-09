//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";
virtual inherit "/lib/modules/conversations.c";
virtual inherit "/lib/modules/crafting.c";

protected object leader;

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfNpc()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setLeader(object player, int doNotJoinParty)
{
    if (objectp(player))
    {
        leader = player;

        if (!doNotJoinParty)
        {
            object partyDictionary = getDictionary("party");
            if (!leader->getParty())
            {
                partyDictionary->createParty(
                    sprintf("%s's Party", capitalize(leader->RealName())), leader);
            }

            object partyObj = leader->getParty();
            if (partyObj)
            {
                partyObj->addNPC(this_object());
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string leaderName()
{
    return objectp(leader) ? leader->RealName() : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string partyName()
{
    string ret = 0;
    if (leader)
    {
        ret = leader->partyName() ? leader->partyName() : leader->RealName();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty()
{
    object ret = this_object();
    if (leader && leader->getParty())
    {
        ret = leader->getParty();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getFollowerData()
{
    return save_object(2);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int restoreFollowerData(string data)
{
    return restore_object(data);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canAttack(object initiator)
{
    object *party = getParty()->members(1);

    return (initiator != leader) && 
        (!party || (member(party, initiator) < 0)) &&
        (objectp(leader) ? leader->onKillList() : 1);
}
