//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));
    addSpecification("name", "Bludgeon Foundations");
    addSpecification("description", "The principles of controlled impacts "
        "and recovery with staffs, maces, and hammers. Individual techniques "
        "still require advanced instruction.");
    addSpecification("source", "monk");
    addSpecification("research type", "tree root");
}
