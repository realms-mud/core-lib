//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cleansing Breath");
    addSpecification("source", "monk");
    addSpecification("description",
        "Draw a clean breath deep into the belly and send it through "
        "clouded blood. The bitter fog of indulgence lifts with the "
        "exhalation, leaving the senses clear and wakeful.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":15
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
    addPrerequisite("/guilds/monk/pure-chi/circulation-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 40);

    addSpecification("command template", "chi cleansing breath");
    addSpecification("use ability message",
        "##InitiatorName## exhale##InitiatorReflexive## a cleansing breath.");

    addSpecification("decrease intoxication", ({
        ([
            "probability":100,
            "base damage":8,
            "range":2
        ])
    }));
    addSpecification("decrease druggedness", ({
        ([
            "probability":100,
            "base damage":8,
            "range":2
        ])
    }));
}
