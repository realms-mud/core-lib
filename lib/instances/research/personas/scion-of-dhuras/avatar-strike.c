//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar Strike");
    addSpecification("description", "A weapon channels the power of an elemental avatar.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "fire");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 35, "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "avatarstrike at ##Target##");
    addSpecification("use ability message", "Elemental force bursts against ##TargetName##.");
}
