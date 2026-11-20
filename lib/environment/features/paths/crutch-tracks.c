//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crutch-marked walking tracks");
    addAlias("carter tracks");
    addAlias("tracks");
    addDescriptionTemplate("two walking trails with a repeated wooden crutch mark");
    addItemTemplate("Two sets of boot marks lead along the sheltered "
        "path. A repeated square mark accompanies one uneven "
        "stride. There are no drag marks. An assigned search "
        "can investigate the carter tracks.");
    addNearDarkDescriptionTemplate("uneven ground along the path");
    addLowLightDescriptionTemplate("faint impressions in the track");
    addDimLightDescriptionTemplate("walking tracks beside repeated shallow marks");
    addSomeLightDescriptionTemplate("two boot trails accompanied by crutch marks");
    addTimeOfDayDescription("dawn", ({ " edged with dew" }));
    addTimeOfDayDescription("morning", ({ " clearer in the slanting light" }));
    addTimeOfDayDescription("noon", ({ " difficult to read in the flat light" }));
    addTimeOfDayDescription("afternoon", ({ " picked out by low shadows" }));
    addTimeOfDayDescription("evening", ({ " fading beneath the trees" }));
    addTimeOfDayDescription("dusk", ({ " difficult to distinguish" }));
    addTimeOfDayDescription("night", ({ " needing light for close examination" }));
    addTimeOfDayDescription("midnight", ({ " hidden in the path's darkness" }));
    addSeasonDescription("spring", ({ " pressed into damp ground" }));
    addSeasonDescription("summer", ({ " traced through sheltered dust" }));
    addSeasonDescription("autumn", ({ " partly covered by fallen leaves" }));
    addSeasonDescription("winter", ({ " preserved in the sheltered track" }));
}
