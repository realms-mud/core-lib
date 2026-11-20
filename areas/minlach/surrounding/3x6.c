//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-east passage");
    setShortDescription("The upper crew refuge");
    addItem("/lib/environment/items/records/cargo-slate.c", "north");
    addItem("/lib/environment/items/lighting/lantern.c", "north");
    addFeature("/lib/environment/features/caves/timber-supports.c", "east");
    addClue("crew refuge slate", "flooded-workings", "readCrewRefugeSlate",
        "The slate identifies a dry refuge and the supported "
        "upper approach. A trained crew can use it for recovery "
        "without opening the flooded gallery.");
    addExit("east", "/areas/minlach/surrounding/4x6.c");
    addExit("south", "/areas/minlach/surrounding/3x5.c");
}
