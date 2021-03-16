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
        addSpecification("name", "Lyric verse thingy");
        addSpecification("source", "blarg");
        addSpecification("composite research",
            "lib/tests/support/research/compositeRoot.c");
        addSpecification("default composite description",
            "I'm a lyric verse thingy woman!");
        addSpecification("composite type", "lyric");
        addSpecification("description", "This is limited active research");
        addSpecification("usage summary", "This lyrically blargifies stuff.");
        addSpecification("scope", "area");
        addSpecification("research type", "granted");
        addSpecification("research cost", 1);

        addSpecification("bonus strength", 2);
        addSpecification("duration", 30);
        addSpecification("event handler", "usedResearchEvent");
        addSpecification("use composite message", "##InitiatorName## ##Infinitive::drone## on, '##CompositeSegment##'");
    }
}
