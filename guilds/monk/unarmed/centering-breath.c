//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Centering Breath", "Spend eight stamina to restore "
        "a small amount of your own health while empty-handed.", 10, 3,
        "guarded-breath", "unarmed");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 18);
    addSpecification("command template", "kata centering breath");
    addSpecification("usage summary", "kata centering breath");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":8, "range":3 ])
    }));
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/unarmed/breath-economy.c":2
    ]));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"constitution",
            "formula":"additive", "rate":0.1 ]),
        ([ "type":"research", "name":"Restorative Breath",
            "research item":"/guilds/monk/unarmed/restorative-breath.c",
            "formula":"additive", "base value":1, "rate":3.0 ])
    }));
}
