//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Cleansing Breath", "Spend chi to clear alcohol and drugs "
        "from your body. This does not remove diseases or magical curses.",
        15, 2, "/guilds/monk/pure-chi/circulation-theory.c", ([]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 40);
    addSpecification("command template", "chi cleansing breath");
    addSpecification("use ability message",
        "##InitiatorName## exhale##InitiatorReflexive## a cleansing breath.");
    addSpecification("decrease intoxication", ({
        ([ "probability":100, "base damage":8, "range":2 ]) }));
    addSpecification("decrease druggedness", ({
        ([ "probability":100, "base damage":8, "range":2 ]) }));
}
