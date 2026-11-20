//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("hunter's lean-to");
    addAlias("hunter shelter");
    addAlias("lean-to");
    addDescriptionTemplate("a low hunter's lean-to beneath the trees");
    addItemTemplate("The shelter is built from fallen branches and "
        "weathered canvas, with dry kindling stacked beneath its raised "
        "edge. A narrow trail runs past it toward the old temple road.");
    addNearDarkDescriptionTemplate("a low shape under the trees");
    addLowLightDescriptionTemplate("a rough shelter beside the trail");
    addDimLightDescriptionTemplate("a canvas lean-to with a woodpile");
    addSomeLightDescriptionTemplate("a hunter's lean-to beneath the trees");
    addTimeOfDayDescription("dawn", ({ " beaded with dew" }));
    addTimeOfDayDescription("morning", ({ " open to the woodland air" }));
    addTimeOfDayDescription("noon", ({ " shaded beneath the canopy" }));
    addTimeOfDayDescription("afternoon", ({ " dry beneath its canvas" }));
    addTimeOfDayDescription("evening", ({ " dark beneath the branches" }));
    addTimeOfDayDescription("dusk", ({ " fading into the trees" }));
    addTimeOfDayDescription("night", ({ " nearly hidden in the dark" }));
    addTimeOfDayDescription("midnight", ({ " silent beneath the canopy" }));
    addSeasonDescription("spring", ({ " ringed by wet leaf litter" }));
    addSeasonDescription("summer", ({ " screened by dense foliage" }));
    addSeasonDescription("autumn", ({ " strewn with fallen leaves" }));
    addSeasonDescription("winter", ({ " weighted with light snow" }));
}
