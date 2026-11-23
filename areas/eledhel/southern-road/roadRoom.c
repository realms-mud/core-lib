//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
protected void setRoadCell(string description, string terrain, mapping exits)
{
    string decorator = "village east-west road";
    if (member(exits, "north") && member(exits, "south") &&
        member(exits, "east") && member(exits, "west"))
    {
        decorator = "village road intersection";
    }
    else if (member(exits, "north") && member(exits, "east") &&
        member(exits, "west") && !member(exits, "south"))
    {
        decorator = "village road T-north";
    }
    else if (member(exits, "south") && member(exits, "east") &&
        member(exits, "west") && !member(exits, "north"))
    {
        decorator = "village road T-south";
    }
    else if (member(exits, "north") && member(exits, "south") &&
        member(exits, "east") && !member(exits, "west"))
    {
        decorator = "village road T-east";
    }
    else if (member(exits, "north") && member(exits, "south") &&
        member(exits, "west") && !member(exits, "east"))
    {
        decorator = "village road T-west";
    }
    else if (member(exits, "north") && member(exits, "south") &&
        !member(exits, "east") && !member(exits, "west"))
    {
        decorator = "village north-south road";
    }
    setTerrain(terrain);
    setShortDescription(description);
    addDecorator(decorator);

    foreach(string direction in m_indices(exits))
    {
        addFeature("/lib/environment/features/paths/road.c", direction);
        addExit(direction, exits[direction]);
    }
}
