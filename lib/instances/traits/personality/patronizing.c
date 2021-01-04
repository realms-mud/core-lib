//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "patronizing");
        addSpecification("description", "You appear to be kind and helpful "
            "but tend to betray that you have a rather condescending sense "
            "of superiority toward others.");
        addSpecification("root", "patronizing");
        addSpecification("opinion", -10);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
