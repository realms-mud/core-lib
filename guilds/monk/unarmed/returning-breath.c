//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Returning Breath", "Spend twelve spell points and "
        "eight stamina on a master's self-restoration.", 30, 3,
        "breath-economy", "unarmed");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 12);
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 24);
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/unarmed/returning-rhythm.c":4
    ]));
    addSpecification("command template", "kata returning breath");
    addSpecification("usage summary", "kata returning breath");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":20, "range":4 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.15 ])
    }));
}
