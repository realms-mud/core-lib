//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
protected void setRoadCell(string description, string terrain, mapping exits)
{
    setTerrain(terrain);
    setShortDescription(description);
    addDecorator("village east-west road");

    foreach(string direction in m_indices(exits))
    {
        addFeature("/lib/environment/features/paths/road.c", direction);
        addExit(direction, exits[direction]);
    }
}
