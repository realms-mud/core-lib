//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battle Charge");
    addSpecification("description", "A driving charge breaks through a foe's guard.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 20, "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "battlecharge at ##Target##");
    addSpecification("use ability message", "A forceful charge strikes ##TargetName##.");
}
