//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("shallow ford");
    addAlias("ford");
    addDescriptionTemplate("a shallow ford across a rocky woodland stream");
    addNearDarkDescriptionTemplate("a low crossing in the stream");
    addLowLightDescriptionTemplate("water running over a stony crossing");
    addDimLightDescriptionTemplate(
        "a shallow ford marked by stones on either bank");
    addSomeLightDescriptionTemplate(
        "the road dips through a shallow, stony ford");
    addItemTemplate("The road descends to a broad shelf of gravel where "
        "the ravine creek can be crossed on foot. Marker stones show the "
        "shallowest line; after heavy rain, the current covers the shelf "
        "and the crossing is unsafe.");

    addTimeOfDayDescription("dawn", ({ " carrying a skin of mist" }));
    addTimeOfDayDescription("morning", ({ " clear over the pale stones" }));
    addTimeOfDayDescription("noon", ({ " bright beneath the moving water" }));
    addTimeOfDayDescription("afternoon", ({ " quickened by runoff" }));
    addTimeOfDayDescription("evening", ({ " darkening beneath the trees" }));
    addTimeOfDayDescription("dusk", ({ " audible beyond the road" }));
    addTimeOfDayDescription("night", ({ " marked by the rush of water" }));
    addTimeOfDayDescription("midnight", ({ " cold and swift in darkness" }));

    addSeasonDescription("spring", ({ " swollen with meltwater" }));
    addSeasonDescription("summer", ({ " broken by dry gravel bars" }));
    addSeasonDescription("autumn", ({ " colored by fallen leaves" }));
    addSeasonDescription("winter", ({ " edged with dangerous ice" }));
}
