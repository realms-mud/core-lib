//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Monastic Archery Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The discipline of measured bow releases. Lessons require "
        "instruction; combat techniques require a primary bow and consume an "
        "arrow through the normal consumables system.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addSpecification("research type", "tree root");
}
