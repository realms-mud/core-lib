//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Smolder Intensity");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the number of times Smolder's flames strike "
        "the target.");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", (["Smolder": 2]));
    addSpecification("affected research type", "increase repeat effect");
}
