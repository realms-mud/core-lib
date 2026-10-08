//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected void Setup()
{
    addPrerequisite("Chen's trust", ([
        "type":"relationship",
        "direction":"from",
        "target":getService("relationship")->identity(
            load_object("/lib/tests/support/relationships/npc.c")),
        "dimension":"trust",
        "minimum":10
    ]));
    addPrerequisite("Chen's respect", ([
        "type":"relationship",
        "direction":"from",
        "target":getService("relationship")->identity(
            load_object("/lib/tests/support/relationships/npc.c")),
        "dimension":"respect",
        "minimum":5
    ]));
    addSpecification("name", "Chen's lesson");
    addSpecification("description", "An earned lesson.");
    addSpecification("source", "test");
    addSpecification("research type", "granted");
}
