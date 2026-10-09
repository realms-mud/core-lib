//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
public int testAddSpecification(string type, mixed value)
{
    return constructedResearchComponent::addSpecification(type, value);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Test High Multiplier Component");
    addSpecification("source", "test");
    addSpecification("description", "This is a test constructed research "
        "component used to validate a large constructed spell multiplier.");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
    addSpecification("affected research type", "percentage");
    addSpecification("affected research",
        (["Constructed Spell Multiplier": 50]));
}
