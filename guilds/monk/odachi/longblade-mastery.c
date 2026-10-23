//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Mastery", "Unify grip, footing, and "
        "recovery: +2 two-handed sword.", 30, 4,
        "longblade-composure", "odachi");
    addSpecification("bonus two-handed sword", 2);
}
