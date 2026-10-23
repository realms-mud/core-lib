//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Severing Current", "Cut across body and inner reserve "
        "at once, trading efficiency for disruption of both resources.",
        30, 4, "/guilds/monk/pure-chi/piercing-intent.c", ([]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 24);
    addSpecification("cooldown", 40);
    addSpecification("command template", "chi severing current at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## cut##InitiatorReflexive## across "
        "##TargetName##'s current with a sweeping palm.");
    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":22, "range":6 ]) }));
    addSpecification("damage spell points", ({
        ([ "probability":100, "base damage":12, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"spellcraft",
            "formula":"additive", "rate":0.12 ]),
        ([ "type":"attribute", "name":"intelligence",
            "formula":"additive", "rate":0.1 ]) }));
}
