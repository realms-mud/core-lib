//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("harbor refuge");
    setFloorPlanType("trade");
    addAlias("refuge");
    addDescriptionTemplate("a sheltered harbor refuge with broad wooden doors");
    addItemTemplate("A weatherproof hall provides dry beds, water, "
        "and a hearth for crews forced ashore. It is a public "
        "working shelter, not a barracks or an abandoned store.");
    addNearDarkDescriptionTemplate("a broad low silhouette");
    addLowLightDescriptionTemplate("a low hall near the harbor");
    addDimLightDescriptionTemplate("a refuge hall with broad doors");
    addSomeLightDescriptionTemplate("a weatherproof harbor shelter");
    addTimeOfDayDescription("dawn", ({ " quiet beneath the pale sky" }));
    addTimeOfDayDescription("morning", ({ " airing beneath opened shutters" }));
    addTimeOfDayDescription("noon", ({ " shaded along its sheltered entrance" }));
    addTimeOfDayDescription("afternoon", ({ " warm against the harbor wind" }));
    addTimeOfDayDescription("evening", ({ " with hearth light behind the shutters" }));
    addTimeOfDayDescription("dusk", ({ " standing against the darkening bay" }));
    addTimeOfDayDescription("night", ({ " sheltered from the sea wind" }));
    addTimeOfDayDescription("midnight", ({ " quiet beside the harbor" }));
    addSeasonDescription("spring", ({ " with damp cloaks drying under its eaves" }));
    addSeasonDescription("summer", ({ " catching the harbor breeze" }));
    addSeasonDescription("autumn", ({ " stocked for storm-delayed crews" }));
    addSeasonDescription("winter", ({ " protected by heavy draught strips" }));
}
