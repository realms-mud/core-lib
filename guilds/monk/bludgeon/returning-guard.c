//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Returning Guard");
    addSpecification("source", "monk");
    addSpecification("description",
        "Let every stroke return through a compact shelter "
        "before it begins again. The recovering haft waits "
        "across the opening your foe hoped to exploit.");

    addSpecification("limited by", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":32
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "adept", "senior disciple", "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/bludgeon/recovery-economy.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");

    addSpecification("bonus parry", 1);
    addSpecification("bonus defense", 1);

    addSpecification("stamina point cost", 8);

    addSpecification("per hit received cost", ([
        "stamina points":1
    ]));

    addSpecification("cooldown", 10);

    addSpecification("command template", "kata returning guard");
    addSpecification("use ability activate message",
        "##InitiatorName## settle##InitiatorReflexive## into a returning "
        "guard.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## relax##InitiatorReflexive## the returning guard.");
}
