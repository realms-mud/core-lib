//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addSpecification("name", "a timed lesson");
    addSpecification("description", "A timed lesson for teacher tests.");
    addSpecification("source", "test");
    addSpecification("research type", "timed");
    addSpecification("research cost", 6);
    addSpecification("teacher required", 1);
}
