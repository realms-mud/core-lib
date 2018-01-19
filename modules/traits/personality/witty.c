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
        addSpecification("name", "witty");
        addSpecification("description", "You have a way with words - a sharp tongue and a quick wit.");
        addSpecification("root", "eloquent");
        addSpecification("opposing root", "vulgar");
        addSpecification("opinion", 10);
        "baseTrait"::reset(arg);
    }
}

