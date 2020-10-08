//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "talkative");
        addSpecification("description", "You can easily catch and hold the "
            "attention of those around you. Unfortunately, you tend to "
            "ramble on long after your audience has lost interest in what "
            "you have to say.");
        addSpecification("root", "interesting");
        addSpecification("opinion", -5);
        addSpecification("bonus bluff", 1);
        "baseTrait"::reset(arg);
    }
}
