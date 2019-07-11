//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "professional");
        addSpecification("name", "apprentice engineer");
        addSpecification("description", "You have just begun learning about engineering");
        addSpecification("root", "engineer");
        addSpecification("opinion", 1);
        addSpecification("bonus engineering", 2);
        addSpecification("bonus mathematics", 1);
        addSpecification("bonus physics", 1);
        "baseTrait"::reset(arg);
    }
}
