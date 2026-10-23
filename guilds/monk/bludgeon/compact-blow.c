//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Compact Blow", "Deliver a short mace blow from a closed "
        "guard. A narrow damage range rewards accuracy and mace skill "
        "without claiming armor penetration.", 15, 2,
        "/guilds/monk/bludgeon/close-haft-grip.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 7);
    addSpecification("cooldown", 9);
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/bludgeon/mace-head-alignment.c":1
    ]));
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/mace-recovery.c":1
    ]));
    addSpecification("command template", "kata compact blow at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "land##InitiatorReflexive## a compact mace blow on ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":10, "range":2 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"mace",
            "formula":"additive", "rate":0.06 ]),
        ([ "type":"attribute", "name":"dexterity",
            "formula":"additive", "rate":0.1 ]),
        ([ "type":"research", "name":"contact geometry",
            "research item":"/guilds/monk/bludgeon/contact-geometry.c",
            "base value":1, "formula":"multiplicative", "rate":1.1 ])
    }));
}
