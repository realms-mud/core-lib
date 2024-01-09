//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/specification.c";

protected mapping harvestData = ([ ]);
private string HarvestedDescription = 0;
private object owningElement;
private int isSetUp = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask void setup(string name, int quantity, string resourceFile, 
    string harvestedDescription, string *aliases, object owner)
{
    if (!isSetUp)
    {
        object resourceObj;
        catch (resourceObj = load_object(resourceFile));
        if (resourceObj && stringp(name) && sizeof(name) &&
            (member(inherit_list(resourceObj), "/lib/items/item.c") > -1))
        {
            owningElement = owner;
            harvestData = ([
                "name":name,
                "initial quantity" : quantity,
                "available quantity" : ([]),
                "resource file" : resourceFile,
                "description when harvested" : harvestedDescription
            ]);

            if (sizeof(aliases))
            {
                harvestData["aliases"] = aliases;
            }
            isSetUp = 1;
        }
        else
        {
            raise_error(sprintf("EnvironmentalElement: The resource %O must "
                "exist and be clonable.\n", resourceFile));
        }
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
public nomask varargs int isHarvestableResource(string resource, object user,
    object environment, int displayMessage)
{
    int quantityExists =
        member(harvestData["available quantity"], environment) &&
        (harvestData["available quantity"][environment] > 0);
    if (displayMessage && !quantityExists)
    {
        object configuration = getDictionary("configuration");

        write(configuration->decorate(
            sprintf("There is currently no %O available to harvest.\n",
                resource),
            "missing prerequisites", "research", user->colorConfiguration()));
    }

    return hasNameOf(resource) && quantityExists &&
        environmentalFactorsMet(user, displayMessage);
}

/////////////////////////////////////////////////////////////////////////////
public nomask object harvestResource(string resource, object user,
    object environment)
{
    object ret = 0;

    if (isHarvestableResource(resource, user, environment, 1) &&
        userFactorsMet(user, user, 1))
    {
        harvestData["available quantity"][environment] -= 1;

        ret = present_clone(harvestData["resource file"], user);
        if (ret)
        {
            ret->set("quantity", ret->query("quantity") + 1);
        }
        else
        {
            ret = clone_object(harvestData["resource file"]);
            ret->set("quantity", 1);
        }

        if (member(harvestData, "description when harvested"))
        {
            HarvestedDescription =
                harvestData["description when harvested"];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string harvestedDescription(object environment)
{
    return (member(harvestData["available quantity"], environment) &&
        (harvestData["available quantity"][environment] <
        harvestData["initial quantity"])) ?
        harvestData["description when harvested"] : 0;
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

    if (member(harvestData, "aliases"))
    {
        ret += configuration->decorate("Alias(es): ", "field header",
                "harvestable resources", colorConfiguration) +
            configuration->decorate(implode(harvestData["aliases"], ", "), 
                "field data", "harvestable resources", 
                colorConfiguration) + "\n";
    }
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
