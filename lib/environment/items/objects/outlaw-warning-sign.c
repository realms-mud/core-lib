//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("warning sign");
    addAlias("outlaw warning sign");
    addAlias("sign");
    addDescriptionTemplate("a warning sign nailed to a split post");
    addNearDarkDescriptionTemplate("a dark post beside the track");
    addLowLightDescriptionTemplate("a sign on a split post");
    addDimLightDescriptionTemplate("a weathered warning sign");
    addSomeLightDescriptionTemplate("a warning sign nailed to a split post");
    addItemTemplate("The rough-painted warning reads, \"Keep to the main "
        "trail. Armed road thieves have been seen beyond this point.\"");
    addTimeOfDayDescription("dawn", ({ " damp with the morning mist" }));
    addTimeOfDayDescription("noon", ({ " faded in the direct sunlight" }));
    addTimeOfDayDescription("dusk", ({ " dark against the fading light" }));
    addTimeOfDayDescription("night", ({ " barely visible in the darkness" }));
    addSeasonDescription("spring", ({ " flecked with rain" }));
    addSeasonDescription("summer", ({ " faded by the sun" }));
    addSeasonDescription("autumn", ({ " edged with fallen leaves" }));
    addSeasonDescription("winter", ({ " rimed with frost" }));
}
