//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Vital Reading", "Reading subtle changes of breathing "
        "grants +3 perception in an empty-handed form.", 20, 2,
        "guarded-breath", "unarmed");
    addSpecification("bonus perception", 3);
}
