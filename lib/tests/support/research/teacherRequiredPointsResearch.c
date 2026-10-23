//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

public int TestAddSpecification(string key, mixed value)
{
    return addSpecification(key, value);
}

protected void Setup()
{
    addSpecification("name", "a taught lesson");
    addSpecification("description", "A point-based lesson for teacher tests.");
    addSpecification("source", "test");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);
}
