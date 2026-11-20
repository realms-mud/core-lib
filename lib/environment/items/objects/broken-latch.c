//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("broken latch");
    addAlias("latch");
    addAlias("splinters");
    addDescriptionTemplate("a broken wooden latch with splinters below it");
    addItemTemplate("The latch's split grain and scattered splinters "
        "show the direction in which it failed. Nothing about the "
        "damage alone identifies who caused it. An assigned "
        "examination can be made with investigate warehouse latch.");
    addNearDarkDescriptionTemplate("an uneven shadow beside the doorway");
    addLowLightDescriptionTemplate("a damaged fitting beside the doorway");
    addDimLightDescriptionTemplate("a split latch above scattered fragments");
    addSomeLightDescriptionTemplate("a broken latch with exposed pale wood");
    addTimeOfDayDescription("dawn", ({ " damp on its exposed grain" }));
    addTimeOfDayDescription("morning", ({ " showing pale splinters" }));
    addTimeOfDayDescription("noon", ({ " casting a short jagged shadow" }));
    addTimeOfDayDescription("afternoon", ({ " edged by lengthening shadows" }));
    addTimeOfDayDescription("evening", ({ " difficult to distinguish from its frame" }));
    addTimeOfDayDescription("dusk", ({ " losing its details in the dimness" }));
    addTimeOfDayDescription("night", ({ " dark beside the closed doorway" }));
    addTimeOfDayDescription("midnight", ({ " quiet against the door frame" }));
    addSeasonDescription("spring", ({ " swollen by rain" }));
    addSeasonDescription("summer", ({ " dry along its fractured edge" }));
    addSeasonDescription("autumn", ({ " catching windblown leaves below it" }));
    addSeasonDescription("winter", ({ " cold and stiff against the frame" }));
}
