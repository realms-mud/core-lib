//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Returning Rhythm", "A complete breathing cycle reduces "
        "Returning Breath's cooldown by four seconds.", 30,
        "returning-breath", "unarmed", "Returning Breath",
        "decrease cooldown", 4);
}
