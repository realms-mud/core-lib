//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Interrupting Thread", "Cast a fine thread from the "
        "ward's stable boundary to disrupt an opponent's spell points. "
        "It does not silence commands or cancel casting.",
        20, 3, "/guilds/monk/mana-shield/disruption-theory.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 14);
    addSpecification("cooldown", 30);
    addSpecification("command template",
        "chi interrupting thread at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## cast##InitiatorReflexive## a disruptive "
        "thread of chi toward ##TargetName##.");
    addSpecification("damage type", "energy");
    addSpecification("damage spell points", ({
        ([ "probability":100, "base damage":16, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"spellcraft",
            "formula":"additive", "rate":0.12 ]),
        ([ "type":"attribute", "name":"intelligence",
            "formula":"additive", "rate":0.12 ]) }));
}
