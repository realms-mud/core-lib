//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environmental-elements/core.c";

protected mapping bonusData = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask int environmentalBonusTo(string state, object environment,
    string bonus, object actor, object target)
{
    int ret = 0;

    object *bonusItems = m_values(
        filter(bonusData, (: $2->name() == $3 :), bonus));

    if (sizeof(bonusItems))
    {
        foreach(object item in bonusItems)
        {
            if (item->canApplyBonusToEnvironment(environment, actor, target))
            {
                ret += item->value();
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *bonuses()
{
    return m_indices(bonusData);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBonusDescriptions(object environment,
    object user)
{
    string ret = 0;

    if (sizeof(bonusData))
    {
        string *descriptions = ({});
        foreach(object item in m_values(bonusData))
        {
            descriptions += 
                ({ item->getBonusStatistics(environment, user) });
        }
        ret = implode(descriptions, "\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs void addBonusValue(string bonusName, int value)
{
    if (getDictionary("bonuses")->isValidBonus(bonusName))
    {
        if (!member(bonusData, bonusName))
        {
            object bonus =
                clone_object("/lib/environment/elementBonus.c");
            bonus->setup(bonusName, value, this_object());
            bonusData[bonusName] = bonus;
        }
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: The bonus %O must "
            "be valid as specified in bonusesDictionary.\n", bonusName));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addBonus(string bonusName, int value)
{
    if (value > 0)
    {
        addBonusValue(bonusName, value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: The bonus %O must "
            "be greater than 0 (%d).\n", bonusName, value));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addPenalty(string bonusName, int value)
{
    if (value > 0)
    {
        addBonusValue(bonusName, 0 - value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: The penalty %O must "
            "be greater than 0 (%d).\n", bonusName, value));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusBySeason(string name, string season)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusBySeason(season);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a season.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyBySeason(string name, string season)
{
    limitBonusBySeason(name, season);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByTimeOfDay(string name, string timeOfDay)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByTimeOfDay(timeOfDay);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a time of day.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByTimeOfDay(string name, string timeOfDay)
{
    limitBonusByTimeOfDay(name, timeOfDay);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByMoonPhase(string name, string moonPhase)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByMoonPhase(moonPhase);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a time of day.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByMoonPhase(string name, string moonPhase)
{
    limitBonusByMoonPhase(name, moonPhase);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByState(string name, string state)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByState(state);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByState(string name, string state)
{
    limitBonusByState(name, state);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByAttribute(string name, string attribute,
    int value)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByAttribute(attribute, value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByAttribute(string name, string attribute,
    int value)
{
    limitBonusByAttribute(name, attribute, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusBySkill(string name, string skill,
    int value)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusBySkill(skill, value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyBySkill(string name, string skill,
    int value)
{
    limitBonusBySkill(name, skill, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void bonusRequiresEquipment(string name, string tool)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByEquipment(tool);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a required tool.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void penaltyRequiresEquipment(string name, string tool)
{
    bonusRequiresEquipment(name, tool);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void bonusRequiresOneOfEquipment(string name, string *tools)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByOneOfEquipment(tools);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a required tool.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void penaltyRequiresOneOfEquipment(string name, string *tools)
{
    bonusRequiresOneOfEquipment(name, tools);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByIntoxication(string name, int value)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByIntoxication(value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByIntoxication(string name, int value)
{
    limitBonusByIntoxication(name, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByDrugEffect(string name, int value)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByDrugEffect(value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByDrugEffect(string name, int value)
{
    limitBonusByDrugEffect(name, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByNearnessToDeath(string name, int value)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByNearnessToDeath(value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByNearnessToDeath(string name, int value)
{
    limitBonusByNearnessToDeath(name, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusBySpellPointsDrained(string name, int value)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusBySpellPointsDrained(value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyBySpellPointsDrained(string name, int value)
{
    limitBonusBySpellPointsDrained(name, value);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitBonusByStaminaDrained(string name, int value)
{
    if (member(bonusData, name) && objectp(bonusData[name]))
    {
        bonusData[name]->limitBonusByStaminaDrained(value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown bonus (%O).\n"
            "It must be added via the addBonus(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitPenaltyByStaminaDrained(string name, int value)
{
    limitBonusByStaminaDrained(name, value);
}
