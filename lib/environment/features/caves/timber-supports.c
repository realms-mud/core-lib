//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/features/baseFeature.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("gallery timber supports");
    addAlias("upper props");
    addAlias("supports");
    addDescriptionTemplate("heavy timber props supporting the upper passage");
    addItemTemplate("Fitted crosspieces transfer the roof's weight "
        "to stout uprights. Inspection marks distinguish this "
        "supported approach from lower, shifted timbers. An "
        "assigned survey can investigate the upper props.");
    addNearDarkDescriptionTemplate("heavy shapes along the passage");
    addLowLightDescriptionTemplate("uprights beneath the cave roof");
    addDimLightDescriptionTemplate("timber props beneath fitted crosspieces");
    addSomeLightDescriptionTemplate("marked timber supports in the dry passage");
    addTimeOfDayDescription("dawn", ({ " quiet beneath the rock" }));
    addTimeOfDayDescription("morning", ({ " dry on the sheltered side" }));
    addTimeOfDayDescription("noon", ({ " beyond the reach of daylight" }));
    addTimeOfDayDescription("afternoon", ({ " faintly creaking as water drips" }));
    addTimeOfDayDescription("evening", ({ " shadowed beneath the roof" }));
    addTimeOfDayDescription("dusk", ({ " still in the sheltered passage" }));
    addTimeOfDayDescription("night", ({ " holding the dark roof above" }));
    addTimeOfDayDescription("midnight", ({ " quiet except for occasional drips" }));
    addSeasonDescription("spring", ({ " darkened by increased seepage" }));
    addSeasonDescription("summer", ({ " cool beneath the dry crosspieces" }));
    addSeasonDescription("autumn", ({ " inspected after the heavy rains" }));
    addSeasonDescription("winter", ({ " sheltered from the outside frost" }));
}
