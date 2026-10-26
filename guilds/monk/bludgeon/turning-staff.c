//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Turning Staff");
    addSpecification("source", "monk");
    addSpecification("description",
        "Keep the staff turning in patient circles before "
        "the body. An approaching weapon meets a length "
        "of wood already traveling to greet it.");

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
        "value":14
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "student",
        "disciple",
        "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/sweeping-arc.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");

    addSpecification("bonus parry", 2);

    addSpecification("stamina point cost", 8);

    addSpecification("per hit received cost", ([
        "stamina points":1
    ]));

    addSpecification("cooldown", 12);

    addSpecification("command template", "kata turning staff");
    addSpecification("use ability activate message",
        "##InitiatorName## begin##InitiatorReflexive## a turning staff guard.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## lower##InitiatorReflexive## the turning staff "
        "guard.");
}
