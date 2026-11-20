//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/quests/local-quest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("Roots Beside the Stream");
    setDescription("Herbalist Edda will not use a new batch of roots "
        "until the cloudy garden water has been investigated.");
    addState("started", "Edda asked me to inspect the garden water.");
    addState("water checked", "The garden sluice carries fine quarry "
        "silt; there is no reason to blame the plants.");
    addState("source checked", "A blocked settling ditch diverts "
        "runoff into the garden's stream.");
    addState("ready", "The spring above the workings remains clear. "
        "The problem can be addressed without promising a miracle cure.");
    addTransition("started", "water checked", "inspectGardenWater");
    addTransition("water checked", "source checked", "inspectSettlingDitch");
    addTransition("source checked", "ready", "inspectClearSpring");
    addResolution("ditch repair", "Edda arranged ditch maintenance "
        "with the quarry crew and withheld the tainted crop.",
        "arrangeDitchRepair");
    addResolution("clean supply", "Edda arranged spring-water deliveries "
        "and kept the affected beds out of use pending repairs.",
        "arrangeCleanWater");
    setInitialState("started");
}
