//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/monster.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void testMaxHitPoints(int value)
{
    "monster"::setMaxHitPoints(value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testMaxSpellPoints(int value)
{
    "monster"::setMaxSpellPoints(value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void testMaxStaminaPoints(int value)
{
    "monster"::setMaxStaminaPoints(value);
}
