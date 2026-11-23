//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Measured Force");
    addSpecification("description", "A measured pulse of Bilanx's power strikes a foe.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 20, "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "measuredforce at ##Target##");
    addSpecification("use ability message", "A balanced pulse of energy hits ##TargetName##.");
}
