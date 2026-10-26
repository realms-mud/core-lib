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
        "Spread your hands and lay a calm intention over the shield. "
        "Flame gutters, frost loosens, and the storm's bright fingers "
        "slide across a surface as serene as an undisturbed pond.");

    addSpecification("limited by", ([
        "research active":({ "/guilds/monk/mana-shield/mindful-ward.c" })
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

    addSpecification("bonus resist fire", 15);
    addSpecification("bonus resist cold", 15);
    addSpecification("bonus resist electricity", 15);

    addSpecification("command template", "chi shelter of intent");
    addSpecification("use ability message",
        "##InitiatorName## gather##InitiatorReflexive## a shelter of intent "
        "against the elements.");

    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/seamless-recovery.c":8
    ]));
}
