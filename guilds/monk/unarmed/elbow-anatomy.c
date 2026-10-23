//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Elbow Anatomy", "Anatomical placement adds three points "
        "to Driving Elbow's damage formula.", 10, "driving-elbow",
        "unarmed", "Driving Elbow", "bonus", 3);
}
