//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("spectator stands");
    addAlias("stands");
    addAlias("seating");
    addAlias("benches");

    addAdjectives(({ "tiered", "wooden", "crowded", "raucous", "circular" }));

    setDescriptionTemplate("##Adjective## wooden stands surrounding the arena "
        "where spectators gather to watch the combats");

    addItemTemplate("The lower rows are reserved for wealthy patrons and "
        "officials, with the common folk relegated to the higher tiers");

    addSomeLightDescriptionTemplate("wooden benches arranged in rising tiers "
        "around the combat arena, allowing spectators a clear view");

    addDimLightDescriptionTemplate("rising rows of seating surrounding the "
        "central fighting area");

    addLowLightDescriptionTemplate("what seems to be tiered seating around the "
        "perimeter of the arena");

    addNearDarkDescriptionTemplate("shadowy shapes suggesting rows of seating "
        "in the darkness");
}
