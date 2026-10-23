//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":15
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "disciple", "adept", "senior disciple",
            "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/students-awareness.c",
        ([ "type":"research" ]));
    addSpecification("name", "Disciple's Insight");
    addSpecification("source", "monk");
    addSpecification("description", "You recognize small shifts in balance "
        "and intent, improving your ability to dodge an incoming attack.");
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 2);
}
