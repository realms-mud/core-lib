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
        addSpecification("type", "personality");
        addSpecification("name", "dreaded");
        addSpecification("description", "People regard you with a great "
            "deal of apprehension and fear.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "kind");
        addSpecification("penalty to charisma", 1);
        addSpecification("opinion", -15);
        addSpecification("opposing opinion", -15);
        "baseTrait"::reset(arg);
    }
}
