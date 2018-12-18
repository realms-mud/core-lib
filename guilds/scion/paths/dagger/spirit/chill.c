//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "chill");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This is limited active research");

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addPrerequisite("lib/guilds/scion/paths/dagger/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/dagger/spirit/root.c",
            (["type":"research"]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 10);

        addSpecification("damage hit points", ({ ([
                "probability":80,
                "base damage" : 5,
                "range" : 5
            ]),
            ([
                "probability":20,
                "base damage" : 10,
                "range" : 10
            ])
        }));
        addSpecification("damage type", "magical");
        addSpecification("modifiers", ({ 
            ([
                "type":"skill",
                "name" : "dagger",
                "formula" : "additive",
                "rate" : 1.05
            ]),
            ([
                "type":"skill",
                "name" : "spirit",
                "formula" : "additive",
                "rate" : 1.10
            ]),
            ([
                "type":"attribute",
                "name" : "intelligence",
                "formula" : "additive",
                "rate" : 1.05
            ]) 
        }));

        addSpecification("cooldown", 4);
        addSpecification("event handler", "chillEvent");
        addSpecification("command template", "chill [at ##Target##]");
        addSpecification("use ability message",  "A chill fog "
            "flies from ##InitiatorPossessive::Name## dagger enveloping ##TargetName##.");
    }
}
