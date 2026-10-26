//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Essence Weaving");
    addSpecification("source", "monk");
    addSpecification("description",
        "Lay one thread of intent beside another without tangling their "
        "courses. Through patient repetition, the separate strands "
        "become a living pattern beneath your hands.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":19
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
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/essence-sensitivity.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/concentrated-channel.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("bonus spellcraft", 2);
}
