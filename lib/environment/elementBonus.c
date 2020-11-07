//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";

private mapping environmentList = ([]);
private object owningElement;
private string bonusName;
private int bonusValue;
private int isSetUp = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setup(string name, int value, object owner)
{
    if (!isSetUp)
    {
        if(getDictionary("bonuses")->isValidBonus(name))
        {
            owningElement = owner;
            bonusName = name;
            bonusValue = value;
            isSetUp = 1;
        }
        else
        {
            raise_error(sprintf("EnvironmentalElement: The bonus %O must "
                "be valid as specified in bonusesDictionary.\n", name));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void setupBonus(object environment)
{
    if (objectp(environment))
    {
        environmentList[environment] = bonusValue;
    }
    else
    {
        foreach(object listedEnvironment in
            m_indices(environmentList))
        {
            environmentList[listedEnvironment] = bonusValue;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canApplyBonusToEnvironment(object environment, object actor,
    object target)
{
    return objectp(environment) && member(environmentList, environment) &&
        canApplySpecification(bonusName, actor, target);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string name()
{
    return bonusName;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int value()
{
    return bonusValue;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addToLimitors(string key, mixed value)
{
    if (!member(specificationData, "limited by"))
    {
        specificationData["limited by"] = ([]);
    }

    if (!pointerp(value))
    {
        value = ({ value });
    }

    if (validLimitor(([key:value])))
    {
        if (!member(specificationData["limited by"], key))
        {
            specificationData["limited by"][key] = value;
        }
        else
        {
            specificationData["limited by"][key] += value;
        }
        specificationData["limited by"][key] =
            m_indices(mkmapping(specificationData["limited by"][key]));
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: A valid %s must be "
            "specified.\n", key));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitBonusBySeason(string season)
{
    addToLimitors("season", season);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitBonusByTimeOfDay(string timeOfDay)
{
    addToLimitors("time of day", timeOfDay);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitBonusByMoonPhase(string moonPhase)
{
    addToLimitors("moon phase", moonPhase);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitBonusByState(string state)
{
    addToLimitors("environment state", state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitBonusByEquipment(string tool)
{
    addToLimitors("equipment", tool);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitBonusByOneOfEquipment(string *tools)
{
    addToLimitors("equipment", tools);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitBonusBySkill(string skill, int value)
{
    if (!member(specificationData, "limited by"))
    {
        specificationData["limited by"] = ([]);
    }

    if (validLimitor((["skill": ([ skill: value ]) ])))
    {
        if (!member(specificationData["limited by"], "skill"))
        {
            specificationData["limited by"]["skill"] = ([ skill: value ]);
        }
        else
        {
            specificationData["limited by"]["skill"] += ([ skill: value ]);
        }
    }
    else
    {
        raise_error("EnvironmentalElement: A valid skill and value "
            "must be specified.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask string capitalizeName()
{
    string *words = explode(bonusName, " ");
    int size = sizeof(words);
    for (int i = 0; i < size; i++)
    {
        words[i] = capitalize(words[i]);
    }

    return implode(words, " ");
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getBonusStatistics(object environment, object user)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();
    object configuration = getDictionary("configuration");

    string ret = configuration->decorate("Name: ", "field header",
            "element bonuses", colorConfiguration) +
        configuration->decorate(capitalizeName(), "field data",
            "element bonuses", colorConfiguration) + "\n";

    int value = member(environmentList, environment) ?
        environmentList[environment] : bonusValue;

    ret += (value > 0) ?
        configuration->decorate(
            sprintf("There is a +%d bonus to %s active.\n",
                value, bonusName),
            "bonus", "element bonuses", colorConfiguration) :
        configuration->decorate(
            sprintf("There is a %d penalty to %s active.\n",
                value, bonusName),
            "penalty", "element bonuses", colorConfiguration);

    ret += displayLimiters(colorConfiguration, configuration, 1);
    return format(ret, 78);
}
