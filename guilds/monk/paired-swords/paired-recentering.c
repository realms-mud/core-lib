//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Recentering", "Spend eight spell points and "
        "six stamina to restore a modest amount of your own health while "
        "holding the correct pair.", 20, 3, "paired-recovery",
        "paired-swords");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 24);
    addSpecification("command template", "kata paired recentering");
    addSpecification("usage summary", "kata paired recentering");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":12, "range":3 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.1 ])
    }));
}
