//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Still Edge", "Reserve fourteen maximum stamina for "
        "+4 sword skill and +2 parry; landed hits cost one spell point.",
        25, 3, "unwavering-eye", "katana");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata still edge");
    addSpecification("bonus hand and a half sword", 4);
    addSpecification("bonus parry", 2);
    addSpecification("per hit landed cost", ([ "spell points":1 ]));
}
