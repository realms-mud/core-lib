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
        addSpecification("name", "master engineer");
        addSpecification("description", "You are a master engineer");
        addSpecification("root", "engineer");
        addSpecification("opinion", 5);
        addSpecification("bonus engineering", 25);
        addSpecification("bonus mathematics", 20);
        addSpecification("bonus physics", 20);

        "baseTrait"::reset(arg);
    }
}
