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
    addSpecification("name", "Test Fixed Heal Effect");
    addSpecification("source", "test");
    addSpecification("description", "This is a test constructed research "
        "effect component with a fixed (non-random) heal formula, used to "
        "validate that beneficial effects are also applied correctly.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);

    addSpecification("increase hit points", ({ ([
        "probability": 100,
        "base damage": 15,
        "range": 0
    ]) }));
}
