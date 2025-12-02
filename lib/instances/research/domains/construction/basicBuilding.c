//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Basic Building");
    addSpecification("source", "domains");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to oversee simple domain construction projects.");
    addSpecification("research type", "granted");
}
