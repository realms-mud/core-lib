//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Empty Hand Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "The master erases the names of the forms from the practice slate. "
        "Palm, heel, and elbow are no longer separate answers, but ways "
        "for an unburdened body to speak the same intention.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":60
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/unarmed/empty-hand.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("related research",
        ({ "/guilds/monk/unarmed/empty-hand.c",
            "/guilds/monk/unarmed/measured-palm.c",
            "/guilds/monk/unarmed/driving-elbow.c",
            "/guilds/monk/unarmed/hammer-fist.c",
            "/guilds/monk/unarmed/rising-heel.c",
            "/guilds/monk/unarmed/crushing-embrace.c",
            "/guilds/monk/unarmed/sapping-palm.c",
            "/guilds/monk/unarmed/meridian-strike.c" }));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Empty Hand":3,
        "Measured Palm":3,
        "Driving Elbow":3,
        "Hammer Fist":3,
        "Rising Heel":2,
        "Crushing Embrace":2,
        "Sapping Palm":1,
        "Meridian Strike":1
    ]));
}
