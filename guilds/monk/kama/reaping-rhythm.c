//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Reaping Rhythm", "Recover the kama smoothly: "
        "Reaping Cut's cooldown is four seconds shorter.",
        20, "reaping-lines", "kama", "Reaping Cut", "decrease cooldown", 4);
}
