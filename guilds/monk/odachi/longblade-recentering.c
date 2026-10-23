//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Recentering", "Spend ten spell points "
        "and eight stamina to restore a modest amount of your own health "
        "while wielding the odachi.", 20, 3, "longblade-recovery", "odachi");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 10);
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 30);
    addSpecification("command template", "kata longblade recentering");
    addSpecification("usage summary", "kata longblade recentering");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":16, "range":3 ])
    }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"constitution",
            "formula":"additive", "rate":0.1 ])
    }));
}
