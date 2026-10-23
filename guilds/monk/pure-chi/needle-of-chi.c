//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Needle of Chi", "Send a thin, quick energy needle instead "
        "of a broad pulse. Geometry improves its carefully aimed point.",
        10, 2, "/guilds/monk/pure-chi/chi-anatomy.c", ([]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 5);
    addSpecification("cooldown", 6);
    addSpecification("command template", "chi needle at ##Target##");
    addSpecification("damage type", "energy");
    addSpecification("use ability message",
        "##InitiatorName## send##InitiatorReflexive## a chi needle "
        "toward ##TargetName##.");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":8, "range":2 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"spellcraft",
            "formula":"additive", "rate":0.12 ]),
        ([ "type":"attribute", "name":"intelligence",
            "formula":"additive", "rate":0.1 ]),
        ([ "type":"research", "name":"Pulse Geometry",
            "research item":"/guilds/monk/pure-chi/pulse-geometry.c",
            "base value":1, "formula":"additive", "rate":2.0 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/economical-breath.c":1 ]));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/pure-chi/stillness-between-pulses.c":1 ]));
}
