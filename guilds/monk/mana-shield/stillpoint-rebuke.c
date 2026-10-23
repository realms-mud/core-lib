//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Stillpoint Rebuke", "Launch a deliberate master-level "
        "rebuke from your ward's still center, harming flesh and energy "
        "without reflecting or storing incoming damage.",
        30, 4, "/guilds/monk/mana-shield/interrupting-thread.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 28);
    addSpecification("cooldown", 50);
    addSpecification("command template", "chi stillpoint rebuke at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## release##InitiatorReflexive## a stillpoint "
        "rebuke into ##TargetName##.");
    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":28, "range":6 ]) }));
    addSpecification("damage spell points", ({
        ([ "probability":100, "base damage":10, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.12 ]),
        ([ "type":"skill", "name":"spellcraft",
            "formula":"additive", "rate":0.1 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/conservation-of-motion.c":2 ]));
}
