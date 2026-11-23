//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Werra's Might");
    addSpecification("description", "Werra lends his strength to a crushing "
        "blow.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "bludgeon");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 35,
        "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "werramight at ##Target##");
    addSpecification("use ability message",
        "A forceful blow lands against ##TargetName##.");
}
