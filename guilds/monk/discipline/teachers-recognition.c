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
        "Your first instructor acknowledges your completed lessons and "
        "recommends you for advanced instruction. This recognition opens "
        "further teaching; it is not a mastery trial.");

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
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
