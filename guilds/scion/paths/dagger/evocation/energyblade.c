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
        addSpecification("name", "Energy Blade");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "");

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addPrerequisite("lib/guilds/scion/paths/dagger/root.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/dagger/evocation/root.c",
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/evocation/sweeping-blast.c",
                "name" : "sweeping flames",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/evocation/energy-brand.c",
                "name" : "energy brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/evocation/scintillating-blade.c",
                "name" : "scintilating blade",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/evocation/magical-edge.c",
                "name" : "magical edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": "lib/guilds/scion/paths/dagger/evocation/dhurass-pommel.c",
                "name" : "Dhuras's Pommel",
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
        addSpecification("command template", "energy blade");
        addSpecification("bonus energy enchantment", 3);
        addSpecification("bonus resist energy", 3);

        addSpecification("use ability activate message", "Thin wisps of pulsating "
            "energy wrap around ##InitiatorPossessive::Name## dagger.");
        addSpecification("use ability deactivate message", "Thin wisps of pulsating "
            "energy around ##InitiatorPossessive::Name## dagger fade away.");
    }
}
