//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environmental-elements/core.c";

protected mapping harvestData = ([]);

/////////////////////////////////////////////////////////////////////////////
protected nomask string getHarvestedDescriptions(object environment)
{
    string ret = 0;

    object *harvestItems = m_values(
        filter(harvestData, (: (($1 == $2->name()) && 
            $2->harvestedDescription($3)) :), environment));

    if (sizeof(harvestItems))
    {
        string *descriptions = ({});
        foreach(object item in harvestItems)
        {
            descriptions += 
                ({ item->harvestedDescription(environment) });
        }
        ret = implode(descriptions, " ");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void harvestableResource(string name, int quantity,
    string resourceFile, string harvestedDescription, string *aliases)
{
    if (load_object(resourceFile))
    {
        if (!member(harvestData, name))
        {
            object resource =
                clone_object("/lib/environment/harvestableResource.c");
            resource->setup(name, quantity, resourceFile, harvestedDescription,
                aliases, this_object());
            harvestData[name] = resource;

            if (pointerp(aliases) && sizeof(aliases))
            {
                foreach(string alias in aliases)
                {
                    if (member(harvestData, alias))
                    {
                        raise_error(sprintf("EnvironmentalElement: The alias "
                            "of the harvestable resource (%O) is already in use.\n",
                            alias));
                    }
                    else
                    {
                        harvestData[alias] = resource;
                    }
                }
            }
        }
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: The resource %O must "
            "exist and be clonable.\n", resourceFile));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestBySeason(string name, string season)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestBySeason(season);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a season.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestByTimeOfDay(string name, string timeOfDay)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByTimeOfDay(timeOfDay);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a time of day.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestByMoonPhase(string name, string moonPhase)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByMoonPhase(moonPhase);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a time of day.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestByState(string name, string state)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByState(state);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void limitHarvestBySkill(string name, string skill,
    int value)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestBySkill(skill, value);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a state.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void harvestRequiresTool(string name, string tool)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByTool(tool);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a required tool.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void harvestRequiresOneOfTool(string name, string *tools)
{
    if (member(harvestData, name) && objectp(harvestData[name]))
    {
        harvestData[name]->limitHarvestByOneOfTools(tools);
    }
    else
    {
        raise_error(sprintf("EnvironmentalElement: Unknown resource (%O).\n"
            "It must be added via the harvestableResource(...) method before "
            "adding a required tool.\n", name));
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isHarvestableResource(string resource, object environment,
    object user)
{
    int ret = 0;
    if (member(harvestData, resource) && objectp(harvestData[resource]) &&
        objectp(environment))
    {
        ret = harvestData[resource]->isHarvestableResource(resource,
            user, environment);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string *harvestableResources(int noAliases)
{
    string *ret = noAliases ?
        m_indices(filter(harvestData, (: $1 == $2->name() :))) :
        m_indices(harvestData);

    return sizeof(ret) ? ret : 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object harvestResource(string resource, object user,
    object environment)
{
    object ret = 0;

    if (member(harvestData, resource))
    {
        ret = harvestData[resource]->harvestResource(resource,
            user, environment);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string getHarvestStatistics(object user,
    object environment, string item)
{
    string ret = "";

    if (member(harvestData, item) && objectp(harvestData[item]))
    {
        ret = harvestData[item]->getHarvestStatistics(environment, user);
    }
    else if (!item)
    {
        object *harvestItems = m_values(
            filter(harvestData, (: $1 == $2->name() :)));

        if (sizeof(harvestItems))
        {
            foreach(object harvestItem in sort_array(harvestItems, (: $1->name() > $2->name() :)))
            {
                ret += harvestItem->getHarvestStatistics(environment, user) + 
                    "\n";
            }
        }
    }
    return ret;
}
