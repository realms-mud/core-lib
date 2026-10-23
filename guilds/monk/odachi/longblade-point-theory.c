//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Longblade Point Theory", "Support the long thrust "
        "with the whole body: adds three to Long Point's thrust damage.",
        20, "long-point", "odachi", "Long Point", "bonus", 3);
}
