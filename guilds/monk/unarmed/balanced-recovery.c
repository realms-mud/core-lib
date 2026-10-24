//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Balanced Recovery");
    addSpecification("source", "monk");
    addSpecification("description",
        "Instruction in recovering your balance after a committed palm "
        "strike grants +1 dodge while both wielded slots are empty. Requires "
        "ten successful Measured Palm executions against already-hostile, "
        "non-allied NPCs at least half your effective level. Repeated uses "
        "in one encounter count.");

    addSpecification("limited by", ([
        "empty equipment slots":({ "wielded primary", "wielded offhand" })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":2
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "initiate",
            "student",
            "disciple",
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/unarmed/measured-palm.c", ([
        "type":"research"
    ]));
    addPrerequisite("measured palm practice", ([
        "type":"observation",
        "criteria":([
            "type":"combat.kata",
            "research":"/guilds/monk/unarmed/measured-palm.c",
            "qualifying opponent":1
        ]),
        "value":10
    ]));

    addSpecification("scope", "self");

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("bonus dodge", 1);
}
