//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("Eolach forester's board");
    addAlias("forester's notice board");
    addAlias("timber notice");
    addAdjectives(({ "weathered", "official", "wooden", "nail-studded" }));

    addDescriptionTemplate("a ##Adjective## forester's board beside the track");
    addItemTemplate("A posted boundary sketch marks the tenant fields, the "
        "managed ash coppice, and the protected yew stand. Winter cutting "
        "dates are listed below the house seal. A fresh notice asks travelers "
        "to report unmarked stumps or carts carrying timber after dusk.");
    addSomeLightDescriptionTemplate(
        "Eolach's forester's board carries a boundary map and notices");
    addDimLightDescriptionTemplate(
        "a board beside the road is covered in posted sheets");
    addLowLightDescriptionTemplate(
        "a weathered board stands near the turning in the track");
    addNearDarkDescriptionTemplate(
        "a broad wooden shape stands beside the road");

    addTimeOfDayDescription("dawn", ({ " darkened by mist" }));
    addTimeOfDayDescription("morning", ({ " bright with fresh postings" }));
    addTimeOfDayDescription("noon", ({ " warm in the direct sunlight" }));
    addTimeOfDayDescription("afternoon", ({ " shadowed by the nearby trees" }));
    addTimeOfDayDescription("evening", ({ " catching the last light" }));
    addTimeOfDayDescription("dusk", ({ " hard to read in the fading light" }));
    addTimeOfDayDescription("night", ({ " barely visible beside the track" }));
    addTimeOfDayDescription("midnight", ({ " still beneath the night sky" }));

    addSeasonDescription("spring", ({ " flecked with rain" }));
    addSeasonDescription("summer", ({ " faded by the sun" }));
    addSeasonDescription("autumn", ({ " edged with fallen leaves" }));
    addSeasonDescription("winter", ({ " rimed with frost" }));
}
