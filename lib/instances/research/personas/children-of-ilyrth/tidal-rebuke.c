//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tidal Rebuke");
    addSpecification("description", "Ilyrth's power turns the tide against a foe.");
    addSpecification("effect", "combat");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("spell point cost", 12);
    addSpecification("damage type", "water");
    addSpecification("damage hit points", ({ ([
        "probability": 100, "base damage": 35, "range": 30
    ]) }));
    addSpecification("cooldown", 12);
    addSpecification("command template", "tidalrebuke at ##Target##");
    addSpecification("use ability message", "A churning tide sweeps over ##TargetName##.");
}
