//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Weighted Rhythm");
    addSpecification("source", "monk");
    addSpecification("description",
        "Give the mace a measured rhythm of approach and "
        "return. Its heavy head marks the beat while "
        "your stance follows with the patience of a slow drum.");

    addSpecification("limited by", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":20
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({         "disciple",
        "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/compact-blow.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");

    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);

    addSpecification("stamina point cost", 10);

    addSpecification("per hit landed cost", ([
        "stamina points":1
    ]));

    addSpecification("cooldown", 12);

    addSpecification("command template", "kata weighted rhythm");
    addSpecification("use ability activate message",
        "##InitiatorName## adopt##InitiatorReflexive## a weighted mace "
        "rhythm.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## release##InitiatorReflexive## the weighted rhythm.");
}
