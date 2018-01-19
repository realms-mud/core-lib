//*****************************************************************************
// Class: monster
// File Name: monster.c
//
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";

private nosave int EffectiveLevel;

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfMonster()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int effectiveLevel(int newLevel)
{
    if (newLevel)
    {
        EffectiveLevel = newLevel;
    }
    return EffectiveLevel;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int effectiveExperience()
{
    return 1000 + (1000 * EffectiveLevel * (EffectiveLevel + 1) / 2);
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        if (this_object()->Name() && (this_object()->Name() != ""))
        {
            set_living_name(this_object()->Name());
        }
        "living"::reset(arg);
    }
}