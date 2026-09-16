//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/environment/modules/environment/core.c";
virtual inherit "/lib/environment/modules/environment/region.c";
virtual inherit "/lib/environment/modules/environment/exits.c";

// Tracks the last region name pushed to each viewer so the full region grid
// is only re-sent when the viewer crosses into a different region.
// Keyed by viewer object; values are region name strings.
private nosave mapping lastRegionByViewer = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int viewerHasGmcp(object viewer)
{
    return objectp(viewer) &&
        function_exists("gmcpIsEnabled", viewer) &&
        viewer->gmcpIsEnabled() &&
        function_exists("sendOutOfBand", viewer);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string snapshotCellDecorator(mapping cell)
{
    string ret = 0;
    object environment = member(cell, "environment") ? cell["environment"] : 0;

    if (objectp(environment) && function_exists("decoratorType", environment))
    {
        ret = environment->decoratorType(0);
    }

    if (!stringp(ret) && member(cell, "decorator type") &&
        stringp(cell["decorator type"]))
    {
        ret = cell["decorator type"];
    }

    if (!stringp(ret))
    {
        ret = cell["room type"];
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping snapshotRegionCell(int x, int y, mapping cell)
{
    mapping ret = ([
        "x": x,
        "y": y,
        "type": cell["room type"],
        "path": cell["name"],
        "decorator": snapshotCellDecorator(cell),
    ]);

    if (member(cell, "exit to") && stringp(cell["exit to"]))
    {
        ret["exit to"] = cell["exit to"];
    }

    if (member(cell, "state exits"))
    {
        ret["exits"] = cell["state exits"];
    }

    if (objectp(cell["environment"]) &&
        function_exists("buildRoomSnapshot", cell["environment"]))
    {
        mapping roomSnapshot = cell["environment"]->buildRoomSnapshot();

        ret["terrain"] = roomSnapshot["terrain"];
        ret["interior"] = roomSnapshot["interior"];
        ret["features"] = roomSnapshot["features"];
        ret["items"] = roomSnapshot["items"];
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping buildRegionSnapshot()
{
    mapping ret = 0;
    object region = getRegion();

    if (objectp(region))
    {
        int maxX = region->xDimension();
        int maxY = region->yDimension();
        mapping *cells = ({});

        for (int x = 0; x < maxX; x++)
        {
            for (int y = 0; y < maxY; y++)
            {
                mapping cell = region->coordinateToMapping(x, y);

                if (mappingp(cell) && cell["is placed"])
                {
                    cells += ({ snapshotRegionCell(x, y, cell) });
                }
            }
        }

        ret = ([
            "name": region->regionName(),
            "type": region->regionType(),
            "level": region->regionLevel(),
            "width": maxX,
            "height": maxY,
            "entry": region->entryPoint(),
            "entryDirection": region->entryDirection(),
            "rooms": cells,
        ]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping snapshotLocation(mapping location)
{
    return ([
        "description": location["description"],
        "x": location["x"],
        "y": location["y"],
        "z": location["z"],
        "x-rotation": location["x-rotation"],
        "y-rotation": location["y-rotation"],
        "z-rotation": location["z-rotation"],
    ]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *snapshotElementsOfType(string type)
{
    mapping *ret = ({});

    if (member(environmentalElements, type) &&
        mappingp(environmentalElements[type]) &&
        sizeof(environmentalElements[type]))
    {
        foreach(string element, mixed placements in environmentalElements[type])
        {
            object elementObj =
                getService("environment")->environmentalObject(element);

            mapping *locations = ({});
            if (pointerp(placements))
            {
                foreach(mapping location in placements)
                {
                    if (mappingp(location))
                    {
                        locations += ({ snapshotLocation(location) });
                    }
                }
            }

            ret += ({ ([
                "name": objectp(elementObj) ? elementObj->Name() : element,
                "element": element,
                "type": type,
                "locations": locations,
            ]) });
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping *snapshotRoomContents(object viewer)
{
    mapping *ret = ({});

    foreach(object item in all_inventory(this_object()))
    {
        string shortDesc = objectp(item) ? item->short() : 0;

        if (stringp(shortDesc) && (shortDesc != "") && (item != viewer))
        {
            ret += ({ ([
                "name": shortDesc,
                "path": program_name(item),
                "living": function_exists("isRealizationOfLiving", item) ?
                    item->isRealizationOfLiving() : 0,
            ]) });
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping buildRoomSnapshot(object viewer)
{
    object region = getRegion();

    return ([
        "coordinate": getCoordinates(),
        "region": objectp(region) ? region->regionName() : 0,
        "terrain": snapshotElementsOfType("terrain"),
        "interior": snapshotElementsOfType("interior"),
        "features": snapshotElementsOfType("feature"),
        "items": snapshotElementsOfType("item"),
        "exits": exits(),
        "contents": snapshotRoomContents(viewer),
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask int pushRegionSnapshot(object viewer)
{
    int ret = 0;
    mapping snapshot = viewerHasGmcp(viewer) ? buildRegionSnapshot() : 0;

    if (mappingp(snapshot))
    {
        ret = viewer->sendOutOfBand("Region", snapshot);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int pushRoomSnapshot(object viewer)
{
    int ret = 0;
    mapping snapshot = viewerHasGmcp(viewer) ? buildRoomSnapshot(viewer) : 0;

    if (mappingp(snapshot))
    {
        ret = viewer->sendOutOfBand("Room.Info", snapshot);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int pushRegionSnapshotForViewer(object viewer)
{
    int ret = 0;
    object region = getRegion();

    if (viewerHasGmcp(viewer) && objectp(region))
    {
        string regionName = region->regionName();

        if (regionName != lastRegionByViewer[viewer])
        {
            lastRegionByViewer[viewer] = regionName;
            ret = pushRegionSnapshot(viewer);
        }
    }

    return ret;
}
