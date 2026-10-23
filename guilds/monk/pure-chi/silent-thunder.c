//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Silent Thunder", "Concentrate a master's intent into "
        "a single costly energy strike. Unified Current multiplies its "
        "base power; wisdom and essence provide smaller additions.",
        30, 4, "/guilds/monk/pure-chi/unified-current.c", ([]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 32);
    addSpecification("cooldown", 60);
    addSpecification("command template", "chi silent thunder at ##Target##");
    addSpecification("use ability message",
        "Silent thunder blooms between ##InitiatorName## "
        "and ##TargetName##.");
    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":44, "range":10 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"magical essence",
            "formula":"additive", "rate":0.15 ]),
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.15 ]),
        ([ "type":"research", "name":"Unified Current",
            "research item":"/guilds/monk/pure-chi/unified-current.c",
            "base value":110, "formula":"multiplicative", "rate":0.01 ]) }));
}
