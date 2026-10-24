//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Brace the Spirit");
    addSpecification("source", "monk");
    addSpecification("description",
        "While warded, spend chi for twelve seconds of braced defense. The "
        "brief posture grants three defense and does not absorb damage "
        "itself.");

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
        "value":22
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
    addPrerequisite("/guilds/monk/mana-shield/refuge-theory.c", ([
        "type":"research"
    ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 3);
    addSpecification("teacher required", 1);

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 40);

    addSpecification("duration", 12);

    addSpecification("bonus defense", 3);

    addSpecification("command template", "chi brace the spirit");
    addSpecification("use ability message",
        "##InitiatorName## brace##InitiatorReflexive## beneath the ward.");

    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/economical-refuge.c":1
    ]));

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/defensive-timing.c":6
    ]));
}
