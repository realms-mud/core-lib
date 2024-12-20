//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

private string interiorType = "wooden building";
private string FloorPlanType = "shop";

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return "building";
}

/////////////////////////////////////////////////////////////////////////////
public string floorPlanType()
{
    return FloorPlanType;
}

/////////////////////////////////////////////////////////////////////////////
protected void setFloorPlanType(string type)
{
    FloorPlanType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string InteriorType(string interior)
{
    if (interior)
    {
        if (member(({ "wood building", "limestone building", "granite building",
            "brick building", "opulent building" }), interior) > -1)
        {
            interiorType = interior;
        }
        else
        {
            raise_error("baseBuilding.c: Invalid shop interior specified.\n");
        }
    }
    return interiorType;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object generateInterior(string exitTo, int x, int y,
    object connectedRegion)
{
    object dictionary = load_object("/lib/dictionaries/regionDictionary.c");
    mapping regionData = dictionary->getFloorPlan(FloorPlanType);

    object region = clone_object("/lib/environment/region.c");

    mapping *entries = filter(regionData["rooms"],
        (: (member($1, "entry for") && (member($1["entry for"], $2) > -1)) :),
            exitTo);

    if (sizeof(entries))
    {
        mapping entry = entries[random(sizeof(entries))];

        regionData["entry coordinate"] = ({ entry["x"], entry["y"] });
        entry["room type"] = "entry";
    }
    regionData["master region name"] = connectedRegion->regionName();
    regionData["level"] = connectedRegion->regionLevel();
    regionData["entry point"] = sprintf("%dx%d", x, y);
    regionData["name"] = sprintf("%s-%s", regionData["name"],
        regreplace(object_name(region), ".*#([0-9]+)", "\\1", 1));
    regionData["type"] = interiorType;
    regionData["enter from"] = region->getEnterFromDirection(exitTo);

    region->createRegionFromTemplate(regionData, connectedRegion);
    return region;
}
