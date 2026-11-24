//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("wrecked stagecoach");
    addAlias("stagecoach");
    addAlias("coach");
    addAdjectives(({ "wrecked", "splintered", "tilted", "abandoned" }));
    addDescriptionTemplate("a ##Adjective## stagecoach half off the track");
    addNearDarkDescriptionTemplate("a tilted coach-shaped shadow");
    addLowLightDescriptionTemplate("a stagecoach broken against a fir");
    addDimLightDescriptionTemplate("a stagecoach with one wheel missing");
    addSomeLightDescriptionTemplate(
        "a splintered stagecoach leaning against the trackside firs");
    addItemTemplate("The axle has snapped cleanly, but the harness is "
        "still buckled and the driver's box is locked. One passenger "
        "door hangs open. Mud on the step carries overlapping boot "
        "prints away from the road; a torn blue curtain is caught "
        "high in the branches.");
    addTimeOfDayDescription("dawn", ({ " silvered with dew" }));
    addTimeOfDayDescription("morning", ({ " bright against the firs" }));
    addTimeOfDayDescription("noon", ({ " throwing a hard shadow" }));
    addTimeOfDayDescription("afternoon", ({ " warm along its split boards" }));
    addTimeOfDayDescription("evening", ({ " dark beneath the branches" }));
    addTimeOfDayDescription("dusk", ({ " becoming difficult to distinguish" }));
    addTimeOfDayDescription("night", ({ " silent beside the track" }));
    addTimeOfDayDescription("midnight", ({ " cold beneath the stars" }));
    addSeasonDescription("spring", ({ " listing in the soft road mud" }));
    addSeasonDescription("summer", ({ " dusty beneath the needles" }));
    addSeasonDescription("autumn", ({ " filled with wet leaves" }));
    addSeasonDescription("winter", ({ " rimed with frost and snow" }));
}
