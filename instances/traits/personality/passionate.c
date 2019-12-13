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
        addSpecification("name", "passionate");
        addSpecification("description", "You look upon everything you do with "
            "a great deal of zeal.");
        addSpecification("root", "passionate");
        addSpecification("opinion", 5);
        addSpecification("bonus persuasion", 1);
        "baseTrait"::reset(arg);
    }
}
