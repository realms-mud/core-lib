//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno");
    addSpecification("description", "Ferianth's flames erupt in a consuming inferno.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 20);
    addSpecification("damage type", "fire");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 55, "range": 45
    ]) }));
    addSpecification("cooldown", 30);
    addSpecification("command template", "inferno at ##Target##");
    addSpecification("use ability message", "A roaring inferno engulfs ##TargetName##.");
}
