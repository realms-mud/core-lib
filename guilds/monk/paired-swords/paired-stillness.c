//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Stillness", "Reserve eighteen maximum "
        "stamina for +3 hand and a half sword and +3 short sword at a "
        "cost of two attack.", 30, 4, "paired-mastery", "paired-swords");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata paired stillness");
    addSpecification("bonus hand and a half sword", 3);
    addSpecification("bonus short sword", 3);
    addSpecification("penalty to attack", 2);
}
