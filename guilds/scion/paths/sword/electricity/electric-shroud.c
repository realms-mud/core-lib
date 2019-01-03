//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        sustainedResearchItem::reset(arg);
        addSpecification("name", "Electric Shroud");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the electric shroud technique. By means of this, the "
            "Scion is able to emit a constant electrical current from their "
            "sword that encapsulates them in a protective barrier. Doing so "
            "is very taxing and will decrease hit points, spell points, and "
            "stamina.");

        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("lib/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/electricity/root.c",
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 23
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/static-shield.c",
                "name" : "static shield",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/electricity/plasma-shield.c",
                "name" : "plasma shield",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
        }));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 60);
        addSpecification("hit point cost", 100);
        addSpecification("spell point cost", 100);
        addSpecification("stamina point cost", 100);
        addSpecification("command template", "electric shroud");
        addSpecification("bonus resist electricity", 50);
        addSpecification("bonus resist physical", 25);
        addSpecification("apply damage reflection", 1);

        addSpecification("use ability activate message", "A shroud of scintillating "
            "electrical energy wraps around ##InitiatorName##.");
        addSpecification("use ability deactivate message", "The shroud of electrical "
            "energy around ##InitiatorName## subsides.");
    }
}
