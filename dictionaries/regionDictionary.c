//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib//dictionaries/regions/region-types.h"

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidRegionType(string type)
{
    return member(RegionTypes, type);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidRegion(object region)
{
    int ret = 0;
    if (objectp(region) &&
        member(inherit_list(region), "lib/environment/region.c") > -1)
    {
        ret = isValidRegionType(region->regionType());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping setTerrain(mapping room, mapping roomInput)
{
    if (member(roomInput, "terrain"))
    {
        room["terrain"] = roomInput["terrain"];
    }
    else
    {
        room["interior"] = roomInput["interior"];
    }
    return room;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping setExits(mapping room, mapping exits,
    mapping roomInput, object region)
{
    room["exits"] = ([]);

    foreach(string direction in m_indices(exits))
    {
        room["exits"][direction] = ([
            "exit to": exits[direction],
            "path type": "/lib/environment/features/path.c",
            "region": region
        ]);
    }
    return room;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping generateRoomData(object region, mapping data)
{
    mapping ret = 0;
    if (isValidRegion(region))
    {
        ret = ([]);
        mapping roomInput = RegionTypes[region->regionType()] + ([]);

        setTerrain(ret, roomInput);
        setExits(ret, data["exits"], roomInput, region);

        ret["features"] = ([]);
        ret["items"] = ([]);
        ret["room objects"] = ([]);
        ret["creatures"] = ([]);
    }

    return ret;
}
