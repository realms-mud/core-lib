//*****************************************************************************
// Class: monster
// File Name: monster.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";

private nosave int EffectiveLevel;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

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
        Setup();
        if (this_object()->Name() && (this_object()->Name() != ""))
        {
            set_living_name(this_object()->Name());
        }
        "living"::reset(arg);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setMaxHitPoints(int value)
{
    maxHitPoints = value;
    call_direct(this_object(), "hitPoints", maxHitPoints);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setMaxSpellPoints(int value)
{
    maxSpellPoints = value;
    call_direct(this_object(), "spellPoints", maxSpellPoints);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setMaxStaminaPoints(int value)
{
    maxStaminaPoints = value;
    call_direct(this_object(), "staminaPoints", maxStaminaPoints);
}
