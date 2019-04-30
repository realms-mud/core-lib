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
        addSpecification("name", "lewd");
        addSpecification("description", "You tend to express your thoughts "
            "in a rather crude and sexually-offensive manner.");
        addSpecification("root", "crude");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -20);
        addSpecification("penalty to etiquette", 1);
        "baseTrait"::reset(arg);
    }
}
