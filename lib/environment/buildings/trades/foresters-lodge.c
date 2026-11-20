//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("forester's lodge");
    setFloorPlanType("trade");
    addAlias("lodge");
    addDescriptionTemplate("a small forester's lodge with a covered porch");
    addItemTemplate("The lodge provides a dry place for boundary "
        "maps, permits, and woodland tools. Its worn threshold "
        "faces the managed paths rather than a commercial lumber yard.");
    addNearDarkDescriptionTemplate("a small dark building");
    addLowLightDescriptionTemplate("a lodge beneath a pitched roof");
    addDimLightDescriptionTemplate("a timber lodge with a porch");
    addSomeLightDescriptionTemplate("a forester's lodge with a worn threshold");
    addTimeOfDayDescription("dawn", ({ " damp beneath the porch roof" }));
    addTimeOfDayDescription("morning", ({ " lit along its sheltered entrance" }));
    addTimeOfDayDescription("noon", ({ " shaded by its broad eaves" }));
    addTimeOfDayDescription("afternoon", ({ " warm along its timber wall" }));
    addTimeOfDayDescription("evening", ({ " quiet after the woodland work" }));
    addTimeOfDayDescription("dusk", ({ " dim beneath its eaves" }));
    addTimeOfDayDescription("night", ({ " dark against the common" }));
    addTimeOfDayDescription("midnight", ({ " silent beneath its roof" }));
    addSeasonDescription("spring", ({ " with muddy boots beside the porch" }));
    addSeasonDescription("summer", ({ " aired through its narrow windows" }));
    addSeasonDescription("autumn", ({ " surrounded by windblown leaves" }));
    addSeasonDescription("winter", ({ " shuttered against the cold" }));
}
