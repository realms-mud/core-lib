//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("broken cart");
    addAlias("cart");
    addAlias("wheel");
    addDescriptionTemplate("a cart resting on a broken wheel hub");
    addItemTemplate("The wheel has failed at the hub. Its harness "
        "was unbuckled and laid on the seat, not cut apart. One "
        "wooden slat has been removed from the side. You can "
        "investigate the broken cart when tracing its occupants.");
    addNearDarkDescriptionTemplate("a low shape beside the track");
    addLowLightDescriptionTemplate("the tilted outline of a cart");
    addDimLightDescriptionTemplate("a cart leaning on a broken wheel");
    addSomeLightDescriptionTemplate("a disabled cart with a coiled harness");
    addTimeOfDayDescription("dawn", ({ " wet with dew along its rails" }));
    addTimeOfDayDescription("morning", ({ " showing the pale break in its hub" }));
    addTimeOfDayDescription("noon", ({ " casting a crooked shadow" }));
    addTimeOfDayDescription("afternoon", ({ " warm along its wooden seat" }));
    addTimeOfDayDescription("evening", ({ " shaded beside the old track" }));
    addTimeOfDayDescription("dusk", ({ " becoming a dark roadside shape" }));
    addTimeOfDayDescription("night", ({ " motionless beside the road" }));
    addTimeOfDayDescription("midnight", ({ " silent beneath the night sky" }));
    addSeasonDescription("spring", ({ " with mud pressed around the failed wheel" }));
    addSeasonDescription("summer", ({ " dusty beneath its axles" }));
    addSeasonDescription("autumn", ({ " catching leaves in its open bed" }));
    addSeasonDescription("winter", ({ " rimed with frost along its rails" }));
}
