//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unbroken Cadence");
    addSpecification("source", "monk");
    addSpecification("description",
        "Maintain an economical offensive cadence for one attack and one "
        "damage. Reserve eighteen stamina; each landed hit costs one "
        "stamina. Uses any primary bludgeon.");

    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":70
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/momentum-mastery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");

    addSpecification("bonus attack", 1);
    addSpecification("bonus damage", 1);

    addSpecification("stamina point cost", 18);

    addSpecification("per hit landed cost", ([
        "stamina points":1
    ]));

    addSpecification("cooldown", 20);

    addSpecification("command template", "kata unbroken cadence");
    addSpecification("use ability activate message",
        "##InitiatorName## establish##InitiatorReflexive## an unbroken "
        "cadence.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## release##InitiatorReflexive## the unbroken "
        "cadence.");
}
