//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stonebreaker");
    addSpecification("description", "A weapon strike fractures defenses like stone.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 35, "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "stonebreaker at ##Target##");
    addSpecification("use ability message", "A stone-hard blow slams into ##TargetName##.");
}
