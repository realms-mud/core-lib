//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping limitors = (["limited by": ([]) ]);

/////////////////////////////////////////////////////////////////////////////
private nomask void addToLimitors(string key, mixed value)
{
    if (!pointerp(value))
    {
        value = ({ value });
    }

    if (getDictionary("limitor")->validLimitor(([key:value])))
    {
        if (!member(limitors["limited by"], key))
        {
            limitors["limited by"][key] = value;
        }
        else
        {
            limitors["limited by"][key] += value;
        }
        limitors["limited by"][key] = 
            m_indices(mkmapping(limitors["limited by"][key]));
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: A valid %s must be "
            "specified.\n", key));
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addToLimitorsWithSubMapping(string topLevelKey,
    string subKey, int value)
{
    if (getDictionary("limitor")->validLimitor(
        ([topLevelKey:([subKey:value])])))
    {
        if (!member(limitors["limited by"], topLevelKey))
        {
            limitors["limited by"][topLevelKey] = ([subKey:value]);
        }
        else
        {
            limitors["limited by"][topLevelKey] += ([subKey:value]);
        }
    }
    else
    {
        raise_error("EnvironmentalElement: A valid skill and value "
            "must be specified.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addIntValueToLimitors(string key, int value)
{
    if (getDictionary("limitor")->validLimitor(([key:value])))
    {
        limitors["limited by"][key] = value;
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: A valid %s must be "
            "specified.\n", key));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayBySeason(string season)
{
    addToLimitors("season", season);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByTimeOfDay(string timeOfDay)
{
    addToLimitors("time of day", timeOfDay);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByMoonPhase(string moonPhase)
{
    addToLimitors("moon phase", moonPhase);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByState(string state)
{
    addToLimitors("environment state", state);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByEquipment(string tool)
{
    addToLimitors("equipment", tool);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByOneOfEquipment(string *tools)
{
    addToLimitors("equipment", tools);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayBySkill(string skill, int value)
{
    addToLimitorsWithSubMapping("skill", skill, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByAttribute(string attribute, int value)
{
    addToLimitorsWithSubMapping("attribute", attribute, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByQuest(string quest)
{
    addToLimitors("quests", quest);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByResearch(string research)
{
    addToLimitors("research", research);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByTrait(string trait)
{
    addToLimitors("traits", trait);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByResearchThatIsActive(string research)
{
    addToLimitors("research active", research);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByIntoxication(int value)
{
    addIntValueToLimitors("intoxicated", value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByDrugEffect(int value)
{
    addIntValueToLimitors("drugged", value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByNearnessToDeath(int value)
{
    addIntValueToLimitors("near death", value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayBySpellPointsDrained(int value)
{
    addIntValueToLimitors("spell points drained", value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitDisplayByStaminaDrained(int value)
{
    addIntValueToLimitors("stamina drained", value);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int elementIsAvailable(object user)
{
    int ret = 1;

    if (objectp(user) && sizeof(limitors))
    {
        object dictionary = getDictionary("limitor");
        ret &&= dictionary->environmentalFactorsMet(limitors, user) &&
            dictionary->userFactorsMet(limitors, user);
    }
    return ret;
}
