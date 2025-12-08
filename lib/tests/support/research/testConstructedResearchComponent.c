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
    addSpecification("name", "Test Constructed Component");
    addSpecification("source", "test");
    addSpecification("description", "This is a test constructed research component.");
    addSpecification("research type", "granted");
    addSpecification("research cost", 1);
}
