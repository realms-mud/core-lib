//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "cataracts");
        addSpecification("description", "You have cataracts clouding your eyes and are quite blind.");
        addSpecification("root", "blind");
        addSpecification("opinion", -1);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}