//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Odachi Foundations");
    addSpecification("source", "monk");
    addSpecification("description",
        "The discipline of committed odachi cuts and deliberate recovery. "
        "Individual lessons require instruction and the actual odachi "
        "blueprint.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));

    addSpecification("research type", "tree root");
}
