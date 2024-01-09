//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lyrical Components");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge of creating spell-like effects with lyrics.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
}
