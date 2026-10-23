//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Stillness", "Reserve twenty-two maximum "
        "stamina for +4 two-handed sword and +2 parry at a cost of two "
        "dodge.", 30, 4, "longblade-mastery", "odachi");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 22);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata longblade stillness");
    addSpecification("bonus two-handed sword", 4);
    addSpecification("bonus parry", 2);
    addSpecification("penalty to dodge", 2);
}
