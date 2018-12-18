//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Ionization");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the ionization technique. This form enhances "
            "the Scion's offensive spells.");

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 19 ]));
        addPrerequisite("lib/guilds/scion/paths/dagger/electricity/electrostatic-induction.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Lightning": 5,
            "Lightning Blast": 5,
            "Maelstrom": 5,
            "Plasma Ball": 10
        ]));
    }
}
