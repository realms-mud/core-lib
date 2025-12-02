//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/services/domains/sub-services/core.c";

/////////////////////////////////////////////////////////////////////////////
private nomask float getCommanderBonus(object unit, string type)
{
    return 0.0;
}

/////////////////////////////////////////////////////////////////////////////
private nomask float getOwnerBonus(object unit, string type)
{
    return 0.0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask float getDefenseBonus(object unit, object target)
{
    return 1.0 + getCommanderBonus(unit, "defense") +
        getOwnerBonus(unit, "defense") -
        getCommanderBonus(target, "defense") -
        getOwnerBonus(target, "defense");
}

/////////////////////////////////////////////////////////////////////////////
public nomask float getAttackBonus(object unit, object target)
{
    return 1.0 + getCommanderBonus(unit, "attack") +
        getOwnerBonus(unit, "attack") -
        getCommanderBonus(target, "attack") -
        getOwnerBonus(target, "attack");
}

/////////////////////////////////////////////////////////////////////////////
public nomask float getDamageBonus(object unit, object target)
{
    return 1.0 + getCommanderBonus(unit, "damage") +
        getOwnerBonus(unit, "damage") -
        getCommanderBonus(target, "damage") -
        getOwnerBonus(target, "damage");
}

/////////////////////////////////////////////////////////////////////////////
public nomask float getHealthBonus(object unit, object target)
{
    return 1.0 + getCommanderBonus(unit, "health") +
        getOwnerBonus(unit, "health") -
        getCommanderBonus(target, "health") -
        getOwnerBonus(target, "health");
}
