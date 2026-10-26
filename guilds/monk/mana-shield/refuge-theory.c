//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Refuge Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "A true refuge is shaped around those it shelters. Studying the "
        "shield's response to your own movements teaches you to lay its "
        "threads in harmony with bone, breath, and intention.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":20
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
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
    addPrerequisite("/guilds/monk/mana-shield/sentry-focus.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Mana Shield":3,
        "Ward Mending":1,
        "Breath Conversion":1,
        "Measured Renewal":2,
        "Vigilant Renewal":3,
        "Deflecting Palm":3,
        "Interrupting Thread":2,
        "Ward Counterpulse":2,
        "Sheltering Touch":2,
        "Stillpoint Rebuke":3
    ]));

    addSpecification("related research", ({
        "/guilds/monk/mana-shield/brace-the-spirit.c",
        "/guilds/monk/mana-shield/refuge-posture.c"
    }));
}
