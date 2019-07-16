//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/living.c";
virtual inherit "/lib/modules/quests.c";
virtual inherit "/lib/modules/conversations.c";
virtual inherit "/lib/modules/crafting.c";
virtual inherit "/lib/modules/personas.c";
virtual inherit "/lib/modules/combatChatter.c";

private object Leader;
private string Location;
private string Type;
private string Activity = "idle";
private int RemovalTime = 0;
private int Cost = 0;

private nosave int EffectiveLevel;
private nosave float ExperiencePerHitPoint = 0;
private nosave int ExperiencePerHitPointSet = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfHenchman()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (arg)
    {
        return;
    }
    "living"::reset(arg);
    registerHeartBeat("henchman");
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
    call_direct(this_object(), "hitPoints",
        call_direct(this_object(), "maxHitPoints"));
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

/////////////////////////////////////////////////////////////////////////////
public nomask void setLeader(object player)
{
    Leader = player;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    if (Leader && Leader->getDomainType(location))
    {
        Location = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string location()
{
    return Location;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setActivity(string activity)
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (Leader && Leader->getDomainType(Location) &&
        dictionary->isValidActivity(Location, activity))
    {
        Activity = activity;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string activity()
{
    return Activity;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setType(string type)
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary->isValidHenchmanType(type))
    {
        Type = type;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string type()
{
    return Type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string partyName()
{
    string ret = 0;
    if (Leader)
    {
        ret = Leader->RealName();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getParty()
{
    object ret = this_object();
    if (Leader && Leader->getParty())
    {
        ret = Leader->getParty();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCost(int cost)
{
    if (cost > 0)
    {
        Cost = cost;
    }
    else
    {
        raise_error("Henchman: The cost must be a value greater than 0.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isHireling()
{
    return Cost > 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int cost()
{
    return Cost;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setHenchmanData(mapping data, object leader)
{
    Name(data["name"]);
    Gender(data["gender"] == "male" ? 1 : 2);
    if (member(data, "house"))
    {
        Title(data["house"]);
    }
    if (member(data, "pre-title"))
    {
        Pretitle(data["pre-title"]);
    }
    setLeader(leader);
    setLocation(data["location"]);
    SetUpPersonaOfLevel(data["persona"], data["level"]);
    setUpRandomEquipment(data["level"] * 2);
    setType(data["type"]);
    setActivity(data["activity"]);

    if (member(data, "cost") && intp(data["cost"]))
    {
        setCost(data["cost"]);
    }
    if (member(data, "duration") && intp(data["duration"]))
    {
        RemovalTime = Age() + data["duration"];
    }

    if (member(data, "skills") && mappingp(data["skills"]) &&
        sizeof(data["skills"]))
    {
        foreach(string skill in m_indices(data["skills"]))
        {
            addSkillPoints(advanceSkillCost(skill, data["skills"][skill]));
            advanceSkill(skill, data["skills"][skill]);
        }
    }

    if (member(data, "traits") && pointerp(data["traits"]) &&
        sizeof(data["traits"]))
    {
        foreach(string trait in data["traits"])
        {
            addTrait(trait);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask varargs void henchmanHeartBeat()
{
    if (Leader && Cost && (Age() >= RemovalTime))
    {
        Leader->removeHenchman(Location, short());
        Leader = 0;
    }
}
