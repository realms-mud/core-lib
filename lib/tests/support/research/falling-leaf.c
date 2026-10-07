//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "falling-leaf");
    addSpecification("description", "A sweeping kata.");
    addSpecification("source", "monk");
    addSpecification("research type", "granted");
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("command template", "falling leaf at ##Target##");
    addSpecification("observation type", "combat.kata");
    addSpecification("damage type", "bludgeon");
    addSpecification("damage stamina points", ({ ([
        "probability": 100,
        "base damage": 1,
        "range": 0
    ]) }));
}