//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Pulse Mapping", "Recognizing vulnerable rhythms adds "
        "three points to Meridian Strike's spell-point drain.", 25,
        "meridian-strike", "unarmed", "Meridian Strike", "bonus", 3);
}
