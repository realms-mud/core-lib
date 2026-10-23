//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Recentering", "Spend eight spell points "
        "and six stamina to restore modest health with primary tiger claws.",
        20, 3, "claw-recovery", "claw");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 22);
    addSpecification("command template", "kata claw recentering");
    addSpecification("usage summary", "kata claw recentering");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":10, "range":3 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.1 ])
    }));
}
