//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/domains/sub-dictionaries/core.c";

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
