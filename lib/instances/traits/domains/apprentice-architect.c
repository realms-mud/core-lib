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
        addSpecification("type", "professional");
        addSpecification("name", "apprentice architect");
        addSpecification("description", "You have just begun learning about architecture");
        addSpecification("root", "architect");
        addSpecification("opinion", 1);
        addSpecification("bonus engineering", 2);
        addSpecification("bonus mathematics", 1);
        addSpecification("bonus physics", 1);
        "baseTrait"::reset(arg);
    }
}
