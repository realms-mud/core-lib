//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hundred Strikes");
    addSpecification("description", "A rapid flurry overwhelms a single foe.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 20);
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 55, "range": 45
    ]) }));
    addSpecification("cooldown", 30);
    addSpecification("command template", "hundredstrikes at ##Target##");
    addSpecification("use ability message", "A flurry of strikes crashes into ##TargetName##.");
}
