//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shelter of Intent");
    addSpecification("source", "monk");
    addSpecification("description",
        "While warded, spend chi to prepare twenty seconds of fire, cold, "
        "and electricity resistance. These resistances are ordinary "
        "defenses, not an extra shield.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
    ]));

    addPrerequisite("monk", ([
        "type":"guild",
        "value":({ "monk" })
    ]));
    addPrerequisite("level", ([
        "type":"level",
        "guild":"monk",
        "value":66
    ]));
    addPrerequisite("rank", ([
        "type":"guild rank",
        "guild":"monk",
        "value":({
            "master candidate",
            "master"
        })
    ]));
    addPrerequisite("/guilds/monk/discipline/teachers-recognition.c", ([
        "type":"research"
    ]));
    addPrerequisite("/guilds/monk/mana-shield/lucid-refuge.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 4);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 70);

    addSpecification("duration", 20);

    addSpecification("bonus resist fire", 3);
    addSpecification("bonus resist cold", 3);
    addSpecification("bonus resist electricity", 3);

    addSpecification("command template", "chi shelter of intent");
    addSpecification("use ability message",
        "##InitiatorName## gather##InitiatorReflexive## a shelter of intent "
        "against the elements.");

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/seamless-recovery.c":8
    ]));
}
