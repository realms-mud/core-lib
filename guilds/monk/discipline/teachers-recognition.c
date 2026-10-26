//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Teacher's Recognition");
    addSpecification("source", "monk");
    addSpecification("description",
        "Your instructor offers a quiet nod at the end "
        "of practice. It is an acknowledgment of patient "
        "work, and an invitation to carry that work into deeper study.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":3
    ]));
    addPrerequisite("/guilds/monk/discipline/steady-practice.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "granted");
    addSpecification("teacher required", 1);
}
