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
        addSpecification("type", "persona");
        addSpecification("name", "aegis guardsman");
        addSpecification("description", "You are a member of the Aegis Guard.");
        addSpecification("root", "fighter persona");
        "baseTrait"::reset(arg);
    }
}
