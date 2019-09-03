//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private object regionDictionary = 
    load_object("/lib/dictionaries/regionDictionary.c");

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomEnvironmentalElements(mapping elements, 
    string state)
{
    foreach(string feature in m_indices(elements["features"]))
    {
        foreach(string direction in elements["features"][feature])
        {
            addFeature(feature, direction, state);
        }
    }

    foreach(string item in m_indices(elements["items"]))
    {
        foreach(string direction in elements["items"][item])
        {
            addItem(item, direction, state);
        }
    }

    if (member(elements, "shop"))
    {
        addShop(elements["shop"]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomObjects(mapping items, string state)
{
    foreach(string item in m_indices(items))
    {
        addObject(items[item], state);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addRandomCreature(mapping creatures, string state)
{
    foreach(string creature in m_indices(creatures))
    {
        addObject(creatures[creature], state);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void addGeneratedExits(mapping exits, object region, 
    string state)
{
    if (mappingp(exits) && sizeof(exits))
    {
        foreach(string direction in m_indices(exits))
        {
            mapping exit = exits[direction];
            if (member(exit, "building"))
            {
                addGeneratedBuilding(exit["building"], direction,
                    exit["exit to"], region, exit["door"], exit["key"], state);
                addFeature(exit["path type"], direction, state);
            }
            else
            {
                addGeneratedExit(direction, exit["exit to"], region, state);
                addFeature(exit["path type"], direction, state);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void generateEnvironment(mapping data, object region, 
    string state)
{
    if (mappingp(data))
    {
        mapping roomData =
            regionDictionary->generateRoomData(region, data);

        if (roomData)
        {
            if (member(roomData, "terrain"))
            {
                setTerrain(roomData["terrain"]);
            }
            else
            {
                setInterior(roomData["interior"]);
            }

            setCoordinates(region->regionName(), data["x"], data["y"]);
            addGeneratedExits(roomData["exits"], region, state);

            addRandomEnvironmentalElements(roomData, state);
            addRandomObjects(roomData["room objects"], state);
            addRandomCreature(roomData["creatures"], state);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void addEntryExit(string direction, string location)
{
    addExit(direction, location);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string getCoordinates()
{
    return sprintf("%dx%d", xCoordinate, yCoordinate);
}
