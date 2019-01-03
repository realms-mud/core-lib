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
        addSpecification("name", "Phantasmal Blade");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "");

        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("lib/guilds/scion/paths/sword/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/spirit/root.c",
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/spirit/sweeping-mist.c",
                "name" : "sweeping mist",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/spirit/phantasmal-brand.c",
                "name" : "phantasmal brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/spirit/spirit-blade.c",
                "name" : "spirit blade",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/spirit/spirit-edge.c",
                "name" : "spirit edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/sword/spirit/nienwyns-pommel.c",
                "name" : "Nienwyn's Pommel",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
        }));
        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("cooldown", 4);
        addSpecification("spell point cost", 10);
        addSpecification("stamina point cost", 50);
        addSpecification("command template", "phantasmal blade");
        addSpecification("bonus magical enchantment", 3);
        addSpecification("bonus resist magical", 3);

        addSpecification("use ability activate message", "Thin wisps of pulsating "
            "mist wrap around ##InitiatorPossessive::Name## sword.");
        addSpecification("use ability deactivate message", "Thin wisps of pulsating "
            "mist around ##InitiatorPossessive::Name## sword fade away.");
    }
}
