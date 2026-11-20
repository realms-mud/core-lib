//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/doors/baseDoor.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("plank door");
    addAlias("door");
    addAlias("wooden door");
    addDescriptionTemplate("a stout plank door on iron strap hinges");
    addItemTemplate("Close-fitting wooden boards are braced by "
        "crosspieces and hung from plain iron straps. A worn "
        "handle and a draught strip show regular use. This "
        "public entrance has no keyed lock.");
    addNearDarkDescriptionTemplate("a tall shadow in the wall");
    addLowLightDescriptionTemplate("a wooden door");
    addDimLightDescriptionTemplate("a plank door with iron hinges");
    addSomeLightDescriptionTemplate("a braced plank door with a worn handle");
    addTimeOfDayDescription("dawn", ({ " cool along its iron hinges" }));
    addTimeOfDayDescription("morning", ({ " worn smooth around the handle" }));
    addTimeOfDayDescription("noon", ({ " showing the grain of its boards" }));
    addTimeOfDayDescription("afternoon", ({ " shadowed beneath its frame" }));
    addTimeOfDayDescription("evening", ({ " quiet against the doorway" }));
    addTimeOfDayDescription("dusk", ({ " fading into the frame's shadows" }));
    addTimeOfDayDescription("night", ({ " dark beneath the lintel" }));
    addTimeOfDayDescription("midnight", ({ " still in the quiet doorway" }));
    addSeasonDescription("spring", ({ " swollen slightly by damp weather" }));
    addSeasonDescription("summer", ({ " dry across its wooden boards" }));
    addSeasonDescription("autumn", ({ " fitted with a fresh draught strip" }));
    addSeasonDescription("winter", ({ " sealed against the cold" }));
}
