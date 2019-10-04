//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

private string interiorType = "wood building";
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
protected string setFloorPlanType(string type)
{
    return FloorPlanType;
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
public nomask object generateInterior(string exitTo, int x, int y)
{
    return 0;
}
