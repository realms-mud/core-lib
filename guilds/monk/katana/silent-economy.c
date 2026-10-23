//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Silent Economy", "A master's economy reduces Silent "
        "Edge's authored stamina cost by three.", 30, "silent-edge",
        "katana", "Silent Edge", "decrease cost", 3);
}
