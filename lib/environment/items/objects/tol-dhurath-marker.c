//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Tol-Dhurath trail marker");
    addAlias("trail marker");
    addAlias("wooden marker");
    addDescriptionTemplate("a weather-worn trail marker");
    addItemTemplate("A carved arrow points west toward Tol-Dhurath. A "
        "second mark warns that the patrol trail grows rough beyond the "
        "wooded rise.");
    addNearDarkDescriptionTemplate("a narrow shape beside the trail");
    addLowLightDescriptionTemplate("a wooden marker at the path edge");
    addDimLightDescriptionTemplate("a weather-worn sign with carved arrows");
    addSomeLightDescriptionTemplate("a wooden trail marker pointing west");
    addTimeOfDayDescription("dawn", ({ " dark with dew" }));
    addTimeOfDayDescription("morning", ({ " clear in the early light" }));
    addTimeOfDayDescription("noon", ({ " casting a short shadow" }));
    addTimeOfDayDescription("afternoon", ({ " dappled by the canopy" }));
    addTimeOfDayDescription("evening", ({ " dim beneath the trees" }));
    addTimeOfDayDescription("dusk", ({ " fading into the wooded path" }));
    addTimeOfDayDescription("night", ({ " hard to read in the dark" }));
    addTimeOfDayDescription("midnight", ({ " silent beside the trail" }));
    addSeasonDescription("spring", ({ " marked by fresh rain streaks" }));
    addSeasonDescription("summer", ({ " partly screened by new growth" }));
    addSeasonDescription("autumn", ({ " surrounded by fallen leaves" }));
    addSeasonDescription("winter", ({ " edged with frost" }));
}
