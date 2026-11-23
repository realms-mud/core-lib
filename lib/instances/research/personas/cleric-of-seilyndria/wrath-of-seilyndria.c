//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wrath of Seilyndria");
    addSpecification("description", "A wave of divine fury punishes "
        "Seilyndria's enemies.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 20);
    addSpecification("damage type", "fire");
    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 55,
        "range": 45
    ]) }));
    addSpecification("damage spell points", ({ ([
        "probability": 100,
        "base damage": 25,
        "range": 20
    ]) }));
    addSpecification("cooldown", 30);
    addSpecification("command template", "wrathofseilyndria at ##Target##");
    addSpecification("use ability message",
        "Seilyndria's wrath engulfs ##TargetName## in flame.");
}
