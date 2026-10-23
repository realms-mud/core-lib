//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Mastery", "Unify curved cuts and patient "
        "recovery: +2 short sword.", 30, 1, "sickle-composure", "kama");
    addSpecification("bonus short sword", 2);
}
