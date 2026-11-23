//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("peat bog");
    addAlias("bog");
    addDescriptionTemplate("a peaty hollow fringed with moss and rushes");
    addNearDarkDescriptionTemplate("a dark, waterlogged hollow");
    addLowLightDescriptionTemplate("a soft patch of bogland");
    addDimLightDescriptionTemplate(
        "a peat bog with pools between the mossy hummocks");
    addSomeLightDescriptionTemplate(
        "a wet peat bog where rushes fringe dark pools");
    addItemTemplate("The ground gives way to saturated peat beyond the "
        "rushes. Moss binds the hummocks, and black pools collect rain "
        "between them. Cut turves lie stacked on a drier rise, well clear "
        "of the road and the living moss.");

    addTimeOfDayDescription("dawn", ({ " beaded with cold moisture" }));
    addTimeOfDayDescription("morning", ({ " reflecting the pale sky" }));
    addTimeOfDayDescription("noon", ({ " dark beneath the open light" }));
    addTimeOfDayDescription("afternoon", ({ " steaming faintly after rain" }));
    addTimeOfDayDescription("evening", ({ " swallowing the last light" }));
    addTimeOfDayDescription("dusk", ({ " blending into the shadowed hollow" }));
    addTimeOfDayDescription("night", ({ " black between the mossy hummocks" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the night air" }));

    addSeasonDescription("spring", ({ " brimful with rain and meltwater" }));
    addSeasonDescription("summer", ({ " soft beneath its dry-looking crust" }));
    addSeasonDescription("autumn", ({ " spongy under the fallen leaves" }));
    addSeasonDescription("winter", ({ " edged with a thin skin of ice" }));
}
