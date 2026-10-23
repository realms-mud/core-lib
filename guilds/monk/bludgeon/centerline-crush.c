//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Centerline Crush", "Commit the mace head along a direct "
        "centerline for a deliberate master-level blow. Its long recovery "
        "and stamina demand trade frequency for contact force.", 30, 4,
        "/guilds/monk/bludgeon/contact-geometry.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 22);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/mace-recovery.c":1
    ]));
    addSpecification("command template", "kata centerline crush at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "deliver##InitiatorReflexive## a centerline crush to ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":19, "range":4 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"weapon damage", "name":"mace",
            "types":({ "mace" }), "formula":"additive", "rate":0.5 ]),
        ([ "type":"attribute", "name":"strength",
            "formula":"additive", "rate":0.15 ]),
        ([ "type":"research", "name":"contact geometry",
            "research item":"/guilds/monk/bludgeon/contact-geometry.c",
            "base value":1, "formula":"multiplicative", "rate":1.1 ])
    }));
}
