//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addDecorator("rocky shore");
    setShortDescription("The low signal cove");
    addItem("/lib/environment/items/marine/shuttered-signal-lantern.c",
        "east");
    addFeature("/lib/environment/features/landforms/cliff.c", "west");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addClue("false lantern", "false-harbor-light", "inspectFalseLantern",
        "The hood and repeated shutter marks show deliberate "
        "signaling below the official beacon's sight line.");
    addExit("north", "/areas/minlach/shore/2x3.c");
    addExit("south", "/areas/minlach/shore/2x1.c");
}
