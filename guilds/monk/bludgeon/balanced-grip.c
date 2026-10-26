//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Balanced Grip");
    addSpecification("source", "monk");
    addSpecification("description",
        "Let the staff rest between the hands like a balance beam. "
        "Neither end is idle; the smallest shift of pressure "
        "awakens the length beyond your fingers.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"staff",
            "blueprint":({ "staff", "quarterstaff" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":6
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/staff-fulcrum.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");

    addSpecification("bonus staff", 2);
}
