//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Entangle");
    addSpecification("description", "Roots and vines lash out at a foe.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 5);
    addSpecification("damage type", "earth");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 20,
        "range": 20
    ]) }));
    addSpecification("cooldown", 4);
    addSpecification("command template", "entangle at ##Target##");
    addSpecification("use ability message",
        "Roots surge from the earth and lash around ##TargetName##.");
}
