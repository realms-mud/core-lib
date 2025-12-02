//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("castle steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("castle");

    addAdjectives(({ "built with deliberately uneven heights",
        "designed to trip attacking enemies",
        "that wind between levels in a defensive pattern",
        "with treads of varying depth",
        "carved to favor right-handed defenders",
        "that force attackers into vulnerable positions",
        "built from massive stone blocks",
        "with murder holes positioned overhead" }));

    addDescriptionTemplate("castle steps ##Adjective## "
        "serve both access and defensive purposes");
    addSomeLightDescriptionTemplate("castle steps ##Adjective## "
        "connect levels with strategic irregularity");
    addNearDarkDescriptionTemplate("uneven stone steps can be felt "
        "following a defensive pattern");
    addLowLightDescriptionTemplate("irregular castle steps "
        "wind between levels with defensive intent");
    addDimLightDescriptionTemplate("castle steps ##Adjective## "
        "link floors with military precision");
    addSourceOfLight(1);

    addItemTemplate("The castle steps are engineered with defense in mind, "
        "each irregularity deliberately planned to disadvantage attackers. "
        "Steps of uneven height and depth force enemies to look down while "
        "moving, making them vulnerable to defenders. The design often "
        "favors right-handed defenders wielding swords, while narrow "
        "passages prevent massed assault. Murder holes and arrow slits "
        "command key positions along the route.");
}
