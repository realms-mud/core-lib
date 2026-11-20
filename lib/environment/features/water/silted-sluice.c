//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("silted sluice");
    addAlias("garden water");
    addAlias("settling ditch");
    addDescriptionTemplate("a narrow sluice clogged with fine stone silt");
    addItemTemplate("A shallow channel should settle runoff before "
        "it reaches the stream. Fine silt has blocked it, cutting "
        "a bypass through its bank. An assigned inquiry can "
        "investigate garden water or the settling ditch.");
    addNearDarkDescriptionTemplate("a dark depression in the ground");
    addLowLightDescriptionTemplate("a shallow drainage channel");
    addDimLightDescriptionTemplate("a ditch edged with pale sediment");
    addSomeLightDescriptionTemplate("a silted channel with an eroded bypass");
    addTimeOfDayDescription("dawn", ({ " misted above the cold water" }));
    addTimeOfDayDescription("morning", ({ " showing pale sediment at its edges" }));
    addTimeOfDayDescription("noon", ({ " rippling in the open light" }));
    addTimeOfDayDescription("afternoon", ({ " shadowed beneath its banks" }));
    addTimeOfDayDescription("evening", ({ " darkening in the low light" }));
    addTimeOfDayDescription("dusk", ({ " murmuring through the dimness" }));
    addTimeOfDayDescription("night", ({ " audible beneath the banks" }));
    addTimeOfDayDescription("midnight", ({ " running quietly through the silt" }));
    addSeasonDescription("spring", ({ " swollen by runoff" }));
    addSeasonDescription("summer", ({ " low between drying banks" }));
    addSeasonDescription("autumn", ({ " catching leaves against the obstruction" }));
    addSeasonDescription("winter", ({ " rimmed with ice" }));
}
