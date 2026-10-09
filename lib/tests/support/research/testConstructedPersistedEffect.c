//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test Persisted Attack Effect");
    addSpecification("source", "test");
    addSpecification("description", "A deterministic constructed buff.");
    addSpecification("scope", "targeted");
    addSpecification("research type", "granted");
    addSpecification("bonus attack", 3);
    addSpecification("duration", 60);
    addSpecification("modifiers", ({ ([
        "type": "attribute",
        "name": "intelligence",
        "formula": "additive",
        "rate": 0.25
    ]) }));
}
