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
    string harvestedDescription, object owner)
{
    if (load_object(resourceFile))
    {
        owningElement = owner;
        harvestData = ([
            "name": name,
            "initial quantity": quantity,
            "available quantity": ([]),
            "resource file": resourceFile,
            "description when harvested": harvestedDescription,
        ]);
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
public nomask string name()
{
    return harvestData["name"];
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
protected nomask void limitHarvestByTool(string tool)
{
    addToLimitors("equipment", tool);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestByOneOfTools(string *tools)
{
    addToLimitors("equipment", tools);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isHarvestableResource(string resource, object environment)
{
    int ret = 0;
    if (member(harvestData, resource) && objectp(environment))
    {
        string key = member(harvestData[resource], "alias") ?
            harvestData[resource]["alias"] : resource;

        if (member(harvestData[key], "limited to state") &&
            sizeof(harvestData[key]["limited to state"]))
        {
            ret = member(harvestData[key]["limited to state"], 
                owningElement->currentState()) > -1;
        }
        else
        {
            ret = 1;
        }

        ret &&= (member(harvestData[key]["available quantity"], environment) &&
            (harvestData[key]["available quantity"][environment] > 0));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *harvestableResources()
{
    return sizeof(harvestData) ? m_indices(harvestData) : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object harvestResource(string resource, object environment)
{
    object ret = 0;

    if (member(harvestData, resource))
    {
        string key = member(harvestData[resource], "alias") ?
            harvestData[resource]["alias"] : resource;

        if (isHarvestableResource(key, environment))
        {
            harvestData[key]["available quantity"][environment] -= 1;
            ret = clone_object(harvestData[key]["resource file"]);

            if (member(harvestData[key], "description when harvested"))
            {
                HarvestedDescription =
                    harvestData[key]["description when harvested"];
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getHarvestStatistics(object user)
{
    return "";
}
