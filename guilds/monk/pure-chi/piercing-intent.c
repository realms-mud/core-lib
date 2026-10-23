//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Piercing Intent", "Disrupt an opponent's spell-point "
        "reserve instead of wounding flesh. Spellcraft locates the current.",
        20, 3, "/guilds/monk/pure-chi/resonance-theory.c", ([]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 14);
    addSpecification("cooldown", 24);
    addSpecification("command template", "chi piercing intent at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## pierce##InitiatorReflexive## "
        "##TargetName##'s current with focused intent.");
    addSpecification("damage type", "energy");
    addSpecification("damage spell points", ({
        ([ "probability":100, "base damage":16, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"spellcraft",
            "formula":"additive", "rate":0.15 ]),
        ([ "type":"attribute", "name":"intelligence",
            "formula":"additive", "rate":0.15 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/channel-economy.c":2 ]));
}
