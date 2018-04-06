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
        addSpecification("type", "personality");
        addSpecification("name", "awkward");
        addSpecification("description", "You have a lack of social grace.");
        addSpecification("root", "awkward");
        addSpecification("opinion", -1);
        "baseTrait"::reset(arg);
    }
}
