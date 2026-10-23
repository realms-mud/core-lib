//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Committed Cut", "Commit the odachi to one heavy cut "
        "with substantial stamina expenditure and deliberate recovery.",
        10, "longblade-grip", "odachi", "damage hit points",
        22, 0, 14, 18, "commitment-theory");
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/odachi/longblade-economy.c":2
    ]));
}
