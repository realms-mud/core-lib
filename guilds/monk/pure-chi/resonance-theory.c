//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Resonance Theory");
    addSpecification("source", "monk");
    addSpecification("description",
        "The body and its current do not always sing the same note. "
        "Learn to hear their subtle harmonies and discord, following "
        "the places where a touch can quiet or unsettle the whole.");

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":45
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "senior disciple",
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/pure-chi/driving-wave.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([
        "Focused Pulse":2,
        "Needle of Chi":2,
        "Driving Wave":3,
        "Restorative Chi Breath":1,
        "Returning Current":1,
        "Heart Mending":2,
        "Piercing Intent":3,
        "Centered Release":3,
        "Renewal of Self":2,
        "Severing Current":3,
        "Silent Thunder":3
    ]));

    addSpecification("related research", ({
        "/guilds/monk/pure-chi/piercing-intent.c",
        "/guilds/monk/pure-chi/centered-release.c"
    }));
}
