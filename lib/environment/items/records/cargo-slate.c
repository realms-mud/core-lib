//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("cargo slate");
    addAlias("slate");
    addAlias("tally");
    addDescriptionTemplate("a cargo slate hung beneath a wooden cover");
    addItemTemplate("Chalk columns record loads, times, and the initials "
        "of workers accepting each delivery. The cover protects the "
        "writing from rain. Records may be checked with investigate.");
    addNearDarkDescriptionTemplate("a dark rectangular object");
    addLowLightDescriptionTemplate("a covered writing board");
    addDimLightDescriptionTemplate("a slate with faint chalk columns");
    addSomeLightDescriptionTemplate("a covered cargo slate with chalk tallies");
    addTimeOfDayDescription("dawn", ({ " damp along its wooden frame" }));
    addTimeOfDayDescription("morning", ({ " freshly marked for the day's work" }));
    addTimeOfDayDescription("noon", ({ " shaded beneath its protective cover" }));
    addTimeOfDayDescription("afternoon", ({ " smudged where entries were revised" }));
    addTimeOfDayDescription("evening", ({ " carrying the day's final tally" }));
    addTimeOfDayDescription("dusk", ({ " fading into the shadows" }));
    addTimeOfDayDescription("night", ({ " quiet beneath its cover" }));
    addTimeOfDayDescription("midnight", ({ " protected from the night damp" }));
    addSeasonDescription("spring", ({ " sheltered from passing rain" }));
    addSeasonDescription("summer", ({ " dusty along its lower edge" }));
    addSeasonDescription("autumn", ({ " covered against wind-driven rain" }));
    addSeasonDescription("winter", ({ " with frost on the outside of its cover" }));
}
