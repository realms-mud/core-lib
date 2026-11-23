//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rising Tide");
    addSpecification("description", "A forceful surge of water batters a foe.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "water");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 20, "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "risingtide at ##Target##");
    addSpecification("use ability message", "A rising wave crashes into ##TargetName##.");
}
