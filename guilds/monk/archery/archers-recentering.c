//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Archer's Recentering", "Spend eight spell points "
        "and six stamina to restore a modest amount of your own health "
        "with a primary bow. No arrow is consumed.",
        20, 3, "draw-recovery", "archery");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 24);
    addSpecification("command template", "kata archer's recentering");
    addSpecification("usage summary", "kata archer's recentering");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":12, "range":3 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.1 ])
    }));
}
