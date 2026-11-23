//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("field drain");
    addAlias("drainage channel");
    addAlias("field ditch");
    addDescriptionTemplate("a shallow field drain cut between crop rows");
    addNearDarkDescriptionTemplate("a narrow dip along the field edge");
    addLowLightDescriptionTemplate("a shallow channel beside the road");
    addDimLightDescriptionTemplate("a field drain edged with cut grass");
    addSomeLightDescriptionTemplate("a maintained channel between tenant fields");
    addItemTemplate("The shallow channel follows the slope between tenant "
        "fields, carrying rainwater toward the lower ground. Small stone "
        "checks slow the flow and keep the furrows from washing into the "
        "estate road. The tenants clear it before the spring rains.");

    addTimeOfDayDescription("dawn", ({ " holding beads of dew" }));
    addTimeOfDayDescription("morning", ({ " trickling after the night rain" }));
    addTimeOfDayDescription("noon", ({ " mostly dry in the sun" }));
    addTimeOfDayDescription("afternoon", ({ " shadowed by its grassy banks" }));
    addTimeOfDayDescription("evening", ({ " darkening beneath the field edge" }));
    addTimeOfDayDescription("dusk", ({ " murmuring with a little runoff" }));
    addTimeOfDayDescription("night", ({ " carrying water quietly downhill" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the dark fields" }));

    addSeasonDescription("spring", ({ " running with rain and meltwater" }));
    addSeasonDescription("summer", ({ " nearly dry beneath the crops" }));
    addSeasonDescription("autumn", ({ " carrying water from the harvested fields" }));
    addSeasonDescription("winter", ({ " rimmed with ice along its banks" }));
}
