//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Low Guard", "Reserve twelve maximum stamina for "
        "+2 soak and +1 dodge, sacrificing two attack.", 20, 3,
        "traveling-guard", "katana");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata low guard");
    addSpecification("bonus soak", 2);
    addSpecification("bonus dodge", 1);
    addSpecification("penalty to attack", 2);
}
