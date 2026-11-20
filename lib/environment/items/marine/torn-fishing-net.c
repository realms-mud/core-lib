//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("torn fishing net");
    addAlias("torn net");
    addAlias("net rack");
    addDescriptionTemplate("a torn fishing net hung from drying rails");
    addItemTemplate("The net's damaged mesh follows worn knots and "
        "frayed lashings. The rails keep it above damp ground, "
        "where small tracks pass beneath it. An assigned inquiry "
        "can investigate the torn net or net rack.");
    addNearDarkDescriptionTemplate("a hanging tangle");
    addLowLightDescriptionTemplate("a loose web hanging from rails");
    addDimLightDescriptionTemplate("a ragged net on wooden rails");
    addSomeLightDescriptionTemplate("a fishing net with frayed, torn mesh");
    addTimeOfDayDescription("dawn", ({ " beaded with dew" }));
    addTimeOfDayDescription("morning", ({ " airing on the rails" }));
    addTimeOfDayDescription("noon", ({ " drying in the breeze" }));
    addTimeOfDayDescription("afternoon", ({ " moving softly against the supports" }));
    addTimeOfDayDescription("evening", ({ " dark along its damp knots" }));
    addTimeOfDayDescription("dusk", ({ " becoming a web of shadows" }));
    addTimeOfDayDescription("night", ({ " hanging quietly" }));
    addTimeOfDayDescription("midnight", ({ " still on its drying rails" }));
    addSeasonDescription("spring", ({ " washed by occasional rain" }));
    addSeasonDescription("summer", ({ " stiff with dried salt" }));
    addSeasonDescription("autumn", ({ " tugged by the cold breeze" }));
    addSeasonDescription("winter", ({ " rimed with frost" }));
}
