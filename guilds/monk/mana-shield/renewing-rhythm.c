//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Renewing Rhythm");
    addSpecification("source", "monk");
    addSpecification("description",
        "Hear the returning cadence beneath the clash of battle. Each "
        "tremor of the shield marks another chance to gather yourself, "
        "until renewal becomes part of the dance rather than a retreat.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":38
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "adept",
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/defensive-timing.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/measured-renewal.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Ward Mending":4,
        "Measured Renewal":6
    ]));
}
