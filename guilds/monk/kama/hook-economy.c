//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Hook Economy", "Avoid unnecessary tension during "
        "a controlled cut: Measured Hook costs two less stamina.",
        15, "hook-geometry", "kama", "Measured Hook", "decrease cost", 2);
}
