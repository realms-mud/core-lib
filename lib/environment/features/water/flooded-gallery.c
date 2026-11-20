//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("flooded gallery");
    addAlias("floodwater");
    addAlias("adit watermark");
    addDescriptionTemplate("a flooded lower gallery beyond a stone ledge");
    addItemTemplate("Water covers the lower working and darkens "
        "a marked line on the stone. The dry ledge is the safe "
        "standing place; the lower gallery is not a passage. "
        "An assigned survey can investigate the adit watermark.");
    addNearDarkDescriptionTemplate("a dark recess beyond the ledge");
    addLowLightDescriptionTemplate("water below a stone ledge");
    addDimLightDescriptionTemplate("a flooded passage beneath a water mark");
    addSomeLightDescriptionTemplate("a closed flooded gallery below a dry ledge");
    addTimeOfDayDescription("dawn", ({ " echoing with slow drips" }));
    addTimeOfDayDescription("morning", ({ " still beneath the wet stone" }));
    addTimeOfDayDescription("noon", ({ " hidden from daylight" }));
    addTimeOfDayDescription("afternoon", ({ " cold beneath the rock" }));
    addTimeOfDayDescription("evening", ({ " quiet except for dripping water" }));
    addTimeOfDayDescription("dusk", ({ " dark beyond the ledge" }));
    addTimeOfDayDescription("night", ({ " echoing faintly" }));
    addTimeOfDayDescription("midnight", ({ " undisturbed beneath the rock" }));
    addSeasonDescription("spring", ({ " fed by seepage from above" }));
    addSeasonDescription("summer", ({ " cool below the surface ground" }));
    addSeasonDescription("autumn", ({ " dripping after the seasonal rains" }));
    addSeasonDescription("winter", ({ " sheltered from the surface frost" }));
}
