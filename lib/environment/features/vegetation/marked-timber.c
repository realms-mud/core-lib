//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("marked timber plot");
    addAlias("timber cuts");
    addAlias("stumps");
    addDescriptionTemplate("marked woodland trunks around several fresh stumps");
    addItemTemplate("Survey marks identify the managed timber plot. "
        "Fresh stumps show where standing trees were cut beyond "
        "the common boundary. No timber is available for public "
        "harvesting here. An inquiry can investigate the timber cuts.");
    addNearDarkDescriptionTemplate("a stand of dark trunks");
    addLowLightDescriptionTemplate("tree trunks around low stumps");
    addDimLightDescriptionTemplate("marked trunks beside newly cut stumps");
    addSomeLightDescriptionTemplate("a managed timber plot with pale fresh cuts");
    addTimeOfDayDescription("dawn", ({ " damp beneath the canopy" }));
    addTimeOfDayDescription("morning", ({ " showing pale cut surfaces" }));
    addTimeOfDayDescription("noon", ({ " shaded by surviving trees" }));
    addTimeOfDayDescription("afternoon", ({ " striped with long shadows" }));
    addTimeOfDayDescription("evening", ({ " dark along the woodland margin" }));
    addTimeOfDayDescription("dusk", ({ " blending into the trees" }));
    addTimeOfDayDescription("night", ({ " silent beneath the canopy" }));
    addTimeOfDayDescription("midnight", ({ " still beside the path" }));
    addSeasonDescription("spring", ({ " surrounded by young shoots" }));
    addSeasonDescription("summer", ({ " shaded by full foliage" }));
    addSeasonDescription("autumn", ({ " scattered with fallen leaves" }));
    addSeasonDescription("winter", ({ " exposed beneath bare branches" }));
}
