//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Troops");
    addSpecification("source", "domains");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to form armies, use formations, and assign "
        "activities.");
    addSpecification("research type", "granted");
}
