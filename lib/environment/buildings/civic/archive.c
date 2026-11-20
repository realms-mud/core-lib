//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("town archive");
    setFloorPlanType("trade");
    addAlias("archive");
    addDescriptionTemplate("a modest town archive with shuttered windows");
    addItemTemplate("The archive's raised floor protects household "
        "registers from damp. Narrow windows light the copying desks, "
        "while a covered entrance shelters visitors and their papers.");
    addNearDarkDescriptionTemplate("a low building behind closed shutters");
    addLowLightDescriptionTemplate("a building with narrow windows");
    addDimLightDescriptionTemplate("a modest archive with a covered entrance");
    addSomeLightDescriptionTemplate("a town archive with raised floors and shutters");
    addTimeOfDayDescription("dawn", ({ " quiet before the copying work" }));
    addTimeOfDayDescription("morning", ({ " with light falling through its windows" }));
    addTimeOfDayDescription("noon", ({ " shaded beneath its entrance cover" }));
    addTimeOfDayDescription("afternoon", ({ " casting a long shadow" }));
    addTimeOfDayDescription("evening", ({ " with lamplight at the copying desk" }));
    addTimeOfDayDescription("dusk", ({ " sheltered behind drawn shutters" }));
    addTimeOfDayDescription("night", ({ " quiet beneath its roof" }));
    addTimeOfDayDescription("midnight", ({ " still along the sleeping street" }));
    addSeasonDescription("spring", ({ " raised above the rain-soaked lane" }));
    addSeasonDescription("summer", ({ " aired through screened windows" }));
    addSeasonDescription("autumn", ({ " with its roof repaired against rain" }));
    addSeasonDescription("winter", ({ " shuttered against drafts" }));
}
