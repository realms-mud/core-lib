//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Needle Thrust", "A deliberately aligned thrust exchanges "
        "damage variance for a longer recovery.", 20, "measured-distance",
        "katana", "damage hit points", 22, 2, 12, 14, "point-alignment");
    addSpecification("damage type", "thrust");
}
