//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/personas.c";
virtual inherit "/lib/modules/combatChatter.c";

private nosave int EffectiveLevel;
private nosave float ExperiencePerHitPoint = 0;
private nosave int ExperiencePerHitPointSet = 0;

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
public varargs string Name(string newName)
{
    string ret = living::Name(newName);
    if (newName && (ret == newName))
    {
        addLiving(this_object());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    living::create();
    if (this_object()->Name() && (this_object()->Name() != ""))
    {
        addLiving(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
private void calculateExperiencePerHitPoint(int totalHP)
{
    ExperiencePerHitPoint = (1.0 * effectiveExperience()) / 
        (totalHP * 125.0);

    ExperiencePerHitPointSet = 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void getExperienceFromHit(int damage, object foe)
{
    if (damage && objectp(foe))
    {
        if (!ExperiencePerHitPointSet)
        {
            calculateExperiencePerHitPoint(
                call_direct(this_object(), "maxHitPoints"));
        }

        int experienceToAdd = to_int(ExperiencePerHitPoint * damage /
            foe->effectiveLevel());

        foe->addExperience(experienceToAdd ? experienceToAdd : 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxHitPoints(int value)
{
    maxHitPoints = value;
    call_direct(this_object(), "resetCaches");

    int totalHitPoints = call_direct(this_object(), "maxHitPoints");

    call_direct(this_object(), "hitPoints", totalHitPoints);
    calculateExperiencePerHitPoint(totalHitPoints);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxSpellPoints(int value)
{
    maxSpellPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "spellPoints",
        call_direct(this_object(), "maxSpellPoints"));
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setMaxStaminaPoints(int value)
{
    maxStaminaPoints = value;
    call_direct(this_object(), "resetCaches");
    call_direct(this_object(), "staminaPoints",
        call_direct(this_object(), "maxStaminaPoints"));
}
