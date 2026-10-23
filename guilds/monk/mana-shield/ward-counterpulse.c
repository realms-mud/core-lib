//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Ward Counterpulse", "Deliberately project chi from a "
        "stable ward. It spends spell points normally and neither stores "
        "nor reflects previously absorbed damage.",
        20, 3, "/guilds/monk/mana-shield/disruption-theory.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 16);
    addSpecification("cooldown", 28);
    addSpecification("command template", "chi ward counterpulse at ##Target##");
    addSpecification("use ability message",
        "A measured counterpulse arcs from ##InitiatorName## "
        "toward ##TargetName##.");
    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":24, "range":6 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"magical essence",
            "formula":"additive", "rate":0.12 ]),
        ([ "type":"research", "name":"Lucid Refuge",
            "research item":"/guilds/monk/mana-shield/lucid-refuge.c",
            "base value":110, "formula":"multiplicative", "rate":0.01 ]) }));
}
