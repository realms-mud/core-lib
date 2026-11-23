//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("tenant threshing floor");
    addAlias("threshing floor");
    addAlias("threshing ground");
    addDescriptionTemplate("a hard-packed tenant threshing floor");
    addNearDarkDescriptionTemplate("a smooth patch of earth by the fields");
    addLowLightDescriptionTemplate("a circular patch of packed earth");
    addDimLightDescriptionTemplate("a threshing floor edged with straw");
    addSomeLightDescriptionTemplate("a tenant threshing floor beside the road");
    addItemTemplate("A broad circle of hard-packed earth lies at the meeting "
        "of several tenant plots. Straw and chaff gather along its edge, and "
        "cart ruts lead from the floor toward the estate road. The ground is "
        "swept clear when it is not in use.");

    addTimeOfDayDescription("dawn", ({ " cool beneath the morning dew" }));
    addTimeOfDayDescription("morning", ({ " brushed clean for the day's work" }));
    addTimeOfDayDescription("noon", ({ " warm beneath the open sky" }));
    addTimeOfDayDescription("afternoon", ({ " scattered with fresh chaff" }));
    addTimeOfDayDescription("evening", ({ " quiet after the day's threshing" }));
    addTimeOfDayDescription("dusk", ({ " fading into the field margins" }));
    addTimeOfDayDescription("night", ({ " bare beneath the dark sky" }));
    addTimeOfDayDescription("midnight", ({ " still beside the tenant fields" }));

    addSeasonDescription("spring", ({ " clear and ready for repair" }));
    addSeasonDescription("summer", ({ " marked by drying sheaves" }));
    addSeasonDescription("autumn", ({ " edged with chaff after threshing" }));
    addSeasonDescription("winter", ({ " hard beneath a skim of frost" }));
}
