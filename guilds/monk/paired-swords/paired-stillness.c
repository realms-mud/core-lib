//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Paired Stillness");
    addSpecification("source", "monk");
    addSpecification("description",
        "Hold the unequal blades in a silence neither must "
        "break first. In the master's patient guard, their "
        "separate paths have become a shared understanding.");

    addSpecification("limited by", ([
        "equipment":({
            ([
                "blueprint":"katana",
                "slot":"wielded primary"
            ]),
            ([
                "blueprint":"wakisashi",
                "slot":"wielded offhand"
            ])
        })
    ]));

    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":66
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({ "master candidate", "master" })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/paired-swords/paired-mastery.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 4);

    addSpecification("command template", "kata paired stillness");

    addSpecification("bonus hand and a half sword", 6);
    addSpecification("bonus short sword", 6);
    addSpecification("penalty to attack", 2);
}
