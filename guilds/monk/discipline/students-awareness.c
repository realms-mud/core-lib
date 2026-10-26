//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Student's Awareness");
    addSpecification("source", "monk");
    addSpecification("description",
        "Watch the practice hall before stepping into "
        "its motion. Footfalls, breathing, and the "
        "space between students reveal lessons a hurried eye would miss.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":20
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/disciplined-breath.c", ([
        "type":"research"
    ]));

    addSpecification("scope", "self");

    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("bonus perception", 2);
}
