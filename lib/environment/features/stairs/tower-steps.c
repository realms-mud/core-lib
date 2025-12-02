//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tower steps");
    suppressEntryMessage();
    addAlias("stairs");
    addAlias("steps");
    addAlias("tower");

    addAdjectives(({ "that wind steeply through the tower's interior",
        "carved directly from the tower's stone walls",
        "with narrow treads and high risers",
        "that echo with each footfall",
        "built for function rather than comfort",
        "with iron brackets for torches along the wall",
        "that disappear into shadows",
        "showing wear from guards and servants" }));

    addDescriptionTemplate("tower steps ##Adjective## "
        "provide access through the tower levels");
    addSomeLightDescriptionTemplate("tower steps ##Adjective## "
        "wind through the tower interior");
    addNearDarkDescriptionTemplate("stone steps can be felt "
        "winding through the tower's darkness");
    addLowLightDescriptionTemplate("narrow tower steps "
        "disappearing into shadows");
    addDimLightDescriptionTemplate("tower steps ##Adjective## "
        "wind through the tower structure");
    addSourceOfLight(1);

    addItemTemplate("The tower steps are cut directly from the stone "
        "of the tower walls, creating a steep passage designed more for "
        "defense than comfort. Each step is narrow, forcing travelers to "
        "move slowly and deliberately. Iron brackets along the wall once "
        "held torches to light the way, while small arrow slits provide "
        "occasional glimpses of the outside world during passage.");
}
