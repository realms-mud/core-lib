//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return instantaneousActiveResearchItem::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Fixed Damage Effect");
    addSpecification("source", "test");
    addSpecification("description", "This is a test constructed research "
        "effect component with a fixed (non-random) damage formula, used to "
        "validate deterministic multiplier and modifier math.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
        "probability": 100,
        "base damage": 20,
        "range": 0
    ]) }));

    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.25
        ])
    }));
}
