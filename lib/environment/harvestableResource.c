//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";

protected mapping harvestData = ([ ]);
private string HarvestedDescription = 0;
private object owningElement;

/////////////////////////////////////////////////////////////////////////////
public nomask void setup(string name, int quantity, string resourceFile, 
    string harvestedDescription, string *aliases, object owner)
{
    object resourceObj;
    catch (resourceObj = load_object(resourceFile));
    if (resourceObj && stringp(name) && sizeof(name) &&
        (member(inherit_list(resourceObj), "lib/items/item.c") > -1))
    {
        owningElement = owner;
        harvestData = ([
            "name": name,
            "initial quantity": quantity,
            "available quantity": ([]),
            "resource file": resourceFile,
            "description when harvested": harvestedDescription
        ]);

        if (sizeof(aliases))
        {
            harvestData["aliases"] = aliases;
        }
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: The resource %O must "
            "exist and be clonable.\n", resourceFile));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void resetQuantity(object environment)
{
    if (objectp(environment))
    {
        harvestData["available quantity"][environment] =
            harvestData["initial quantity"];
    }
    else
    {
        foreach(object listedEnvironment in
            m_indices(harvestData["available quantity"]))
        {
            harvestData["available quantity"][listedEnvironment] =
                harvestData["initial quantity"];
            HarvestedDescription = 0;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string description(object environment)
{
    return (member(harvestData["available quantity"], environment) &&
        (harvestData["initial quantity"] !=
            harvestData["available quantity"][environment]) &&
        member(harvestData, "description when harvested")) ?
        harvestData["description when harvested"] : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string name()
{
    return harvestData["name"];
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasNameOf(string name)
{
    return (harvestData["name"] == name) ||
        (member(harvestData, "aliases") && sizeof(harvestData["aliases"]) &&
        (member(harvestData["aliases"], name) > -1));
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addToLimitors(string key, mixed value)
{
    if (!member(researchData, "limited by"))
    {
        researchData["limited by"] = ([]);
    }

    if (!pointerp(value))
    {
        value = ({ value });
    }

    if (validLimitor(([key:value])))
    {
        if (!member(researchData["limited by"], key))
        {
            researchData["limited by"][key] = value;
        }
        else
        {
            researchData["limited by"][key] += value;
        }
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: A valid %s must be "
            "specified.\n", key));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitHarvestBySeason(string season)
{
    addToLimitors("season", season);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitHarvestByTimeOfDay(string timeOfDay)
{
    addToLimitors("time of day", timeOfDay);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitHarvestByMoonPhase(string moonPhase)
{
    addToLimitors("moon phase", moonPhase);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitHarvestByState(string state)
{
    addToLimitors("environment state", state);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitHarvestByTool(string tool)
{
    addToLimitors("equipment", tool);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitHarvestByOneOfTools(string *tools)
{
    addToLimitors("equipment", tools);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void limitHarvestBySkill(string skill, int value)
{
    if (!member(researchData, "limited by"))
    {
        researchData["limited by"] = ([]);
    }

    if (validLimitor((["skill": ([ skill: value ]) ])))
    {
        if (!member(researchData["limited by"], "skill"))
        {
            researchData["limited by"]["skill"] = ([ skill: value ]);
        }
        else
        {
            researchData["limited by"]["skill"] += ([ skill: value ]);
        }
    }
    else
    {
        raise_error("EnvironmentalElement: A valid skill and value "
            "must be specified.\n");
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isHarvestableResource(string resource, object user,
    object environment)
{
    return hasNameOf(resource) && 
        (member(harvestData["available quantity"], environment) &&
        (harvestData["available quantity"][environment] > 0)) &&
        environmentalFactorsMet(user);
}

/////////////////////////////////////////////////////////////////////////////
public nomask object harvestResource(string resource, object user,
    object environment)
{
    object ret = 0;

    if (isHarvestableResource(resource, user, environment) &&
        userFactorsMet(user, user))
    {
        harvestData["available quantity"][environment] -= 1;
        ret = clone_object(harvestData["resource file"]);

        if (member(harvestData, "description when harvested"))
        {
            HarvestedDescription =
                harvestData["description when harvested"];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string capitalizeName()
{
    string *words = explode(harvestData["name"], " ");
    int size = sizeof(words);
    for (int i = 0; i < size; i++)
    {
        words[i] = capitalize(words[i]);
    }

    return implode(words, " ");
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getHarvestStatistics(object environment, object user)
{
    string colorConfiguration = user->colorConfiguration();
    string charset = user->charsetConfiguration();
    object configuration = getDictionary("configuration");

    string ret = configuration->decorate("Name: ", "field header",
        "harvestable resources", colorConfiguration) +
        configuration->decorate(capitalizeName(), "field data",
            "harvestable resources", colorConfiguration) + "\n";

    if (member(harvestData["available quantity"], environment))
    {
        int quantity = harvestData["available quantity"][environment];
        ret += (quantity > 0) ?
            configuration->decorate(
                sprintf("There %s %d %s available for harvest.\n",
                    ((quantity != 1) ? "are" : "is"), quantity, 
                    harvestData["name"]), 
                "quantity left", "harvestable resources", colorConfiguration) :
            configuration->decorate(
                sprintf("There are currently no %s available for harvest.\n", 
                    harvestData["name"]),
                "quantity zero", "harvestable resources", colorConfiguration);
    }

    ret += displayLimiters(colorConfiguration, configuration, 1);
    ret = regreplace(ret, "This is only applied when",
        "This can only be harvested when", 1);

    return format(ret, 78);
}
