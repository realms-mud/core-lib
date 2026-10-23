//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Meridian Lore", "Knowledge of concentration pathways "
        "adds three points to Sapping Palm's spell-point drain.", 15,
        "sapping-palm", "unarmed", "Sapping Palm", "bonus", 3);
}
