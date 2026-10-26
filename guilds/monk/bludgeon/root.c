//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bludgeon Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The staff and the heavy head teach the same patient "
        "lesson: weight must be understood before it is "
        "commanded. Begin with balance, contact, and the return.");


    addSpecification("research type", "tree root");
}
