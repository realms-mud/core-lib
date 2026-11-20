//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("disused water mill");
    setFloorPlanType("trade");
    addAlias("mill");
    addDescriptionTemplate("a disused water mill with a stopped wheel");
    addItemTemplate("The old wheel no longer reaches a working "
        "millrace. Repaired boards keep one side room dry as a "
        "travelers' shelter. The structure produces no grain or "
        "domain income merely by standing beside the road.");
    addNearDarkDescriptionTemplate("a low uneven silhouette");
    addLowLightDescriptionTemplate("a mill-shaped building beside a wheel");
    addDimLightDescriptionTemplate("a boarded mill with a stopped wheel");
    addSomeLightDescriptionTemplate("a disused mill with a repaired shelter door");
    addTimeOfDayDescription("dawn", ({ " beaded with dew beneath the wheel" }));
    addTimeOfDayDescription("morning", ({ " showing old repairs in its boards" }));
    addTimeOfDayDescription("noon", ({ " casting a still wheel-shaped shadow" }));
    addTimeOfDayDescription("afternoon", ({ " quiet beside the dry millrace" }));
    addTimeOfDayDescription("evening", ({ " shaded beneath its patched roof" }));
    addTimeOfDayDescription("dusk", ({ " dark along the abandoned race" }));
    addTimeOfDayDescription("night", ({ " silent beside the road" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the trees" }));
    addSeasonDescription("spring", ({ " with rain trickling down its wheel" }));
    addSeasonDescription("summer", ({ " dry beneath the patched eaves" }));
    addSeasonDescription("autumn", ({ " with leaves caught in the stopped wheel" }));
    addSeasonDescription("winter", ({ " frosted across its old timbers" }));
}
