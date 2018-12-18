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
        addSpecification("name", "Static Barrier");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the static barrier technique. This form enhances "
            "the Scion's defense degradation spells.");

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 11 ]));
        addPrerequisite("lib/guilds/scion/paths/dagger/electricity/shocking-tendrils.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Shocking Tendrils": 2,
            "Shocking Barrier": 2,
            "Tempest": 2
        ]));
    }
}
