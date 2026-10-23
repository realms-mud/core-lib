//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Still Bow", "Reserve twenty maximum stamina "
        "for +4 bow at a cost of two dodge.",
        30, 3, "archers-mastery", "archery");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata still bow");
    addSpecification("bonus bow", 4);
    addSpecification("penalty to dodge", 2);
}
