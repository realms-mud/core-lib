//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stringed Instruments");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "basic knowledge of creating spell-like effects with stringed "
        "instruments.");

    addSpecification("scope", "self");
    addSpecification("research type", "tree root");
}
