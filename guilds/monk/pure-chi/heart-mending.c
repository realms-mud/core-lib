//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Heart Mending", "Guide a sustained exhalation into "
        "another person's wounds. The chi heals flesh, not their reserves.",
        20, 3, "/guilds/monk/pure-chi/quiet-intervals.c", ([]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 16);
    addSpecification("cooldown", 36);
    addSpecification("command template", "chi heart mending on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## guide##InitiatorReflexive## warm chi "
        "into ##TargetName##'s wounds.");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":26, "range":6 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.25 ]),
        ([ "type":"skill", "name":"magical essence",
            "formula":"additive", "rate":0.12 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/perfect-economy.c":2 ]));
}
