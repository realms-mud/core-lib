//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Crane Stance", "Reserve eight maximum stamina for "
        "+3 dodge; each received hit costs one spell point.", 10, 3,
        "quiet-footwork", "unarmed");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata crane stance");
    addSpecification("bonus dodge", 3);
    addSpecification("per hit received cost", ([ "spell points":1 ]));
}
