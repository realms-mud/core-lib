//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Flowing Stance", "Reserve fourteen maximum stamina for "
        "+4 unarmed and +2 dodge; landed hits cost one spell point.", 25, 3,
        "supple-form", "unarmed");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata flowing stance");
    addSpecification("bonus unarmed", 4);
    addSpecification("bonus dodge", 2);
    addSpecification("per hit landed cost", ([ "spell points":1 ]));
}
