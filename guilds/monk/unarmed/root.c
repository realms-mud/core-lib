//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unarmed Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The principles of deliberate, empty-hand movement. This foundation "
        "opens the unarmed curriculum; individual forms still require "
        "instruction and demonstrated practice.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addSpecification("research type", "tree root");
}
