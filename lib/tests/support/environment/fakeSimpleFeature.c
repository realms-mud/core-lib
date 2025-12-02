//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("fake cave");
    addAdjectives(({ "dark and foreboding" }));
    addTimeOfDayDescription("dawn", ({ " that is barely visible" }));
    addTimeOfDayDescription("noon", ({ ", somewhat illuminated" }));
    addTimeOfDayDescription("afternoon", ({ ", shadowed ominously" }));
    addSeasonDescription("winter", ({ " covered with a thick layer of snow" }));
    addSeasonDescription("spring", ({ " with green moss at its entrance" }));
    addSeasonDescription("summer", ({ " largely obscured by foliage" }));
    addSeasonDescription("autumn", ({ " visible through several bare branches" }));

    addDescriptionTemplate("a ##Adjective## cave");
}
