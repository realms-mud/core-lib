//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Taxing Contact", "Repeatedly load the opponent's guard "
        "through one firm contact, dealing modest injury and stamina "
        "damage. This neither stuns nor disarms.", 20, 3,
        "/guilds/monk/bludgeon/mace-recovery.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("stamina point cost", 11);
    addSpecification("cooldown", 15);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/bludgeon/mace-recovery.c":1
    ]));
    addSpecification("command template", "kata taxing contact at ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "drive##InitiatorReflexive## a taxing mace contact at ##TargetName##.");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":5, "range":2 ])
    }));
    addSpecification("damage stamina points", ({
        ([ "probability":100, "base damage":9, "range":3 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"strength",
            "formula":"additive", "rate":0.1 ]),
        ([ "type":"skill", "name":"mace",
            "formula":"additive", "rate":0.03 ])
    }));
}
