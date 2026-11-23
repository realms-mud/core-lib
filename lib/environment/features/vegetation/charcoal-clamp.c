//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("charcoal clamp");
    addAlias("charcoal mound");
    addDescriptionTemplate(
        "a low charcoal clamp covered with turf and packed earth");
    addNearDarkDescriptionTemplate("a dark earthen mound");
    addLowLightDescriptionTemplate("a low mound with faint smoke");
    addDimLightDescriptionTemplate(
        "a turf-covered charcoal clamp beside the woodland road");
    addSomeLightDescriptionTemplate(
        "a charcoal clamp with narrow vents cut through its cover");
    addItemTemplate("Layered hardwood smolders slowly beneath the turf. "
        "The burner has left small vents open to control the draft, and "
        "a thin blue thread of smoke escapes near the crown. The mound "
        "must cool before its charcoal can be gathered.");

    addTimeOfDayDescription("dawn", ({ " breathing a thread of blue smoke" }));
    addTimeOfDayDescription("morning", ({ " watched from the nearby track" }));
    addTimeOfDayDescription("noon", ({ " warm beneath its earthen cover" }));
    addTimeOfDayDescription("afternoon", ({ " smelling faintly of smoke" }));
    addTimeOfDayDescription("evening", ({ " glowing at its vent" }));
    addTimeOfDayDescription("dusk", ({ " watched closely by its burner" }));
    addTimeOfDayDescription("night", ({ " smoldering under the dark trees" }));
    addTimeOfDayDescription("midnight", ({ " warm beneath the cool air" }));

    addSeasonDescription("spring", ({ " ringed by fresh shoots" }));
    addSeasonDescription("summer", ({ " shaded beneath the woodland edge" }));
    addSeasonDescription("autumn", ({ " surrounded by damp fallen leaves" }));
    addSeasonDescription("winter", ({ " kept clear of snow around its vents" }));
}
