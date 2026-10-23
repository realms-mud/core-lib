//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Guard Breaker", "Repeated pressure drains stamina "
        "without automatically lowering armor or preventing defense.", 20,
        "hilt-leverage", "katana", "damage stamina points", 18, 4, 10, 16,
        "guard-pressure");
}
