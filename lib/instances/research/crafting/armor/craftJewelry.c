//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Jewelry");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft jewelry.");
    addSpecification("research type", "granted");
}
