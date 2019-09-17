//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/regions/core.c";
virtual inherit "/lib/environment/regions/generate-room.c"; 

private int PersistRegion = 1;

/////////////////////////////////////////////////////////////////////////////
public nomask int persistRegion()
{
    return PersistRegion;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setPersistRegion(int persist)
{
    PersistRegion = persist;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int setRegionDetails(mapping regionData)
{
    EnterFrom = regionData["entry direction"];
    EntryPoint = regionData["entry point"];
    MaxX = regionData["x-dimension"];
    MaxY = regionData["y-dimension"];
    RegionName = regionData["name"];
    RegionType = regionData["type"];

    return stringp(EnterFrom) && stringp(EntryPoint) && stringp(RegionType);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int setRegionGrid(mapping regionData)
{
    int ret = 0;

    grid = regionData["grid"] + ([]);

    if (sizeof(grid))
    {
        int count = 0;
        foreach(int x in m_indices(grid))
        {
            foreach(string y in m_indices(grid[x]))
            {
                if (grid[x][y]["room type"] != "none")
                {
                    rooms += ({ grid[x][y] });
                }
                count++;
                if (grid[x][y]["room type"] == "entry")
                {
                    entry = ({ x, y });
                }
            }
        }

        ret = 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int buildExistingRegion(mapping regionData)
{
    return setRegionDetails(regionData) && setRegionGrid(regionData);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int load(string enterFrom, string location)
{
    int ret = 0;

    if (stringp(enterFrom) && stringp(location))
    {
        mapping data = Dictionary->loadRegion(enterFrom, location);

        if (mappingp(data) && sizeof(data))
        {
            ret = buildExistingRegion(data);

            if (sizeof(rooms))
            {
                foreach(mapping room in rooms)
                {
                    generateRoomDetails(room);
                }
            }

            grid[entry[0]][entry[1]]["environment"]->addEntryExit(
                enterFrom, location);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void save()
{
    Dictionary->saveRegion(this_object());
}
