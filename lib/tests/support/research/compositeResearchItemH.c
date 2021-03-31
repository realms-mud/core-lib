//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        persistedActiveResearchItem::reset(arg);
        addSpecification("name", "Drum Attack!");
        addSpecification("scope", "self");
        addSpecification("research type", "granted");
        addSpecification("composite research",
            "lib/tests/support/research/compositeRoot.c");
        addSpecification("composite type", "instrumental rhythm");
        addSpecification("composite class", "percussion");
        addSpecification("default composite description",
            "Drum-thumping for fun.");

        addSpecification("limited by", ([
            "equipment":({ "instrument: percussion" }),
        ]));

        addSpecification("bonus sonic attack", 15);
        addSpecification("duration", 4);
        addSpecification("use composite message", "##InitiatorName## ##Infinitive::drum##, '##CompositeSegment##'");
    }
}
