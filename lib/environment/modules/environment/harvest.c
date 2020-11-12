//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping harvestData = ([]);

/////////////////////////////////////////////////////////////////////////////
protected nomask void addHarvestInformation(object environmentalElement)
{
    string *resources = environmentalElement->harvestableResources();
    if (sizeof(resources))
    {
        foreach(string resource in resources)
        {
            if (!member(harvestData, resource))
            {
                harvestData[resource] = ({});
            }
            harvestData[resource] += ({ environmentalElement });
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask object harvestResource(string resource, object user)
{
    object ret = 0;

    if (member(harvestData, resource) && sizeof(harvestData[resource]))
    {
        foreach(object element in harvestData[resource])
        {
            if (objectp(element) && element->elementIsAvailable(user))
            {
                ret = element->harvestResource(resource, user,
                    this_object());
                break;
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string harvestStatistics(object user, string item)
{
    string ret = 0;

    if (sizeof(harvestData))
    {
        ret = "";

        string *items = (item && member(harvestData, item)) ?
            ({ item }) : sort_array(m_indices(harvestData), (: $1 > $2 :));

        foreach(string resource in items)
        {
            foreach(object element in harvestData[resource])
            {
                if (objectp(element) && 
                    element->elementIsAvailable(user) &&
                    (member(element->harvestableResources(1), resource) > -1))
                {
                    ret += element->getHarvestStatistics(
                        user, this_object(), resource) + "\n";
                }
            }
        }
    }

    if (!ret)
    {
        ret = "There is nothing in this environment that can be harvested.\n";
    }
    return ret;
}
