//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Infantry Research I");
    addSpecification("source", "domains");
    addSpecification("description", "This research provides the user with the "
        "knowledge required to enhance infantry units, use formations, and assign "
        "activities.");
    addSpecification("research type", "granted");
}
